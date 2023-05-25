#include "s_shell.h"

/**
 * _getline - Reads line from a file
 * @lineptr: Buffer to put the line into
 * @n: Size of line
 * @fd: File descriptor of file from which to read
 *
 * Return: Number of bytes read
 * -1 if error occurs or EOF is reached
 */
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	static char buff[1024];
	static size_t index, len;
	static ssize_t slen;
	size_t line_len, isfirst = 0;
	char *iter;

	if (len == index)
	{
		_memset(buff, '\0', sizeof(buff));
		slen = read(fd, buff, sizeof(buff) - 1);
		if (slen < 1)
			return (-1);
		len = slen;
		index = 0;
	}
	for (iter = buff + index; (*iter != '\n') && (*iter != '\0'); iter++)
		if (!beg_wh(*iter, &index, isfirst))
			isfirst = 1;
	if (*iter == '\n')
		iter++;
	line_len = iter - (buff + index);
	if (!(*lineptr))
	{
		*lineptr = malloc(sizeof(**lineptr) * line_len + 1);
		if (!(*lineptr))
			return (-1);
		*n = line_len;
	}
	else if ((iter - (buff + index)) > (ssize_t) *n)
	{
		*lineptr = _realloc(*lineptr, *n, line_len + 1);
		if (!(*lineptr))
			return (-1);
		*n = line_len;
	}
	_strncpy(*lineptr, buff + index, line_len);
	*(*lineptr + line_len) = '\0';
	index += line_len;
	return (line_len);
}

/**
 * beg_wh - Removes beginning whitespaces
 * @c: Character under consideration
 * @in: index to modify
 * @isfirst: if the character is at the beginning
 *
 * Return: 1 if character is a beginning whitespace
 * 0 if otherwise
 */
int beg_wh(char c, size_t *in, int isfirst)
{
	if ((c == '\t' || c == ' ') && (!isfirst))
	{
		*in += 1;
		return (1);
	}
	return (0);
}

/**
 * _memset - Fills into memory
 * @s: Pointer to first element
 * @b: Value to fill in
 * @n: Number of elements to fill
 *
 * Return: Filled in memory
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int a;

	for (a = 0; a < n; a++)
	{
		s[a] = b;
	}
	return (s);
}
