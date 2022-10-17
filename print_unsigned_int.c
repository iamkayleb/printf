#include "main.h"

/**
 * print_binary - prints a number in binary
 * @valist: va_list variable
 * @n: number of characters printed to the stdout
 *
 * Return: void
 */
void print_binary(va_list valist, int *n)
{
	unsigned int num, i, num_list[32], m, sum;

	m = 2147483648; /* 2 ^ 31 */
	num = va_arg(valist, int);
	num_list[0] = num / m;
	for (i = 1; i < 32; i++)
	{
		if (m == 0)
			break;
		m /= 2;
		num_list[i] = (num / m) % 2;
	}

	for (i = 0, sum = 0; i < 32; i++)
	{
		sum += num_list[i];
		if (sum != 0 || i == 31)
		{
			_putchar(num_list[i] + '0');
			*n += 1;
		}
	}
}

/**
 * print_decimal - prints unsigned decimal
 * @valist: va_list variable
 * @n: number of characters printed to the stdout
 *
 * Return: void
 */
void print_decimal(va_list valist, int *n)
{
	unsigned int i, num, num_list[10], sum, j;

	j = 1000000000;
	num = va_arg(valist, int);
	num_list[0] = num / j;
	for (i = 1; i < 10; i++)
	{
		j /= 10;
		num_list[i] = (num / j) % 10;
	}
	sum = 0;
	for (i = 0; i < 10; i++)
	{
		sum += num_list[i];
		if (sum != 0 || i == 9)
		{
			_putchar(num_list[i] + '0');
			*n += 1;
		}
	}
}

/**
 * print_octal - prints unsigned int in octal notation
 * @valist: va_list variable
 * @n: number of characters printed to stdout
 *
 * Return: void
 */
void print_octal(va_list valist, int *n)
{
	unsigned int i, num, num_list[11], j, sum;

	j = 1073741824; /* 8 ^ 10 */
	num = va_arg(valist, int);
	num_list[0] = num / j;
	for (i = 1; i < 11; i++)
	{
		j /= 8;
		num_list[i] = (num / j) % 8;
	}
	sum = 0;
	for (i = 0; i < 11; i++)
	{
		sum += num_list[i];
		if (sum != 0 || i == 10)
		{
			_putchar(num_list[i] + '0');
			*n += 1;
		}
	}
}

/**
 * print_hex - prints an unsigned int in hexadecimal
 * @n: number to print in hexadecimal
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
			_putchar(num_list[i] + diff + '0');
			count++;
		}
	}
	return (count);
}

/**
 * print_x - prints unsigned int in lowercase hexadecimal
 * @valist: va_list variable
 * @n: number of charcter printed to the stdout
 *
 * Return: void
 */
void print_x(va_list valist, int *n)
{
	int count;

	count = print_hex((va_arg(valist, int)), 0);
	*n += count;
}

/**
 * print_X - prints unsigned int in uppercase hexadecimal
 * @valist: va_list variable
 * @n: number of characters printed to the stdout
 *
 * Return: void
 */
void print_X(va_list, int *n)
{
	int count;

	count = print_hex((va_arg(valist, int)), 1);
	*n += count;
}














