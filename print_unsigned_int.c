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
		if (sum > 0)
		{
			_putchar(num_list[i] + '0');
			*n += 1;
		}
	}
}
