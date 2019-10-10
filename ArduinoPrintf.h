#ifndef ARDUINO_PRINTF_H_
#define ARDUINO_PRINTF_H_

#include "Print.h"
#include "printf.h"

// In Setup(), you must initialize printf with a Print class if you don't want
// to use the default Serial object. If you want the default behavior, calling this
// function is not necessary.
//
// The caller is responsible for configure the Serial interface in setup() and calling
// Serial.begin().
void printf_init(Print& StreamClass);

#endif //ARDUINO_PRINTF_H_
