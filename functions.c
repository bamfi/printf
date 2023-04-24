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
