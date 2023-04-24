#include "main.h"
/**
 * _printf - print formatted output to stdout
 * @format: format string containing conversion specifiers
 * Return: number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'c':
				count += _putchar(va_arg(args, int));
				break;
			case 's':
				count += _puts(va_arg(args, char *));
				break;
			case 'd':
				count += _print_integer(va_arg(args, int));
				break;
			case '%':
				count += _putchar('%');
				break;
			default:
				return (-1);
			}
		}
		else
		{
			count += _putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}

