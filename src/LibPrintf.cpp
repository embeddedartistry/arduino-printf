#include "LibPrintf.h"
#include "Arduino.h"

static Print& print_instance = Serial;

void printf_init(Print& PrintClass)
{
	print_instance = PrintClass;
}


// If you use the default printf() implementation, this function will route the output
// to the Serial class
extern "C" __attribute__((weak)) void _putchar(char character)
{
	print_instance.print(character);
}
