#include "s_shell.h"

/**
 * _putchar - writes the characer c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropritely.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * print_str - Prints a plain string
 * @str: String to print
 *
 * Return: Length of string
 * -1 if error occurs
 */
int print_str(const char *str)
{
	int len = 0;

	if (!str)
		return (-1);

	while (*str)
	{
		if (_putchar(*str) < 0)
			return (-1);
		len++;
		str++;
	}

	return (len);
}
