#include "median.h"

median_t *median_init(int size)
{
    median_t *m = (median_t *)calloc(sizeof(median_t), 1);
    m->values = calloc(sizeof(m->values[0]), size);
    m->sorted_values = calloc(sizeof(m->values[0]), size);
    m->med_ptr = -1;
    m->size = size;
    return m;
}

void median_free(median_t *m)
{
    free(m->values);
    free(m->sorted_values);
    free(m);
}

#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)
void median_add(median_t *m, MEADIAN_ELEMENT adc)
{
    if (m->med_ptr < 0)
    {
        for (int i = 0; i < m->size; i++)
        {
            m->values[i] = adc;
        }
        m->med_ptr = 0;
        return;
    }
    // calc median
    m->med_ptr = (m->med_ptr + 1) % m->size;
    m->values[m->med_ptr] = adc;
}

MEADIAN_ELEMENT median_value(median_t *m)
{
    MEADIAN_ELEMENT tmin = m->values[0], tmax = m->values[0];
    MEDIAN_SUM tsum = 0;
    for (int i = 0; i < m->size; i++)
    {
        float t = m->values[i];
        tmax = MAX(tmax, t);
        tmin = MIN(tmin, t);
        tsum += t;
    }
    MEADIAN_ELEMENT adc_mid = (tsum - tmin - tmax) / (m->size - 2);

    return adc_mid;
}

// int compare_floats(const void *a, const void *b)
// {
//     int arg1 = *(const float *)a;
//     int arg2 = *(const float *)b;

//     if (arg1 < arg2)
//         return -1;
//     if (arg1 > arg2)
//         return 1;
//     return 0;
// }

// float median_value_qsort(median_t *m)
// {
//     memcpy(m->sorted_values, m->values, sizeof(float) * m->size);
//     qsort(m->sorted_values, m->size, sizeof(float), compare_floats);
//     int skip = m->size / 10 + 1;
//     float sum = 0;
//     for (int i = skip; i < m->size - skip; i++)
//         sum += m->sorted_values[i];
//     return sum / (m->size - skip * 2);
// }