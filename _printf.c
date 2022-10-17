#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * check_spec - checks string for specifier
 * @format: string to be checked
 *
 * Return: string containing a specifier
 */
char *check_spec(const char *format)
{
	int i, j;
	char *specs;

	i = j = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%')
			j++;
		i++;
	}
	j += 1;
	specs = (char *)malloc(sizeof(char) * (j));
	if (specs == NULL)
		return (NULL);
	i = j = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			specs[j] = format[i + 1];
			i += 2;
			j++;
		}
		else
			i++;
	}
	specs[j + 1] = '\0';
	return (specs);
}

/**
 * get_specifier - locates the function associated with a specifier
 * @c: specifier to be located
 *
 * Return: a pointer to associated function or NULL
 */
void (*get_specifier(char c))(va_list, int *)
{
	int j;
	spec_t con_spec[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_int},
		{'i', print_int},
		{'b', print_binary},
		{'\0', NULL}
	};

	j = 0;
	while (con_spec[j].fmt)
	{
		if (c == con_spec[j].fmt)
			return (con_spec[j].func);
		j++;
	}

	return (NULL);
}

/**
 * _printf - prints a formatted string
 * @format: string to be printed
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, n;
	void (*op_func)(va_list, int *);
	va_list args;

	if (format == NULL)
		return (-1);
	i = n = 0;
	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			op_func = get_specifier(format[i + 1]);
			if (op_func)
				op_func(args, &n);
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			_putchar('%');
			i += 2;
			*n += 1;
		}
		else
		{
			_putchar(format[i]);
			i++;
			n++;
		}
	}
	return (n);
}
