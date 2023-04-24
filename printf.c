#include "main.h"

/**
 * _printf - prints a formatted string
 * @format: format string containing directives to format output
 *
 * Return: number of characters printed (excluding null byte used to end output)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0, i = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;

			if (!format[i])
				return (-1);

			if (format[i] == '%')
				printed_chars += _putchar('%');

			else if (get_func(format[i]))
				printed_chars += get_func(format[i])(args);

			else
			{
				printed_chars += _putchar('%');
				printed_chars += _putchar(format[i]);
			}
		}
		else
			printed_chars += _putchar(format[i]);

		i++;
	}

	va_end(args);

	return (printed_chars);
}

/**
 * get_func - selects the correct function to perform the operation
 * specified by the given conversion specifier
 * @c: the conversion specifier
 *
 * Return: a pointer to the corresponding function
 */
int (*get_func(char c))(va_list)
{
	unsigned int i;

	print_t p[] = {
		{'c', print_c},
		{'s', print_s},
		{'d', print_d},
		{'i', print_d},
		{'u', print_u},
		{'o', print_o},
		{'x', print_x},
		{'X', print_X},
		{'p', print_p},
		{'\0', NULL}
	};

	for (i = 0; p[i].t != '\0'; i++)
		if (p[i].t == c)
			return (p[i].f);

	return (NULL);
}

/**
 * print_c - prints a character
 * @args: arguments list containing a character to print
 *
 * Return: number of characters printed
 */
int print_c(va_list args)
{
	return (_putchar(va_arg(args, int)));
}

/**
 * print_s - prints a string
 * @args: arguments list containing a string to print
 *
 * Return: number of characters printed
 */
int print_s(va_list args)
{
	char *s = va_arg(args, char *);
	int i;

	if (!s)
		s = "(null)";

	for (i = 0; s[i]; i++)
		_putchar(s[i]);

	return (i);
}

/**
 * print_d - prints a decimal integer
 * @args: arguments list containing an integer to print
 *
 * Return: number of characters printed
 */
int print_d(va_list args)
{
	int n = va_arg(args, int);
	int digits = count_digits(n);

	if (n < 0)
	{
		_putchar('-');
		n *= -1;
	}

	return (print_number(n, digits));
}

/**
 * print_u - prints an unsigned decimal integer
 * @args: arguments list containing an integer to print
 *
 * Return: number of characters printed
 */
int print_u(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int digits = count_udigits(n);

	return (print_unumber(n, digits));
}

/**
 * print_o - prints an unsigned octal integer
 * @args: arguments list containing an integer to print
 *
 * Return: number of characters printed
 */
int print

