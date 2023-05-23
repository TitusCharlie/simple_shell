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
 * _putcherr - writes the characer c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropritely.
 */
int _putcherr(char c)
{
	return (write(2, &c, 1));
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

/**
 * print_strerr - Prints a plain string to stderr
 * @str: String to print
 *
 * Return: Length of string
 * -1 if error occurs
 */
int print_strerr(const char *str)
{
	int len = 0;

	if (!str)
		return (-1);

	while (*str)
	{
		if (_putcherr(*str) < 0)
			return (-1);
		len++;
		str++;
	}

	return (len);
}

/**
 * printerr_num - Prints integers
 * @n: integer to print
 *
 * Result: Void (Success)
 */
void printerr_num(int n)
{
	int len, div, cut, val;

	if (n < 0)
	{
		_putcherr('-');
	}
	else if (n == 0)
	{
		_putcherr('0');
		return;
	}

	cut = n;
	len = 0;
	while (cut)
	{
		cut /= 10;
		len++;
	}

	while (len)
	{
		div = _pow(10, len - 1);
		val = n / div;
		if (val < 0)
			val = -val;
		_putcherr('0' + val);

		n = n % div;

		len--;
	}
}
