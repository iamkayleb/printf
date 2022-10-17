#include "main.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	char *c = "Caleb", z = 'z';
	int i, j, n = 98;

	i = _printf("Hello %i%s%c%%%b\n", n, c, z, n);
	j = printf("Hello %i%s%c%%\n", n, c, z);
	printf("%d == %d\n", i, j);
	_printf("%d == %d\n", i, j);
	return (0);
}
