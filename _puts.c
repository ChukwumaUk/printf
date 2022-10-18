#include "main.h"

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
