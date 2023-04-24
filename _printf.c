#include "main.h"
/**
 * _printf - a function that produces output according to a format.
 * @format: a string of characters that specifies the
 * output format of the function
 * Return: a positive integer on success
*/
int _printf(const char *format, ...)
{
	int j, count = 0;
	char *ss;

	if (!format)
		return (-1);
	va_list args;

	va_start(args, format);
	for (j = 0; format && format[j]; j++)
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
					ss = va_arg(args, char *);
					if (ss == NULL)
					count += _puts("(null)");
					else
					count += _puts(ss);
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
