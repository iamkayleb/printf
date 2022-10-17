#include "main.h"
/**
 * hex_print - prints characters ascii value in hexadecimal
 * @c: character to print
 *
 * Return: the number of characters printed
 */
int hex_print(char c)
{
	int count;
	char diff = 'A' - ':';
	char num_list[2];

	num_list[0] = c / 16;
	num_list[1] = c % 16;
	for (count = 0; count < 2; count++)
	{
		if (num_list[count] >= 10)
			_putchar('0' + diff + num_list[count]);
		else
			_putchar('0' + num_list[count]);
	}
	return (count);
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
