#include "LibPrintf.h"

#ifndef PRINTF_DISABLE_ALL
#include "Arduino.h"

#ifdef __AVR__
#ifndef PRINTF_PREVENT_DEFAULT_AVR_SETTINGS
#define PRINTF_DISABLE_SUPPORT_EXPONENTIAL
#define PRINTF_DISABLE_SUPPORT_LONG_LONG
#endif
#endif

// We include `printf.c` hear so we can actually control the default settings without
// modifying the original source file
#include "../extras/printf/printf.c"

static Print* print_instance = &Serial;

void printf_init(Print& PrintClass)
{
	print_instance = &PrintClass;
}

// If you use the default printf() implementation, this function will route the output
// to the Serial class
extern "C" __attribute__((weak)) void putchar_(char character)
{
	print_instance->print(character);
}

#endif // PRINTF_DISABLE_ALL
