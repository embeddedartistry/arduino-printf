# Arduino Printf

This library adds support for the `printf()` function to Arduino projects. This code leverages the [embeddedartistry/printf](https://github.com/embeddedartistry/printf) library (a fork of [eyalroz/printf](https://github.com/eyalroz/printf), which is designed for use in embedded systems. For more information about what is available, please refer to the [parent library documentation](https://github.com/embeddedartistry/printf/blob/master/README.md).

## What This Library Provides

This library provides a standalone implementation for the following functions:

* `printf()`
* `sprintf()` and `snprintf()`
* `vprintf()` and `vsnprintf()`

## Project Target

This library aims to offer a complete `printf()` solution while maintaining low storage and RAM requirements. 
This is **critical** for MCUs with limited storage and RAM. This project is ideal for [AVR based MCUs](https://en.wikipedia.org/wiki/AVR_microcontrollers) like the 
Arduino Uno and it's siblings.

## ESP8266 and ESP32

The Arduino implementations for the [ESP8266](https://github.com/esp8266/Arduino) and 
[ESP32](https://github.com/espressif/arduino-esp32) already include a `printf()` implementation 
as part of the base library. You do not need this library for those platforms.

## Using the Library

To use this library in your Arduino project, you need to include the header:

```
#include <LibPrintf.h>

void setup() {
    serial.begin(115200);
}
```

By default, the library can be used without any special initialization. Any `printf()` calls will be output using 
the Arduino `Serial` interface. If you need to use a different interface, call `printf_init`.

If you only want to use `s[n]printf`, then you do not need to initialize the library.

## Advanced Usage

See [advanced_usage.md](advanced_usage.md).

## Configuration

If memory footprint is critical, you can disable library features using compiler definitions. Available controls are:

* `PRINTF_DISABLE_ALL`
    - Remove all `printf` calls from the program
* `PRINTF_NTOA_BUFFER_SIZE` (unsigned integer)
    * 'ntoa' conversion buffer size, this must be big enough to hold one converted numeric number including padded zeros (dynamically created on stack)
    * Default: 32 bytes
* `PRINTF_FTOA_BUFFER_SIZE` (unsigned integer)
    - 'ftoa' conversion buffer size, this must be big enough to hold one converted float number including padded zeros (dynamically created on stack)
    - Default: 32 bytes
* `PRINTF_DISABLE_SUPPORT_FLOAT`
    - support for the floating point type (%f)
* `PRINTF_DISABLE_SUPPORT_EXPONENTIAL`
    - support for exponential floating point notation (%e/%g)
    - Default: active
* `PRINTF_DEFAULT_FLOAT_PRECISION` (unsigned integer)
* `PRINTF_MAX_FLOAT` (float value)
    - define the largest float suitable to print with %f
    - Default: active
    - 1e9
* `PRINTF_DISABLE_SUPPORT_LONG_LONG`
    - support for the long long types (%llu or %p)
    * Default: active
* `PRINTF_DISABLE_SUPPORT_PTRDIFF_T`
    - support for the ptrdiff_t type (%t)
    - Default: active

For AVR chips, the library will automatically set `PRINTF_DISABLE_SUPPORT_EXPONENTIAL` and `PRINTF_DISABLE_SUPPORT_LONG_LONG`. You can re-enable these settings by defining `PRINTF_PREVENT_DEFAULT_AVR_SETTINGS`.

Because these settings control behavior in the source file, they cannot be defined in the sketch. You must adjust the compilation commands for your project in order for the changes to take effect.

If you're using a Makefile or other build system, you'd use the `-D` flag (e.g., `-DPRINTF_DISABLE_SUPPORT_EXPONENTIAL`) to the library build target. For Arduino IDE, the flags need to be added to the compiler.extra_flags property in [platform.txt](https://arduino.github.io/arduino-cli/platform-specification/#platformtxt) or [platform.local.txt](https://arduino.github.io/arduino-cli/platform-specification/#platformlocaltxt). You would need to restart the IDE for the changes to take effect.

Here are comparisons for a simple test sketch showing the overall sketch size for different configurations:

| Type           | Bytes |
| -------------- | ----- |
| No Serial      | 1606  |
| All options enabled | 9476  |
| Disable long long and exponential | 6328 |
| Disable long long, float, and exponential | 4256 |

## Examples

Multiple examples are provided with this library in the [examples/](examples/) folder.

* [Default Usage](examples/default_to_serial/default_to_serial.ino)
    - Without any initialization, `Serial` will be the default output for `printf()`
    - This example initializes the `Serial` class and prints in a loop
* [Specify Print Class](examples/specify_print_class/specify_print_class.ino)
    - Any class derived from the `Print` base class can be used with the **Arduino Printf** library
    - This example initializes `printf` with `Serial1` instead of `Serial`
* [Override Putchar](examples/override_putchar/override_putchar.ino)
    - This example overrides `putchar_()` and adds a space in between every letter
    - You can implement any kind of logic within `putchar_()` that you like, such as outputting information to multiple ports
