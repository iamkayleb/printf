#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>
int _putchar(char c);
unsigned long _pow(unsigned int a, unsigned int b);
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
void print_decimal(va_list valist, int *n);
void print_octal(va_list valist, int *n);
int print_hex(unsigned int num, int letter_case);
void print_x(va_list valist, int *n);
void print_X(va_list valist, int *n);
void print_special(va_list valist, int *n);
void print_p(va_list valist, int *n);
int _printf(const char *format, ...);

#endif /* MAIN_H */
