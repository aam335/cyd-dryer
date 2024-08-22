enum
{
    PWM_FAN,
    PWM_HEATER,
    PWM_COUNT,
};

// software pwm 50Hz // 20 ms
#define PWM_INTERVAL 1000
#define PWM_PERIOD 20 // ms
#define PWM_FULL_CYCLE (PWM_INTERVAL / PWM_PERIOD)

#ifdef __cplusplus
extern "C"
{
#endif
void gpio_init_pwm_pins();
void millis_handler_irq();
void set_pwm(int i, int value);
void set_pwm_percents(int i, int value);
int get_pwm(int i);
#ifdef __cplusplus
} /*extern "C"*/
#endif