#ifndef ARDUINO_PRINTF_H_
#define ARDUINO_PRINTF_H_

#ifdef PRINTF_DISABLE_ALL

#define printf(...)
#define sprintf(...)
#define vsprintf(...)
#define snprintf(...)
#define vsnprintf(...)
#define vprintf(...)

#define printf_init(...)

#else // printf is enabled

#include "Print.h"
#include "../extras/printf/printf.h"

# define printf    printf_
# define sprintf   sprintf_
# define vsprintf  vsprintf_
# define snprintf  snprintf_
# define vsnprintf vsnprintf_
# define vprintf   vprintf_

// Adds a compatibility definition for those who were using the old library
#define _putchar(c) putchar_(c)

// In Setup(), you must initialize printf with a Print class if you don't want
// to use the default Serial object. If you want the default behavior, calling this
// function is not necessary.
//
// The caller is responsible for configure the Serial interface in setup() and calling
// Serial.begin().
#ifdef __AVR_ATmega4809__
void printf_init(arduino::Print& StreamClass);
#else
void printf_init(Print& StreamClass);
#endif // __AVR_ATmega4809__

#endif // PRINTF_DISABLE_ALL
#endif //ARDUINO_PRINTF_H_
