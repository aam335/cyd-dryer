#include <Arduino.h>

#include <esp32_smartdisplay.h>
#include <ui/ui.h>
#include "Preferences.h"

#include "dryer.h"

#define SDA_2 GPIO_NUM_21
#define SCL_2 GPIO_NUM_22

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
    smartdisplay_lcd_set_backlight(0);

#ifdef BOARD_HAS_CDS
    // smartdisplay_lcd_set_brightness_cb(smartdisplay_lcd_adaptive_brightness_cds, 100); // todo limit min value
#endif
    __attribute__((unused)) auto disp = lv_disp_get_default();
    // lv_disp_clean_dcach  e(disp);

    lv_disp_set_rotation(disp, LV_DISP_ROT_90);
    // lv_disp_set_rotation(disp, LV_DISP_ROT_180);
    // lv_disp_set_rotation(disp, LV_DISP_ROT_270);
    load_config();
    config_t *c = get_config();
    ntc_init(THERMISTOR_PIN, c->r25, c->r_div, c->beta);
    ui_init();
    init_values();
    gpio_init_pwm_pins();

    smartdisplay_lcd_set_backlight(1.f);

    Timer0_Cfg = timerBegin(0, 80, true);
    timerAttachInterrupt(Timer0_Cfg, &Timer0_ISR, true);
    timerAlarmWrite(Timer0_Cfg, 1000, true);
    timerAlarmEnable(Timer0_Cfg);
}

crDef(poll_esm2);
crDef(poll_sensors);
crDef(poll_rgbled);
crDef(poll_status);
crDef(poll_notify);

void loop()
{
    system_millis = millis();

    crPoll(poll_sensors);
    crPoll(poll_esm2);
    crPoll(poll_status);
    crPoll(poll_notify);
#ifdef BOARD_HAS_RGB_LED
    crPoll(poll_rgbled);
#endif
    lv_timer_handler();
}

uint32_t poll_esm2()
{
    float tc = get_median_temp();
    apply_temperature(tc, ERRORED_SENSOR);
    poll_esm();
    return ESM_POLL_INTERVAL;
}

uint32_t poll_status()
{
    if (current_temperature == ERRORED_SENSOR)
    {
        apply_emergency_stop();
        esm_status = STATUS_SENSOR_ERROR;
    }
    show_text_status();
    check_and_update_timer(0);
    // show_pid_status();
    return STATUS_POLL_INTERVAL;
}
int ht_read_error_count = 0;
#include <driver/adc.h>
uint32_t poll_sensors()
{
    float t_celsius = ntc_read();

    if (t_celsius < 0 || t_celsius > 120)
    {
        if (ht_read_error_count < MAX_SENSOR_CONTINUOS_ERRORS)
        {
            ht_read_error_count++;
            return SENSORS_POLL_INTERVAL;
        }
        set_failure(FAIL_SENSOR);
    }

    // apply_temperature(t_celsius, ERRORED_SENSOR);

    return SENSORS_POLL_INTERVAL;
}

int green_led = 0;
uint32_t poll_rgbled()
{
    // auto const rgb = (system_millis / 2000) % 8;
    // smartdisplay_led_set_rgb(rgb & 0x01, rgb & 0x02, rgb & 0x04);
    digitalWrite(RGB_LED_G, green_led++ & 1);

    return LED_POLL_INTERVAL;
}
uint32_t poll_notify()
{
    show_notify_on_failure();
    return NOTIFY_POLL_INTERVAL;
}
#ifdef __cplusplus
extern "C"
{
#endif
    void load_data(void *config, size_t size, const char *name)
    {
        memset(config, 0, sizeof(config_t));
        Preferences preferences;
        if (!preferences.begin(name, true))
        {
            log_i("fail");
            return;
        }
        size_t newsize = preferences.getBytes(name, config, size);
        if (newsize != size)
        {
            memset(config, 0, sizeof(config_t));
        }
        preferences.end();
    }

    void save_data(void *config, size_t size, const char *name)
    {
        Preferences preferences;
        preferences.begin(name, false);
        preferences.putBytes(name, config, size);
        preferences.end();
    }
#ifdef __cplusplus
}
#endif