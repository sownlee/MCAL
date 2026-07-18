#ifndef PLATFORMTYPES_H
#define PLATFORMTYPES_H

#ifdef __cplusplus
extern "C"{
#endif

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define PLATFORMTYPES_VENDOR_ID                      15
#define PLATFORMTYPES_AR_RELEASE_MAJOR_VERSION       4
#define PLATFORMTYPES_AR_RELEASE_MINOR_VERSION       4
#define PLATFORMTYPES_AR_RELEASE_REVISION_VERSION    0
#define PLATFORMTYPES_SW_MAJOR_VERSION               1
#define PLATFORMTYPES_SW_MINOR_VERSION               0
#define PLATFORMTYPES_SW_PATCH_VERSION               0

#define CPU_TYPE_8 8
#define CPU_TYPE_16 16
#define CPU_TYPE_32 32
#define CPU_TYPE_64 64
#define MSB_FIRST 0
#define LSB_FIRST 1
#define HIGH_BYTE_FIRST 0
#define LOW_BYTE_FIRST 1

#define CPU_TYPE (CPU_TYPE_32)
#define CPU_BIT_ORDER (LSB_FIRST)
#define CPU_BYTE_ORDER (LOW_BYTE_FIRST)

#define TRUE true
#define FALSE false

/* 0 ..+255 (0x00..0xFF) */
typedef bool boolean;

/* 0 ..+65535 (0x0000..0xFFFF) */
typedef uint8_t uint8;

/* 0 ..+4294967295 (0x00000000..0xFFFFFFFF) */
typedef uint16_t uint16;

/* 0..18446744073709551615 (0x0000000000000000..0xFFFFFFFFFFFFFFFF) */
typedef uint32_t uint32;

/* -128 ..+127 (0x80..0x7F) */
typedef uint64_t uint64;

/* -128 ..+127 (0x80..0x7F) */
typedef int8_t sint8;

/* -32768 ..+32767 (0x8000..0x7FFF) */
typedef int16_t sint16;

/* -2147483648.. +2147483647 (0x80000000..0x7FFFFFFF) */
typedef int32_t sint32;

/* -9223372036854775808..9223372036854775807 (0x8000000000000000..0x7FFFFFFFFFFFFFFF ) */
typedef int64_t sint64;

typedef float float32;

typedef double float64;

#ifdef __cplusplus
}
#endif


#endif /* PLATFORMTYPES_H */
