#include "main.h"
/**
 * _printf - a function that produces output according to a format.
 * @format: a string of characters that specifies the
 * output format of the function
 * Return: a positive integer on success
*/
int _printf(const char *format, ...)
{
	va_list args;
	int j, count = 0;

	if (!format)
		return (-1);

	va_start(args, format);
	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] == '%')
		{
			j++;
			switch (format[j])
			{
				case'c':
					count += _putchar(va_arg(args, int));
					break;
				case's':
					count += _puts(va_arg(args, char *));
					break;
				case'%':
					count += _putchar('%');
					break;
				default:
					break;
			}
		}
		else
		{
			_putchar(format[j]);
			count++;
		}
	}
	va_end(args);
	return (count);
}
