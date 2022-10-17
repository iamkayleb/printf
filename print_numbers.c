#include "main.h"

/**
 * print_int - prints a signed integer
 * @valist: va_list variable
 * @n: number of characters printed to stdout
 *
 * Return: void
*/
void print_int(va_list valist, int *n)
{
	int num, num_list[10], i, j, sum = 0;

	j = 1000000000; /* 10 ^ 9 */
	num = va_arg(valist, int);
	num_list[0] = num / j;
	for (i = 1; i < 10; i++)
	{
		j /= 10;
		num_list[i] = (num / j) % 10;
	}
	if (num < 0)
	{
		_putchar('-');
		for (i = 0; i < 10; i++)
			num_list[i] *= -1;
		*n += 1;
	}
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
