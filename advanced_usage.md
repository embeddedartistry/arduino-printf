## Advanced Usage

You can include `printf.h` directly and supply your own implementation of `putchar_()`. This approach is useful if you want to use the library in a test suite (skipping Arduino SDK headers).

### Changing Default Output Target

You can specify any class derived from the `Print` base class for use with `printf()`. To change the output class, use the `printf_init()` function in `setup()`:

```
printf_init(Serial1);
Serial1.begin(115200);
```

### More Complicated Output Scenarios

More complicated logic is possible, such as sending `printf()` output to multiple locations. The `mpaland/printf` library requires that the end-user defines a `putchar_()` function, which is used by all other library functions. There is an example script that explains this.
