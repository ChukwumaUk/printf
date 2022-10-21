#include "main.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>

/**
 * get_flags - get flags
 * @format: the format
 * @i: the index
 * Return: an array of the flags
 */

int *get_flags(const char *format, int i)
{
	int *flags;
	int j = 0;

	flags = malloc(sizeof(int) * 4);
	for (; j < 4; j++)
		flags[j] = 0;

	while (format[i] == ' ' || format[i] == '+' || format[i] == '#')
	{
		if (format[i] == ' ' && flags[1] != ' ')
			flags[1] = ' ' + 0;
		if (format[i] == '+' && flags[2] != '+')
			flags[2] = '+' + 0;
		if (format[i] == '#' && flags[3] != '#')
			flags[3] = '#' + 0;
		i++;
	}

	flags[0] = i;

	return (flags);
}

/**
 * _printf - prints all va_args
 * @format: format of the args
 * Return: number of chars printed
 */

int _printf(const char *format, ...)
{
	int i = 0, n = 0, j;
	va_list list;
	int flags[4];

	va_start(list, format);
	if (format)
	{
		while (format[i])
		{
			if (format[i] == '%' && (format[i - 1] != '\\' && format[i - 1] != '%'))
			{
				i++;
				if (format[i] == '%')
					n += _putchar('%');
				for (j = 0; j < 4; j++)
					flags[j] = get_flags(format, i)[j];
				i = flags[0];
				n += ctox(format[i], list, flags);
				n += ctoy(format[i], list, flags);
				n += sandp(format[i], list);
				i++;
			}
			else
			{
				n += _putchar(format[i]);
				i++;
			}
		}
	}
	va_end(list);

	return (n);

}

/**
 * ctox - print the converted arg based on the conversion specifier
 * @c: conversion specifier
 * @list: va_arg list
 * @flags: flags
 * Return: number of chars printed
 */

int ctox(char c, va_list list, int *flags)
{
	int i = 0;

	switch (c)
	{
		case ('c'):
			i += _putchar(va_arg(list, int));
			break;
		case ('d'):
		{
			int temp = va_arg(list, int);

			if (flags[1] == ' ' && flags[2] != '+')
				i += _putchar(' ');
			if (flags[2] == '+' && temp >= 0)
				i += _putchar('+');
			i += print_number(temp);
			break;
		}
		case('i'):
		{
			int temp = va_arg(list, int);

			if (flags[1] == ' ' && flags[2] != '+')
				i += _putchar(' ');
			if (flags[2] == '+' && temp >= 0)
				i += _putchar('+');
			i += print_number(temp);
			break;
		}
		case ('b'):
			i += itob(va_arg(list, int));
			break;
	}
	return (i);
}

/**
 * ctoy - print chars
 * @c: conversion specifier
 * @list: args
 * @flags: flags
 * Return: number of chars printed
 */

int ctoy(char c, va_list list, int *flags)
{
	int i = 0;

	switch (c)
	{
		case ('u'):
			i += print_ui(va_arg(list, unsigned int));
			break;
		case ('x'):
		{
			if (flags[3])
			{
				i += _putchar('0');
				i += _putchar('x');
			}
			i += itox(va_arg(list, unsigned int), 'x');
			break;
		}
		case ('X'):
		{
			if (flags[3])
			{
				i += _putchar('0');
				i += _putchar('X');
			}
			i += itox(va_arg(list, unsigned int), 'X');
			break;
		}
		case ('o'):
		{
			if (flags[3])
				i += _putchar('0');
			i += itoo(va_arg(list, unsigned int));
			break;
		}
	}
	return (i);
}


/**
 * sandp - for s, S and p conversion specifiers
 * @c: the specifier
 * @list: args
 * Return: number of chars printed
 */

int sandp(char c, va_list list)
{
	int i = 0;

	switch (c)
	{
		case ('s'):
			i += _puts(va_arg(list, char *));
			break;
		case ('S'):
			i += _putS(va_arg(list, char *));
			break;
		case ('p'):
			i += _putp((long int) va_arg(list, void *));
			break;
	}
	return (i);
}
