#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
int _putchar(char c);
int _puts(char *str);
int _print_integer(int n);
int _print_unsigned(unsigned int n);
int _print_hex(unsigned int n, int uppercase);
int _print_octal(unsigned int n);
int _print_float(double f);
int _print_pointer(void *p);
int _printf(const char *format, ...);
/**
 * _putchar - prints a character
 * @c: a character
 * Return: an integer 1 on success
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _puts - print a string
 * @s: a string
 * Return: the number of characters written
 */
int _puts(char *s)
{
	int j = 0;

	while (s[j])
	{
		_putchar(s[j]);
		j++;
	}
	return (j);
}
#endif /* MAIN_H */

