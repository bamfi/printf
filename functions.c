#include "main.h"
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

	if (s == NULL)
	{
		_putchar('(');
		_putchar('n');
		_putchar('u');
		_putchar('l');
		_putchar('l');
		_putchar(')');
		return (-1);
	}

	while (s[j])
	{
		_putchar(s[j]);
		j++;
	}
	return (j);
}

/**
 * print_int - a function that print an integer
 * @z: a number
 * Return: the number of digit printed
 */
int print_int(int z)
{
	int count = 0;

	if (z < 0)
	{
		_putchar('-');
		z = -z;
		count++;
	}

	if (z / 10)
	{
		count += print_int(z / 10);
	}

	_putchar(z % 10 + '0');
	count++;

	return (count);
}

/**
 * print_binary - a function that convert an unsigned int to binary
 * and print it
 * @a: unsigned int to be converted
 * Return: number of binary digit printed
*/
int print_binary(unsigned int a)
{
	int j = 0, count = 0;
	char ary[32];

	if (a == 0)
	{
		_putchar('0');
		return (1);
	}

	while (a > 0)
	{
		ary[j] = (a & 1) + '0';
		a = a >> 1;
		j++;
	}

	for (; j >= 0; j--)
	{
		_putchar(ary[j]);
		count++;
	}
	return (count);
}











