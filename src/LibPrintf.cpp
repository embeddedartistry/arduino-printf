#include "LibPrintf.h"
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

#if __GNUC__
/// This works around a problem where GCC is replacing
/// printf("string with no args") with puts("string with no args"), which
/// is not actually implemented in a way that is suitable for us, resulting
/// in an infinite reboot loop or simply not printing that output, depending
/// on my luck.
///
/// This is probably NOT the right way to go about this (expecting it to be undefined
/// behavior, but I have fewer tools available in Arduino land, so I am
/// sticking with this for now.
///
/// If this causes problems in the future, the next thing to try is
/// NOT using the Aliasing option (currently defined in LibPrintf.h) and instead
/// then providing definitions in the mpaland style in our LibPrintf.h header:
/// #define printf printf_
/// #define vprintf vprintf_
/// etc.
extern "C" int puts(const char * str)
{
	return printf("%s\n", str);
}
#endif //__GNUC__
