#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * print_char - function prints a character
 * @valist: va_list object
 * @n: number of characters printed to stdout
 *
 * Return: void
 */

void print_char(va_list valist, int *n)
{
	char c = va_arg(valist, int);

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
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		*n += 1;
		_putchar(str[i]);
	}
}

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
	int i, hex_count;
	char *str;

	str = va_arg(valist, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');

			hex_count = hex_print(str[i]);
			*n += hex_count + 2;
		}
		else
		{
			_putchar(str[i]);
			*n += 1;
		}
	}
}

/**
 * print_reverse - prints a string in reverse
 * @valist: va_list variable
 * @n: number of characters printed to the stdout
 *
 * Return: void
 */
void print_reverse(va_list valist, int *n)
{
	int i, len;
	char *str;

	str = va_arg(valist, char *);
	if (str == NULL)
		str = "(null)";
	len = strlen(str);
	for (i = (len - 1); i >= 0; i--)
	{
		_putchar(str[i]);
		*n += 1;
	}
}

/**
 * print_rot13 - prints a string with rot13 encoding format
 * @valist: va_list variable
 * @n: number of characters printed to the stdout
 *
 * Return: void
 */
void print_rot13(va_list valist, int *n)
{
	unsigned int i, j;
	char *alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *match = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *str;

	str = va_arg(valist, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
		{
			for (j = 0; alpha[j]; j++)
			{
				if (str[i] == alpha[j])
				{
					_putchar(match[j]);
				}
			}
		}
		else
			_putchar(str[i]);
		*n += 1;
	}
}
