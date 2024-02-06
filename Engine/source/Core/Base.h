#pragma once
#include <stdio.h>
#include <stdint.h>

#define LOG(...) { printf(__VA_ARGS__); }
#define ERROR_RETURN(R, ...) { printf(__VA_ARGS__); return R; }
#define ERROR_RETURN_VOID(...) { printf(__VA_ARGS__); return; }

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
