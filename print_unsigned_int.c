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
