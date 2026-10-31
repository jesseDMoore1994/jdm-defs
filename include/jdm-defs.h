#ifndef JDM_DEFS_H
#define JDM_DEFS_H
#include <stddef.h>
#include <stdint.h>

// Macro to mark a variable as unused to avoid compiler warnings
#define UNUSED(x) (void)(x)

// Common data types
#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t
#define u64 uint64_t
#define s8 int8_t
#define s16 int16_t
#define s32 int32_t
#define s64 int64_t
#define f32 float
#define f64 double
#define b8 u8
#define b16 u16
#define b32 u32
#define b64 u64
#define pointer void*

#define JDM_TRUE 1
#define JDM_FALSE 0
#define JDM_NULL NULL

// Define function like macros for common utilities
#define JDM_MIN(a, b) ((a) < (b) ? (a) : (b))
#define JDM_MAX(a, b) ((a) > (b) ? (a) : (b))
#define JDM_CLAMP(x, min, max) (JDM_MIN(JDM_MAX((x), (min)), (max)))
#define JDM_ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define JDM_ALIGN_UP(x, align) (((x) + ((align) - 1)) & ~((align) - 1))
#define JDM_ALIGN_DOWN(x, align) ((x) & ~((align) - 1))
#define JDM_IS_ALIGNED(x, align) (((x) & ((align) - 1)) == 0)
#define JDM_SWAP(a, b)       \
    do {                     \
        typeof(a) tmp = (a); \
        (a) = (b);           \
        (b) = tmp;           \
    } while (0)

#define JDM_ZERO_MEMORY(ptr, size) \
    do {                           \
        memset((ptr), 0, (size));  \
    } while (0)

#define JDM_COPY_MEMORY(dest, src, size) \
    do {                                 \
        memcpy((dest), (src), (size));   \
    } while (0)

#define JDM_SET_MEMORY(ptr, value, size) \
    do {                                 \
        memset((ptr), (value), (size));  \
    } while (0)
#define JDM_MOVE_MEMORY(dest, src, size) \
    do {                                 \
        memmove((dest), (src), (size));  \
    } while (0)

#define JDM_IS_POWER_OF_TWO(x) (((x) != 0) && (((x) & ((x) - 1)) == 0))

#define JDM_ROUND_UP_TO_POWER_OF_TWO(x) \
    (JDM_IS_POWER_OF_TWO(x) ? (x) : (1 << (32 - __builtin_clz((x) - 1))))

#define JDM_ROUND_DOWN_TO_POWER_OF_TWO(x) \
    (JDM_IS_POWER_OF_TWO(x) ? (x) : (1 << (31 - __builtin_clz((x)))))

#define JDM_NEXT_POWER_OF_TWO(x) \
    (JDM_IS_POWER_OF_TWO(x) ? (x) : (1 << (32 - __builtin_clz((x)))))

#endif  // JDM_DEFS_H
