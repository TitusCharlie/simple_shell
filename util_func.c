#include "s_shell.h"

/**
 * free_p2p2c - Frees a null terminated array of pointers to strings
 * @pptr: Null terminated array of pointers
 *
 * Return: Void (Nothing)
 */
void free_p2p2c(char **pptr)
{
	char **iter;

	for (iter = pptr; *iter != NULL; iter++)
		free(*iter);
	free(pptr);
}

/**
 * p_exit - freeing line pointer before exit
 * @argline: Line pointer
 * @estat: Exit status
 *
 * Return: Void (Nothing)
 */
void p_exit(char *argline, int estat)
{
	if (estat == -1)
		return;
	cladd_denv(NULL, 3);
	free(argline);
	argline = NULL;
	exit(estat);
}

/**
 * get_env - Get the PATH string from environment list
 * @key: The key to the environment variable
 *
 * Return: Path string (malloced)
 */
char *get_env(char *key)
{
	char *pathvar, **env;

	for (env = environ; *env != NULL; env++)
	{
		pathvar = isenv(*env, key);
		if (pathvar)
		{
			pathvar = malloc(sizeof(*pathvar)
					 * (_strlen(*env) + 1));
			if (!pathvar)
				perror("exec malloc error");
			_strcpy(pathvar, *env);
			break;
		}
	}
	return (pathvar);
}

/**
 * prompt - Print prompt in interactive mode
 * @pmt: Prompt to print
 *
 * Return: Void
 */
void prompt(char *pmt)
{
	if (isatty(STDIN_FILENO))
		print_str(pmt);
}

/**
 * _realloc - Reallocate memory block
 * @ptr: Pointer to previouslly allocated memory
 * @old_size: Size allocated to ptr
 * @new_size: New of new memory block
 *
 * Return: Pointer to resolved memory
 * NULL if new_size is 0
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *newptr, *oldptr = ptr;
	unsigned int iter;

	if (new_size == old_size)
		return (ptr);
	if (!new_size)
	{
		if (ptr)
			free(oldptr);
		return (NULL);
	}
	if (ptr)
	{
		if (new_size < old_size)
		{
			free(oldptr + new_size);
			return (ptr);
		}
		else
		{
			newptr = malloc(new_size);
			if (!newptr)
				return (NULL);
			for (iter = 0; iter < old_size; iter++)
				newptr[iter] = oldptr[iter];
			free(ptr);
			return (newptr);
		}
	}
	else
	{
		if (new_size)
		{
			newptr = malloc(new_size);
			if (!newptr)
				return (NULL);
			return (newptr);
		}
		return (NULL);
	}
}
