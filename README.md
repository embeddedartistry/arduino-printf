# arduino-printf

This library adds support for the `printf()` function to Arduino projects. This code leverages the wonderful [mpaland/printf](https://github.com/mpaland/printf) library, which is designed for use in embedded systems. For more information about what is available, please refer to the [parent library documentation](https://github.com/mpaland/printf/blob/master/README.md).

## Using the Library

To use this library in your Arduino project, you need to include the header:

```
#include LibPrintf.h
```

By default, the library can be used without any special initialization. The `Serial` object is the default output target. You must still initialize the `Serial` object in `setup()`, the library will not do this for you.

You can specify any class derived from the `Print` base class for use with `printf()`. To change the output class, use the `printf_init` function in `setup()`:

```
printf_init(Serial1);
Serial1.begin(115200);
```

More complicated logic is possible, such as sending `printf()` output to multiple locations. The `mpaland/printf` library requires that the end-user defines a `void _putchar(char character)` function, which is used by all other library functions.

Within this library, the implementation is weakly linked:

```
extern "C" __attribute__((weak)) void _putchar(char character)
{
    print_instance->print(character);
}
```

To implement more complex behaviors, simply define this function in your Sketch or program:

```
void _putchar(char character)
{
  Serial.print(character);
  Serial.print(' ');
}
```

And your prototype will be used instead of the library's version.

## Advanced Use

You can include `printf.h` directly and supply your own implementation of `_putchar`. This approach is useful if you want to use the library in a test suite (skipping Arduino SDK headers).

## Disabling Specific Formats

If memory footprint is critical, floating point, exponential and 'long long' support and can be turned off via the `PRINTF_DISABLE_SUPPORT_FLOAT`, `PRINTF_DISABLE_SUPPORT_EXPONENTIAL` and `PRINTF_DISABLE_SUPPORT_LONG_LONG` compiler switches. You must define these symbols in the build system.

## Examples

Multiple examples are provided with this library in the [examples/](examples/) folder.

* [Default Usage](examples/default_to_serial/default_to_serial.ino)
    - Without any initialization, `Serial` will be the default output for `printf()`
    - This example initializes the `Serial` class and prints in a loop
    - Open the Arduino serial monitor to see the output
* [Specify Print Class](examples/specify_print_class/specify_print_class.ino)
    - Any class derived from the `Print` base class can be used with the `printf` library
    - This example initializes `printf` with `Serial1` instead of `Serial`
* [Override Putchar](examples/override_putchar/override_putchar.ino)
    - Because the `_putchar` function is weakly linked, you can override the default implementation to supply your own in the sketch
    - This example overrides `_putchar` and adds a space in between every letter
    - You can implement any kind of logic within `_putchar` that you like, such as outputting information to multiple ports
