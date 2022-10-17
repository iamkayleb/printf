#include "main.h"

/**
 * print_special - prints a string and prints the asci code of no-printable
 * characters in hexadecimal
 * @valist: va_list variable
 * @n: numbers of charcters printed to stdout
 *
 * Return: void
 */
void print_special(va_list valist, int *n)
{
	int i, ascii, hex_count;
	char *str;

	str = va_arg(valist, char *);
	for (i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			_putchar('/');
			_putchar('x');
			ascii = str[i];
			hex_count = print_hex(ascii, 0);
			*n += hex_count + 2;
		}
		else
		{
			_putchar(str[i]);
			*n += 1;
		}
	}
}
