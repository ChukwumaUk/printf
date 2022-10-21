#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);

int _puts(char *);

int _putp(long int);

int _putS(char *);

int *get_flags(const char *, int);

int _putchar(char);

int print_number(int);

int itob(int);

int itoo(unsigned int);

int itox(unsigned int, char);

int ltox(unsigned long int);

int print_ui(unsigned int);

int ctox(char, va_list, int *);

int ctoy(char, va_list, int *);

int sandp(char, va_list);

int ctoz(char, va_list, int *);


#endif /*MAIN_H*/

