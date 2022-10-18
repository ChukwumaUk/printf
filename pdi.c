#include "main.h"

/**
 * print_number - prints an integer using _putchar only
 * @m: the integer to print
 * Return: the number of digits printed
 */

int print_number(int m)
{
	/**
	 * @n: unsigned version of m
	 */
	unsigned int n = m;
	int s = 0;

	if (m < 0)
	{
		n = -1 * n;
		s += _putchar('-');
	}
	if (n / 10 > 0)
	{
		s += print_number(n / 10);
	}
	s += _putchar((n % 10) + '0');
	return (s);
}

/**
 * print_ui - prints an unsigned int
 * @n: the unsigned int to print
 * Return: the number of digits printed
 */

int print_ui(unsigned int n)
{
	int i = 0;

	if (n / 10 > 0)
		i = print_ui(n / 10);
	i += _putchar((n % 10) + '0');
	return (i);

}
