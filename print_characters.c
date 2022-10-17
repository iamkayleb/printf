#include "main.h"
#include <stdlib.h>

/**
 * print_char - function prints a character
 * @valist: va_list object
 * @n: number of characters printed to stdout
 *
 * Return: void
 */

void print_char(va_list valist, int *n)
{
	char c = (char)va_arg(valist, int);

	_putchar(c);
	*n += 1;
}

/**
 * print_string - function prints a string
 * @valist: va_list object
 * @n: number of characters printed to stdout
 *
 * Return: void
 */

void print_string(va_list valist, int *n)
{
	int i;
	char *str = va_arg(valist, char *);

	if (str == NULL)
		str = "(nil)";
	for (i = 0; str[i]; i++)
	{
		*n += 1;
		_putchar(str[i]);
	}
}
