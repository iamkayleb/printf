#include "main.h"

/**
 * _pow - raises a number to the power of another number
 * @a: base value
 * @b: the power of the base value
 *
 * Return: a to the power of b
 */
unsigned long _pow(unsigned int a, unsigned int b)
{
	if (b == 0)
		return (1);
	return (a * _pow(a, (b - 1)));
}
