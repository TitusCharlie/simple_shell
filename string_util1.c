#include "s_shell.h"
/**
 * _strncpy - Copies a string
 * @dest: Destination of copied string
 * @src: String to copy
 * @n: length of src to consider
 *
 * Return: Returns dest after copy
 */
char *_strncpy(char *dest, char *src, int n)
{
	char *pt = dest;
	int iter = 0;
	int mark = 1;

	while (n)
	{
		if (mark)
			if (src[iter])
			{
				pt[iter] = src[iter];
				iter++;
				n--;
				continue;
			}
		mark = 0;
		pt[iter] = '\0';
		iter++;
		n--;
	}

	return (dest);
}

/**
 * _strchr - Locates a character
 * @s: String to parse
 * @c: Character to find
 *
 * Return: Pointer to first occurence
 */
const char *_strchr(const char *s, char c)
{
	if (!s)
		return (NULL);

	while (*s)
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}
	if (!c)
		return (s);
	return (NULL);
}


/**
 * _strtok - Tokenizes a string
 * @str: String to parse
 * @delim: Set of bytes to use as delimiters
 *
 * Return: Pointer to next token
 */
char *_strtok(char *str, const char *delim)
{
	char *str_stat;
	const char *s;
	int mid_tok = 1;
	static char *next_tok;

	if (str)
	{
		str_stat = str;
		next_tok = str;
	}
	else if (*next_tok)
	{
		str_stat = next_tok;
	}
	else
	{
		return (NULL);
	}

	while (*next_tok)
	{
		s = _strchr(delim, *next_tok);
		if (s)
		{
			mid_tok = 0;
			*next_tok = '\0';
			next_tok++;
			continue;
		}
		if (mid_tok)
		{
			next_tok++;
		}
		else
		{
			break;
		}
	}

	return (str_stat);
}

/**
 * _strdup - Duplicates a string
 * @str: String to duplicate
 *
 * Return: Pointer to new duplicate
 * NULL id insufficient memory was available
 */
char *_strdup(char *str)
{
	int iter;
	int len = 0;
	char *pstr = str;

	if (!str)
		return (NULL);

	while (*pstr)
	{
		len++;
		pstr++;
	}

	pstr = (char *) malloc(sizeof(char) * (len + 1));
	if (!pstr)
		return (NULL);

	for (iter = 0; iter < len; iter++)
		pstr[iter] = str[iter];
	pstr[len] = '\0';

	return (pstr);
}
