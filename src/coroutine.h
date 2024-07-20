#pragma once
#include <stdint.h>
#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)
#define APPEND(x, y) x##y
// coRoutines
#define crBegin          \
    switch (crStaticVar) \
    {                    \
    case 0:
#define crReturn(x)             \
    do                          \
    {                           \
        crStaticVar = __LINE__; \
        return x;               \
    case __LINE__:;             \
    } while (0)
#define crFinish }

#define crDef(NAME)  \
    uint32_t NAME(); \
    uint32_t APPEND(NAME, _last) = 0, APPEND(NAME, _next) = 0;
#define crPoll(NAME)                                                   \
    do                                                                 \
    {                                                                  \
        if (system_millis - APPEND(NAME, _last) > APPEND(NAME, _next)) \
        {                                                              \
            APPEND(NAME, _next) = NAME();                              \
            APPEND(NAME, _last) = system_millis;                       \
        }                                                              \
    } while (0)

    