#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>
int _putchar(char c);
int _pow(int a, int b);
/**
 * struct op - Struct op
 *
 * @fmt: format of the soecifier
 * @func: function associated with the specifier
 */
typedef struct op
{
	char fmt;
	void (*func)(va_list, int *);
} spec_t;
void print_char(va_list valist, int *n);
void print_string(va_list valist, int *n);
void print_int(va_list valist, int *n);
void print_binary(va_list valist, int *n);
int _printf(const char *format, ...);

#endif /* MAIN_H */