#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 *
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed
 * @list: list of arguments
 *
 * Return: Precision.
 */

int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;

	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);
	precision = 0;
	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (_isdigit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = curr_i - 1;
	return (precision);
}

/**
 * _isdigit - determines if a char is a digit
 * @c: the char
 * Return: 1 if true and 0 otherwise
 */

int _isdigit(int c)
{
	return (c < 58 && c > 47 ? 1 : 0);
}

