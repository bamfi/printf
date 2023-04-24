#include "main.h"


/**
 * _printf - print formatted output to stdout
 * @format: format string containing conversion specifiers
 *
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
			case 'i':
				count += _print_integer(va_arg(args, int));
				break;
			case 'u':
				count += _print_unsigned(va_arg(args, unsigned int));
				break;
			case 'x':
				count += _print_hex(va_arg(args, unsigned int), 0);
				break;
			case 'X':
				count += _print_hex(va_arg(args, unsigned int), 1);
				break;
			case 'o':
				count += _print_octal(va_arg(args, unsigned int));
				break;
			case 'f':
				count += _print_float(va_arg(args, double));
				break;
			case 'p':
				count += _print_pointer(va_arg(args, void *));
				break;
			case '%':
				count += _putchar('%');
				break;
			case '-':
				// left-justification flag
				break;
			case '0':
				// zero-padding flag
				break;
			case '.':
				// precision specifier
				break;
			default:
				// unsupported format specifier
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
