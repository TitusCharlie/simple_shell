#include "s_shell.h"

/**
 * _atoi - Converts string to integer
 * @s: String to convert
 *
 * Return: resulting integer
 */
int _atoi(char *s)
{
	int iter = 0;

	while (s[iter])
	{
		if ((s[iter] >= '0') && (s[iter] <= '9'))
			return (evalInt(s, s + iter));
		iter++;
	}
	return (0);
}

/**
 * p_exit_status - Processes the exit status
 * @s: Given exit status
 *
 * Return: Resulting integer
 */
int p_exit_status(char *prog, char **argvec)
{
	char *piter;

	for (piter = argvec[1]; *piter != '\0'; piter++)
		if (*piter < '0' || *piter > '9')
		{
			exit_err(prog, argvec);
			return (-1);
		}
	return (_atoi(argvec[1]));
}


/**
 * evalInt - Evaluate the Integer
 * @s: Original string
 * @charInt: starting point of the Integer
 *
 * Return: Evaluated integer.
 */
int evalInt(char *s, char *charInt)
{
	int siter, sign_val;
	int iter = 0;
	int val = 0;

	sign_val = 0;
		for (siter = 0; siter < (charInt - s); siter++)
	{
		if (s[siter] == '-')
			sign_val++;
	}

	while ((charInt[iter] >= '0') && (charInt[iter] <= '9'))
	{
		val *= 10;

		if (sign_val % 2 == 0)
			val += (charInt[iter] - '0');
		else
			val -= (charInt[iter] - '0');
		iter++;
	}

	return (val);
}


/**
 * print_num - Prints integers
 * @n: integer to print
 *
 * Result: Void (Success)
 */
void print_num(int n)
{
	int len, div, cut, val;

	if (n < 0)
	{
		_putchar('-');
	}
	else if (n == 0)
	{
		_putchar ('0');
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
		_putchar('0' + val);

		n = n % div;

		len--;
	}
}


/**
 *_pow - Evaluates an exponent
 * @base: the base
 * @exp: the exponent
 *
 * Return: the evaluated power
 */
int _pow(int base, int exp)
{
	int p = 1;

	while (exp)
	{
		p *= base;
		exp--;
	}
	return (p);
}
