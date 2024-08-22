#include <Arduino.h>
#define MEADIAN_ELEMENT uint16_t
#define MEDIAN_SUM uint32_t
typedef struct {
    int med_ptr,size;
    MEADIAN_ELEMENT *values;
    MEADIAN_ELEMENT *sorted_values;
} median_t;

median_t *median_init(int size);
void median_add(median_t *m, MEADIAN_ELEMENT adc_value);
MEADIAN_ELEMENT median_value(median_t *m);
// float median_value_qsort(median_t *m);