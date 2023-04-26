#include "main.h"
/**
 * print_case - prints the argument of the type given
 * @t: the type of argument to be printed
 * @args: the argument to print
 * Return: the number of characters printed
*/
int print_case(char t, va_list args)
{
	switch (t)
	{
		case'c':
			return (_putchar(va_arg(args, int)));
		case's':
			{
			ss = va_arg(args, char *);
			if (ss == NULL)
				return (_puts("(null)"));
			return (_puts(ss));
			}
		case'd':
		case'i':
			return (print_int(va_arg(args, int)));
		case'b':
			return (print_binary(va_arg(args, unsigned int)));
		case'%':
			return (_putchar('%'));
		default:
			return (0);
	}
}
