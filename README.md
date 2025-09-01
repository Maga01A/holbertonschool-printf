# Holberton School Printf

## Description

This project is a custom implementation of the `printf` function in C, created as part of the Holberton School curriculum. The goal of the project is to build a simplified version of the standard `printf` function, which will handle a variety of format specifiers like integers, strings, characters, hexadecimal numbers, and more. It provides an excellent opportunity to gain hands-on experience with variadic functions, which allow a function to accept a variable number of arguments.

## Features

- Custom implementation of the `printf` function.
- Supports various format specifiers such as:
  - `%d` / `%i` - for integers.
  - `%s` - for strings.
  - `%c` - for characters.
  - `%x` / `%X` - for hexadecimal values.
  - `%p` - for pointers.
  - `%u` - for unsigned integers.
- Modular design: Each format specifier is handled by its own function for better readability and scalability.
- CMake build system for multi-platform support.
- Includes test cases to validate functionality.

## Files

- **`_printf.c`**: The main implementation of the custom `printf` function.
- **`_putchar.c`**: Contains the `_putchar` function used to print individual characters.
- **`main.c`**: Example main program for testing the custom `printf`.
- **`main.h`**: Header file with declarations for the functions.
- **`Makefile`**: Build system for compiling the project.
- **`man_3_printf`**: A man page for the custom `printf` function.
- **`print_*` files**: Functions that handle specific format specifiers (e.g., `print_number.c`, `print_hexadecimal.c`, `print_octal.c`, etc.).

## Installation

To clone and build the project:

1. Clone the repository:
   ```bash
   git clone https://github.com/Maga01A/holbertonschool-printf.git
   ```
2. Navigate into the project directory:
   ```bash
   cd holbertonschool-printf
   ```
3. Compile the project:
   ```bash
   make
   ```
