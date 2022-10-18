#include "main.h"
#include <stddef.h>
#include <stdarg.h>

/**
 * _printf - prints all va_args
 * @format: format of the args
 * Return: number of chars printed
 */

int _printf(const char *format, ...)
{
	int i = 0, n = 0;
	va_list list;

	va_start(list, format);
	if (format)
	{
		while (format[i])
		{
			if (format[i] == '%' && format[i - 1] != '\\')
			{
				i++;
				n += ctox(format[i], list);
			}
			else
			{
				n += _putchar(format[i]);
			}
			i++;
		}
	}
	va_end(list);

	return (n);

}

/**
 * ctox - print the converted arg based on the conversion specifier
 * @c: conversion specifier
 * @list: va_arg list
 * Return: number of chars printed
 */

int ctox(char c, va_list list)
{
	int i = 0;

	switch (c)
	{
		case ('c'):
			i += _putchar(va_arg(list, int));
			break;
		case ('d'):
			i += print_number(va_arg(list, int));
			break;
		case('i'):
			i += print_number(va_arg(list, int));
			break;
		case ('b'):
			i += itob(va_arg(list, int));
			break;
		case ('u'):
			i += print_ui(va_arg(list, unsigned int));
			break;
		case ('x'):
			i += itox(va_arg(list, unsigned int), 'x');
			break;
		case ('X'):
			i += itox(va_arg(list, unsigned int), 'X');
			break;
		case ('s'):
			i += _puts(va_arg(list, char *));
			break;
		case ('S'):
			i += _putS(va_arg(list, char *));
			break;
	}
	return (i);
}

