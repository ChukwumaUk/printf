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

/**
 * ctoz - format double data type
 * @c: specifier
 * @list: var args
 * @flags: flags
 * Return: number of chars printed
 */
/**
*int ctoz(char c, va_list list, int *flags)
*{
*	int i = 0;
*
*	switch (c)
*	{
*		case ('a'):
*			i += dtoa(va_arg(list, double), 'a');
*			break;
*		case ('A'):
*			i += dtoa(va_arg(list, double), 'A');
*			break;
*		case ('e'):
*			i += dote(va_arg(list, double), 'e');
*			break;
*		case ('E'):
*			i += dote(va_arg(list, double), 'E');
*			break;
*		case ('f'):
*			i += dtof(va_arg(list, double), 'f');
*			break;
*		case ('F'):
*			i += dtof(va_arg(list, double), 'F');
*			break;
*		case ('g'):
*			i += dtog(va_arg(list, double), 'g');
*			break;
*		case ('G'):
*			i += dtog(va_arg(list, double), 'G');
*			break;
*	}
*	return (i);
*}
*/
