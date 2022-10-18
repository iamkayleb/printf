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


/**
 * print_p - prints a memory address
 * @valist: va_list variable
 * @n: number of charactersprinted to the stdout
 *
 * Return: void
 */
void print_p(va_list valist, int *n)
{
	unsigned int i, sum, num_list[16];
	unsigned long j, num;
	char *str = "(null)";

	num = va_arg(valist, unsigned long);
	if (num == 0)
	{
		for (i = 0; str[i]; i++)
		{
			_putchar(str[i]);
			*n += 1;
		}
		return;
	}
	j = _pow(16, 15); /* 16 ^ 15 */
	num_list[0] = num / j;
	for (i = 1; i < 16; i++)
	{
		j /= 16;
		num_list[i] = (num / j) % 16;
	}
	_putchar('0');
	_putchar('x');
	*n += 2;
	for (i = 0; i < 16; i++)
	{
		sum += num_list[i];
		if (sum != 0 || i == 15)
		{
			if (num_list[i] > 10)
				_putchar(num_list[i] + '0');
			else
				_putchar(num_list[i] + ('a' - ':') + '0');
			*n += 1;
		}
	}
}
