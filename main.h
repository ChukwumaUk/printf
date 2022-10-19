#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>

int _printf(const char *format, ...);

int _puts(char *);

int _putS(char *);

int _putchar(char);

int print_number(int);

int itob(int);

int itoo(unsigned int);

int itox(unsigned int, char);

int print_ui(unsigned int);

int ctox(char, va_list);

int print_octal(unsigned int n);

int print_unsig(unsigned int n);

int print_hexaup(unsigned int n);

int print_hexalow(unsigned int n);

int print_bi(unsigned int n);

int _printstring(char *s);

int rot13(char *point);

int print_rev(char *);

int print_hl(uintptr_t n);


#endif /*MAIN_H*/

