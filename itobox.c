#include "main.h"

/**
 * itob - convertes decimal to binary and print
 * @n: integer number to convert
 * Return: the number of digits printed
 */

int itob(int n)
{
	int i = 0, r;

	if (n > 1)
	{
		i = itob(n / 2);
	}
	r = n % 2;
	i += _putchar(r + '0');
	return (i);

}

/**
 * itoo - convertes decimal to octal
 * @n: integer to convert
 * Return: number of digits printed
 */

int itoo(unsigned int n)
{
	int i = 0, r;

	if (n > 7)
	{
		i = itoo(n / 8);
	}
	r = n % 8;
	i += _putchar(r + '0');
	return (i);
}

/**
 * itox - convertes decimal to hexadecimal
 * @n: the integer to convert
 * @c: the case specifier
 * Return: the number of digits printed
 */

int itox(unsigned int n, char c)
{
	int i = 0, r;

	if (n > 15)
	{
		i = itox(n / 16, c);
	}
	r = n % 16;
	if (r > 9 && c == 'x')
		i += _putchar((r - 10) + 'a');
	else if  (r > 9 && c == 'X')
		i += _putchar((r - 10) + 'A');
	else if (r < 10)
		i += _putchar(r + '0');

	return (i);
}


