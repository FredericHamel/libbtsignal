# libbtsignal
This is a simple library to help find a problem
that a debugger failed to find by displaying a
simple backtrace.

## AUTHOR
- Frédéric Hamel

## COMPILING
This project uses the mesonbuild system.
```
> meson . build
> ninja -C build
```

## Example usage
There is a simple example that use default configuration.
```
> LD_PRELOAD=/path/to/libbtsignal ./yourexecutable
```

There is a simple that specify the maximum stack size to display.
```
> STACK_SIZE=32 LD_PRELOAD=/path/to/libbtsignal ./yourexecutable
```

