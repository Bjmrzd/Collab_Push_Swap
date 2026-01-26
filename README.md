# README.md - Printf Project

*This project has been created as part of the 42 curriculum by pcaudron.*

## Description

__Printf__ is a function which permits to output arguments according to their format such as %i (integer), %d (decimal), %c (character), %s (string) %x (hexadecimal in lowercase), %X (hexadecimal in uppercase), %p (memory adress of a pointer) or %u (unsigned int).

## Instructions

### Compilation

The project includes a **Makefile** with the following rules:

```
make       # Compiles the library and creates libftprintf.a
make all   # Same as above
make clean # Removes object files
make fclean # Removes all generated files including libftprintf.a
make re    # Recompiles the entire project from scratch
```

### Compilation Flags

All source files are compiled with:
- `-Wall -Wextra -Werror` flags for strict error checking
- `cc` compiler
- No relinking on subsequent builds

### Library Creation

The library is created using the `ar` command (not libtool) and is output as `libftprintf.a` at the repository root.

### Using the Library

To use ft_printf in other projects:

1. Include the header file in your source:
   ```c
   #include "ft_printf.h"
   ```

2. Link against the library during compilation:
   ```
   cc -Wall -Wextra -Werror my_program.c ft_printf.a -o my_program
   ```

## Project Structure

| Functions | Format | Description | Return Value |
| -------- | :-------- |:------- | :-------: |
| `ft_printf`  | cspdiuxX% |**Behave like the printf function of the stdio library** | _Returns the number of bytes written._ |
| `ft_putchar` | %c | **Write a single character**. | _Returns the number of bytes written._ |
| `ft_putnbr_hexa` | %x and %X |**Write a number in hexadecimal**. | _Returns the number of bytes written._|
| `ft_putnbr_u` | %u |**Write an unsigned int**. | _Returns the number of bytes written._ |
| `putnbr` | %i and %d |**Write a number in decimal**. | _Returns the number of bytes written._ |
| `putptr` | %p |**Write the memory adress of a pointer**. | _Returns the number of bytes written._ |
| `putstr` | %s |**Write a string**. | _Returns the number of bytes written._ |

## Resources

### Learning References

- **W3Schools C Reference** — Comprehensive documentation on C language fundamentals and standard functions
- **GeeksforGeeks C Tutorials** — Detailed articles on variadic functions
- **Official C Standard Library (man pages)** — Authoritative source for standard function behavior

### AI Usage Disclosure

AI wasn't used in this project.

## Notes
### Explanation and Justification of Algorithm and Data Structure

The algorithm is in two parts: first the conversion and writing of arguments depending of their formats, and a second which go through the given string and converts each arguments using the first function. This algorithm seemed to be the most intuitive.
