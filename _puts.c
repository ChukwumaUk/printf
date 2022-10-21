#include "main.h"
#include <stdlib.h>
#include <limits.h>
/**
 * _puts - prints a string to the stdout
 * @s: the string to be printed
 * Return: the number of chars printed
 */

int _puts(char *s)
{
	/**
	 * @i: loop and string counter
	 */
	int i = 0;

	while (*(s + i) != 0)
	{
		i += _putchar(*(s + i));
	}
	return (i);
}

/**
 * _putS - print only printable chars
 * @s: the string to print
 * Return: number of chars printed
 */

int _putS(char *s)
{
	int i = 0, n = 0;

	while (s[i])
	{
		if ((s[i] > 0 && s[i] < 32) || s[i] >= 127)
		{
			n += _putchar('\\');
			n += _putchar('x');
			if (s[i] < 16)
			{
				n += _putchar('0');
				if (s[i] > 9)
					n += _putchar((s[i] - 10) + 'A');
				else
					n += _putchar(s[i] + '0');

			}
			else
			{
				n += itox((unsigned int) s[i], 'X');
			}
		}
		else
		{
			n += _putchar(s[i]);
		}
		i++;
	}
	return (i);
}

/**
 * _putp - print the address stored in the pointer p
 * @p: the void pointer
 * Return: the number of chars printed
 */

int _putp(long int p)
{
	int i;
	unsigned long int n = p;

	if (p)
	{
		i = _putchar('0');
		i += _putchar('x');
		if (p < 0)
		{
			n = LONG_MAX + (-1 * p);
		}
		i += ltox(n);
		return (i);
	}
	else
	{
		return (0);
	}
}

/**
 * ltox - converts unsigned long int to hex
 * @n: the int to convert
 * Return: the number of chars printed
 */

int ltox(unsigned long int n)
{
	int i;
	unsigned long int r;

	if (n > 16)
		i = ltox(n / 16);
	r = n % 16;
	if (r > 9)
		i += _putchar((r - 10) + 'a');
	else
		i += _putchar(r + '0');
	return (i);
}
