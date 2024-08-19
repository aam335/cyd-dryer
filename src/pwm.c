#include "dryer.h"

typedef struct bresenham_t
{
  uint16_t size;
  uint16_t value;
  int16_t error;
  uint16_t stepNumber;
} bresenham_t;

void bresenham_init(struct bresenham_t *st, uint16_t size)
{
  st->size = size;
}

void bresenham_setValue(struct bresenham_t *st, uint16_t val)
{
  st->stepNumber = 0;
  st->value = val;
  st->error = st->size / 2;
}

bool bresenham_getNext(struct bresenham_t *st)
{
  bool result;
  st->error -= st->value;
  if (st->error < 0)
  {
    st->error += st->size;
    result = true;
  }
  else
  {
    result = false;
  }
  if (++st->stepNumber >= st->size)
  {
    st->stepNumber = 0;
    st->error = st->size / 2;
  }
  return result;
}

typedef struct pwm
{
  bresenham_t bs;
  int8_t pin, pin2;
  bool inverse_pin, inverse_pin2;
  uint16_t new_value;
  bool flag_update;
} pwm_t;

static pwm_t pwms[] = {
    {.pin = HEATER_PIN, .inverse_pin = false, .new_value = 0, .flag_update = true, .bs.size = PWM_FULL_CYCLE, .pin2 = RGB_LED_R, .inverse_pin2 = true},
    {.pin = FAN_PIN, .inverse_pin = false, .new_value = 0, .flag_update = true, .bs.size = PWM_FULL_CYCLE, .pin2 = RGB_LED_B, .inverse_pin2 = true},
};

int current_count = 0;

inline int pin_value(bool v, bool inverted)
{
  return inverted ? !v : v;
}

void millis_handler_irq()
{
  if (current_count > 0)
  {
    current_count--;
    return;
  }
  current_count = PWM_PERIOD;

  for (int i = 0; i < PWM_COUNT; i++)
  {
    pwm_t *p = &pwms[i];
    if (p->flag_update)
    {
      bresenham_setValue(&p->bs, p->new_value);
      p->flag_update = false;
    }
    bool v = bresenham_getNext(&p->bs);

    digitalWrite(p->pin, pin_value(p->inverse_pin, v));
    if (p->pin2 >= 0)
      digitalWrite(p->pin2, pin_value(p->inverse_pin2, v));
  }
}

void gpio_init_pwm_pins()
{
  for (int i = 0; i < PWM_COUNT; i++)
  {
    pwm_t *p = &pwms[i];
    pinMode(p->pin, OUTPUT);
  }
}

void set_pwm(int i, int value)
{
  if (i >= PWM_COUNT)
  {
    return;
  }
  pwm_t *p = &pwms[i];
  p->new_value = value;
  p->flag_update = true;
}

int get_pwm(int i)
{
  return pwms[i].new_value * 100 / (PWM_FULL_CYCLE);
}