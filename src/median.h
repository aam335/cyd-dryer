#include <Arduino.h>
typedef struct {
    int med_ptr,size;
    float *values;
    float *sorted_values;
} median_t;

median_t *median_init(int size);
void median_add(median_t *m, float temperature);
float median_value(median_t *m);
float median_value_qsort(median_t *m);