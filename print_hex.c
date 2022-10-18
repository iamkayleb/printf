#include "main.h"
#include <stdio.h>

/**
 * print_hex - prints an unsigned int in hexadecimal
 * @num: number to print in hexadecimal
 * @letter_case: case of the alpha characters
 *
 * Return: void
 */
int print_hex(unsigned int num, int letter_case)
{
	unsigned int i, num_list[8], j, sum;
	int count;
	char diff;

	j = 268435456; /* 16 ^ 7 */
	num_list[0] = num / j;
	for (i = 1; i < 8; i++)
	{
		j /= 16;
		num_list[i] = (num / j) % 16;
	}
	if (letter_case)
		diff = 'A' - ':';
	else
		diff = 'a' - ':';
	sum = count = 0;
	for (i = 0; i < 8; i++)
	{
		sum += num_list[i];
		if (sum != 0 || i == 7)
		{
			if (num_list[i] < 10)
				_putchar(num_list[i] + '0');
			else
				_putchar(num_list[i] + diff + '0');
			count++;
		}
	}
	return (count);
}

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
 * print_p - prints a memory address
 * @valist: va_list variable
 * @n: number of charactersprinted to the stdout
 *
 * Return: void
 */
void print_p(va_list valist, int *n)
{
	unsigned int i, sum, num_list[16];
	unsigned long int num = va_arg(valist, unsigned long), j;
	char *str = "(null)";

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
	_putchar('0');
	_putchar('x');
	*n += 2;
	num_list[0] = num / j;
	for (i = 1; i < 16; i++)
	{
		j /= 16;
		num_list[i] = (num / j) % 16;
	}
	sum = 0;
	for (i = 0; i < 16; i++)
	{
		sum += num_list[i];
		if (sum != 0 || i == 15)
		{
			if (num_list[i] < 10)
				_putchar(num_list[i] + '0');
			else
				_putchar(num_list[i] + ('a' - ':') + '0');
			*n += 1;
		}
	}
}
