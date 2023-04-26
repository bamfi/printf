#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
int _printf(const char *format, ...);
int print_case(char t, va_list args);
int _putchar(char c);
int _puts(char *str);
int print_int(int z);
int print_binary(unsigned int a);

#endif
