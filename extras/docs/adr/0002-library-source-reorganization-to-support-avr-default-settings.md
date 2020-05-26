# 2. Library source reorganization to support AVR default settings

Date: 2020-05-26

## Status

Accepted

## Context

We want to provide default settings for AVR chips that reduces the library size *without modifying the original `printf` library files*. We can do this by including the `.c` file directly after we specify the default settings. However, this results in duplicate symbols when the `printf` library files are contained in the `src/` directory, because the Arduino IDE automatically builds them. We need a way to prevent the IDE from automatically building the files so we do not end up with duplicate symbols.

## Decision

* The `src/` folder contains `LibPrintf.cpp` and `LibPrintf.h`
* The `extras/printf` folder contains `printf.c` and `printf.h` as files directly within the repository, enabling the library to work without submodule
* `LibPrintf.h` will include `../extras/printf/printf.h` to access the `printf` definitions
* `LibPrintf.cpp` will include `../extras/printf/printf.c` to add the symbols for the `printf` library. We will also add our definition defaults for `__AVR__`, ensuring that the settings are applied automatically without modifying build rules

## Consequences

* We can modify default settings without changing the original library files, which we do not own or maintain.
* We are referencing source code in an Arduino library build that is kept outside of the `src/` folder, which can be confusing to users. This might also break in the future.
