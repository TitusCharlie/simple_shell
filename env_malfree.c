#include "s_shell.h"
/*
 * void *env_malloc(int sz, void *pfree)
 * {
 *	void *newptr;
 *
 *	if (pfree)
 *	{
 *		cladd_denv(pfree, 1);
 *	}
 *	newptr = malloc(sz);
 *	if (!newptr)
 *	{
 *		perror("env_malloc error");
 *		return (NULL);
 *	}
 *	if (cladd_denv(newptr, 2) > 0)
 *		return (newptr);
 *	free(newptr);
 *	return (NULL);
 * }
*/

/**
 * cladd_denv - keeps track of memory allocated for env
 * @penv: pointer to add or remove from tracking array
 * @stat: determinant for  addition and removal
 *
 * Return: 1 on success, 0 on failure
 * -1 on error
 */
int cladd_denv(void *penv, int stat)
{
	static void *env_pt[256];
	size_t iter, isize;

	isize = sizeof(env_pt) / sizeof(void *);
	if (!penv)
	{
		if (stat == 3)
		{
			for (iter = 0; iter < isize; iter++)
				if (env_pt[iter])
				{
					free(env_pt[iter]);
					env_pt[iter] = NULL;
				}
			return (1);
		}
		return (-1);
	}

	for (iter = 0; iter < isize; iter++)
	{
		if (env_pt[iter] == penv)
		{
			if (stat < 0 || stat > 1)
				return (-1);
			if (stat == 1)
			{
				free(env_pt[iter]);
				env_pt[iter] = NULL;
			}
			return (1);
		}

		if ((env_pt[iter] == NULL) && (stat == 2))
		{
			env_pt[iter] = penv;
			return (1);
		}
	}
	return (0);
}
/**
 * isenv - checks if the environment variable exists.
 * @haystack: environment variable
 * @needle: key of variable
 *
 * Return: ptr to environment variable if it exists
 * NULL if environment variable does not exist
 */
char *isenv(char *haystack, char *needle)
{
	char *hay = haystack;
	int iter, len = _strlen(needle);

	for (iter = 0; iter < len; iter++)
	{
		if (hay[iter] != needle[iter])
			return (NULL);
	}
	if (hay[len] != '=')
		return (NULL);
	return (hay);
}
