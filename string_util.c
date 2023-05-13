#include "s_shell.h"

/**
 * _strstr - Locates a substring
 * @haystack: String containing possible substring
 * @needle: Possible substring to find
 *
 * Return: Location of substring when found,
 * 0 if not found.
 */
char *_strstr(char *haystack, char *needle)
{
	int a;
	char *pt;
	char *hay;

	if (!haystack)
		return (NULL);

	if (!(*needle))
		return (haystack);

	while (*haystack)
	{
		if (*haystack == *needle)
		{
			pt = needle;
			hay = haystack;
			while (*pt)
			{
				if (*pt != *haystack)
				{
					a = 0;
					haystack--;
					break;
				}
				a = 1;
				pt++;
				haystack++;
			}
			if (a)
				return (hay);
			hay = 0;
		}
		haystack++;
	}
	return (NULL);
}

/**
 * _strcpy - Copies string
 * @dest: Destination of copied string
 * @src: Source to be copied from
 *
 * Return: Pointer to dest.
 */
char *_strcpy(char *dest, char *src)
{
	int iter = 0;

	if (!src)
		return (NULL);

	while (src[iter])
	{
		dest[iter] = src[iter];
		iter++;
	}
	dest[iter] = 0;

	return (dest);
}

/**
 * _strcat - Concatenates two strings
 * @dest: First string
 * @src: Second string
 *
 * Return: Returns dest after concatenation
 */
char *_strcat(char *dest, char *src)
{
	char *pt = dest;
	int iter = 0;

	while (*pt)
		pt++;

	while (src[iter])
	{
		pt[iter] = src[iter];
		iter++;
	}
	pt[iter] = '\0';
	return (dest);
}

/**
 * _strlen - Evaluates length of string
 * @s: String to evaluate on
 *
 * Return: Length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;

	return (len);
}

/**
 * _strcmp - Compares two strings
 * @s1: String 1
 * @s2: String 2
 *
 * Return: The difference between s1 and s2. 0 if equal
 */
int _strcmp(char *s1, char *s2)
{
	int dif;

	while (*s1)
	{
		dif = *s1 - *s2;
		if (!dif)
		{
			s1++;
			s2++;
			continue;
		}
		return (dif);
	}

	if (*s2)
		return (-(*s2));
	return (0);
}
