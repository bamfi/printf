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


	if (format == NULL)
		return (-1);

	va_start(args, format);
	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] == '%')
		{
			j++;
			count += print_case(format[j], args);
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
