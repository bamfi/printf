#include "main.h"


/**
 * _print_integer - prints an integer to stdout
 * @n: the integer to print
 *
 * Return: the number of characters printed
 */
int _print_integer(int n)
{
	int i, j = 1, count = 0;
	unsigned int num;

	if (n < 0)
	{
		_putchar('-');
		num = -n;
		count++;
	}
	else
		num = n;

	while (num / j > 9)
		j *= 10;

	for (i = j; i >= 1; i /= 10)
	{
		_putchar(num / i + '0');
		num %= i;
		count++;
	}

	return (count);
}
