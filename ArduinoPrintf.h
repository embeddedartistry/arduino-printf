#ifndef ARDUINO_PRINTF_H_
#define ARDUINO_PRINTF_H_

#include "Print.h"
#include "printf.h"

// In Setup(), you must initialize printf with a serial class.
// You must also configure the Serial interface in setup() and call begin().
void printf_init(Print* StreamClass = nullptr);

#endif //ARDUINO_PRINTF_H_
