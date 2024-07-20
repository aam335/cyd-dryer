#include <Arduino.h>

#include <esp32_smartdisplay.h>
#include <ui/ui.h>
#include "SHTSensor.h"
#include <Wire.h>

#include "dryer.h"

#define SDA_2 GPIO_NUM_21
#define SCL_2 GPIO_NUM_22

SHTSensor sht;
hw_timer_t *Timer0_Cfg = NULL;

void IRAM_ATTR Timer0_ISR()
{
    millis_handler_irq();
}

void setup()
{
#ifdef ARDUINO_USB_CDC_ON_BOOT
    delay(5000);
#endif
    Serial.begin(115200);
    Serial.setDebugOutput(true);
    log_i("Board: %s", BOARD_NAME);
    log_i("CPU: %s rev%d, CPU Freq: %d Mhz, %d core(s)", ESP.getChipModel(), ESP.getChipRevision(), getCpuFrequencyMhz(), ESP.getChipCores());
    log_i("Free heap: %d bytes", ESP.getFreeHeap());
    log_i("Free PSRAM: %d bytes", ESP.getPsramSize());
    log_i("SDK version: %s", ESP.getSdkVersion());

    smartdisplay_init();
#ifdef BOARD_HAS_CDS
    smartdisplay_lcd_set_brightness_cb(smartdisplay_lcd_adaptive_brightness_cds, 100); // todo limit min value
#endif
    __attribute__((unused)) auto disp = lv_disp_get_default();
    lv_disp_set_rotation(disp, LV_DISP_ROT_90);
    // lv_disp_set_rotation(disp, LV_DISP_ROT_180);
    // lv_disp_set_rotation(disp, LV_DISP_ROT_270);

    if (!Wire1.begin(SDA_2, SCL_2, 100000))
    {
        log_i("i2c failed: %d %d ok", SDA_2, SCL_2);
    }

    int nDevices = 0;
    for (int address = 8; address < 127; address++)
    {
        Wire1.beginTransmission(address);
        uint8_t error = Wire1.endTransmission();

        if (error == 0)
        {
            log_i("I2C device found at address 0x%x", address);

            nDevices++;
        }
        else if (error == 4)
        {
            if (address < 16)
                address = 0;
            log_i("Unknow error at address 0x%x", address);
        }
    }
    if (nDevices == 0)
        log_i("No I2C devices found");

    log_i("sht init(): %s", sht.init(Wire1) ? "ok" : "fail");

    sht.setAccuracy(SHTSensor::SHT_ACCURACY_MEDIUM);

    ui_init();
    init_values();
    gpio_init_pwm_pins();

    Timer0_Cfg = timerBegin(0, 80, true);
    timerAttachInterrupt(Timer0_Cfg, &Timer0_ISR, true);
    timerAlarmWrite(Timer0_Cfg, 1000, true);
    timerAlarmEnable(Timer0_Cfg);
}

crDef(poll_esm);
crDef(poll_sensors);
crDef(poll_rgbled);

void loop()
{
    system_millis = millis();

    crPoll(poll_sensors);
    crPoll(poll_esm);
#ifdef BOARD_HAS_RGB_LED
    crPoll(poll_rgbled);
#endif
    lv_timer_handler();
}

uint32_t poll_sensors()
{
    float aTemperature = ERRORED_SENSOR, aHumidity = ERRORED_SENSOR;

    if (sht.readSample())
    {
        aTemperature = sht.getTemperature();
        aHumidity = sht.getHumidity();
    }
    apply_sensor_ht(aTemperature, aHumidity);

    return SENSORS_POLL_INTERVAL;
}

uint32_t poll_rgbled()
{
    auto const rgb = (system_millis / 2000) % 8;
    smartdisplay_led_set_rgb(rgb & 0x01, rgb & 0x02, rgb & 0x04);

    return SENSORS_POLL_INTERVAL;
}