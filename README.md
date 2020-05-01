# Arduino Printf

This library adds support for the `printf()` function to Arduino projects. This code leverages the wonderful [mpaland/printf](https://github.com/mpaland/printf) library, which is designed for use in embedded systems. For more information about what is available, please refer to the [parent library documentation](https://github.com/mpaland/printf/blob/master/README.md).

## What This Library Provides

This library provides a standalone implementation for the following functions:

* `printf()`
* `sprintf()`
* `snprintf()`
* `vprintf()`
* `vsnprintf()`

## Project Target

This library aims to offer a complete `printf()` solution while maintaining low storage and flash requirements. 
This is **critical** for MCUs with limited storage and RAM. This project is ideal for [AVR based MCUs](https://en.wikipedia.org/wiki/AVR_microcontrollers) like the 
Arduino Uno and it's siblings.

## [ESP8266](https://github.com/esp8266/Arduino) and [ESP32](https://github.com/espressif/arduino-esp32)
The Arduino implementations for the ESP8266 and ESP32 already include a `printf()` implementation as part of 
the base library.

## Using the Library

To use this library in your Arduino project, you need to include the header:

```
#include <LibPrintf.h>
```

By default, the library can be used without any special initialization. Any `printf()` calls will be output using 
the Arduino `Serial` interface.

## Advanced Usage

You can include `printf.h` directly and supply your own implementation of `_putchar()`. This approach is useful if you want to use the library in a test suite (skipping Arduino SDK headers).

### Changing Default Output Target

You can specify any class derived from the `Print` base class for use with `printf()`. To change the output class, use the `printf_init()` function in `setup()`:

```
printf_init(Serial1);
Serial1.begin(115200);
```

### More Complicated Output Scenarios

More complicated logic is possible, such as sending `printf()` output to multiple locations. The `mpaland/printf` library requires that the end-user defines a `_putchar()` function, which is used by all other library functions. There is an example script that explains this.

## Disabling Specific Formats

If memory footprint is critical, floating point, exponential, and 'long long' support and can be turned off via the `PRINTF_DISABLE_SUPPORT_FLOAT`, `PRINTF_DISABLE_SUPPORT_EXPONENTIAL` and `PRINTF_DISABLE_SUPPORT_LONG_LONG` compiler switches. You must define these symbols in the build system.

## Examples

Multiple examples are provided with this library in the [examples/](examples/) folder.

* [Default Usage](examples/default_to_serial/default_to_serial.ino)
    - Without any initialization, `Serial` will be the default output for `printf()`
    - This example initializes the `Serial` class and prints in a loop
* [Specify Print Class](examples/specify_print_class/specify_print_class.ino)
    - Any class derived from the `Print` base class can be used with the **Arduino Printf** library
    - This example initializes `printf` with `Serial1` instead of `Serial`
* [Override Putchar](examples/override_putchar/override_putchar.ino)
    - This example overrides `_putchar()` and adds a space in between every letter
    - You can implement any kind of logic within `_putchar()` that you like, such as outputting information to multiple ports
