#include "s_shell.h"

/**
 * setenv_func - creates new environment variable or updates if present already
 * @argvec: environment variable
 */

void setenv_func(char **argvec)
{
/*check if argvec[0] or argvec[1] is NULL*/
	if (argvec[1] == NULL || argvec[2] == NULL)
	{
		print_str("Invalid argument\n");
		return;
	}

	_setenv(argvec[1], argvec[2], 1);
}

/**
 * _setenv - Sets a variable name to the environment with value
 * @name: The name of variable
 * @value: The value of the variable
 * @overwrite: To determine whether to overwrite or not
 *
 * Return: 1 on success, -1 on error.
 */
int _setenv(char *name, char *value, int overwrite)
{
	char *keyval, *siter;
	int len;

	if (!name)
		return (-1);
	keyval = get_env(name);

	if (!overwrite)
	{
		if (keyval)
		{
			free(keyval);
			return (1);
		}
		return (-1);
	}
	else if (overwrite == 1)
	{
		len = _strlen(name) + _strlen(value) + 2;
		siter = malloc(sizeof(*siter) * len);
		if (!siter)
		{
			perror("malloc error");
			return (-1);
		}
		_strcpy(siter, name);
		_strcat(siter, "=");
		_strcat(siter, value);
		place_env(name, keyval, siter);

		return (1);
	}
	return (0);
}

/**
 * envcpy - Copies the environ variable using malloc
 * @dest: Variable that holds the space for copying env
 *
 * Return: Pointer to copied environ
 */
char **envcpy(char **dest)
{
	int size = 0, iter;
	char **ppiter;

	for (ppiter = environ; *ppiter != NULL; ppiter++)
		size++;
	dest = malloc(sizeof(*dest) * (size + 2));

	ppiter = environ;
	for (iter = 0; iter < (size + 2); iter++)
	{
		if (iter < size)
		{
			dest[iter] = _strdup(ppiter[iter]);
			if (!dest[iter])
				perror("_strdup error");
		}
		else
			dest[iter] = NULL;
	}

	return (dest);
}

/**
 * place_env - Implements the logic of adding to environ
 */
void place_env(char *key, char *keyval, char *newval)
{
	char *siter = newval;
	char **env, **envcopy = NULL;

	if (keyval)
	{
		if (!_strcmp(keyval, siter))
		{
			free(siter);
			free(keyval);
			return;
		}
		for (env = environ; *env != NULL; env++)
			if (isenv(*env, key))/*Here*/
				break;
		cladd_denv(*env, 1);
		cladd_denv(siter, 2);
		*env = siter;
		free(keyval);
		return;
	}
	envcopy = envcpy(envcopy);
	cladd_denv(NULL, 3);
	cladd_denv(envcopy, 2);
	environ = envcopy;
	for (env = envcopy; *env != NULL; env++)
		cladd_denv(*env, 2);
	*env = siter;
	cladd_denv(*env, 2);
}
