#include "s_shell.h"

/**
 * setenv_func - creates new environment variable or updates if present already
 * @argvec: environment variable
 */

void setenv_func(char **argvec)
{
	/*
	char *env_name;
	int overwrite;
	char *check_env_name;
	*/
/*check if argvec[0] or argvec[1] is NULL*/
	if (argvec[1] == NULL || argvec[2] == NULL){
		print_str("Invalid argument\n");
		return;
	}

	_setenv(argvec[1], argvec[2], 1);
	/*check if env_name already exist*/
/*	check_env_name = get_env(argvec[0]);
	if (check_env_name != NULL){
		printf("%s already exist\n", argvec[0]);
		return;
	}

	pairing keys and values
	overwrite = snprintf(NULL,0, "%s=%s", argvec[0], argvec[1]);

	env_name = (char*)malloc(overwrite + 1);
	snprintf(env_name, overwrite + 1, "%s=%s", argvec[0], argvec[1]);

	if the env_name does not exist, add the environment variable
	if (putenv(env_name) != 0){
		printf("Failure: can't set %s", argvec[0]);
		free (env_name);
		return;
	}

	printf("%s is set to %s", argvec[0], argvec[1]);
	*/
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
	char **env, **envcopy = NULL;
	int len;

	if (!name)
		return (-1);
	keyval = get_env(name);

	if (!overwrite)
	{
		if (keyval)
		{
			return (1);
			free(keyval);
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
		if (keyval)
		{
			if (!_strcmp(keyval, siter))
			{
				free(siter);
				return (1);
			}
			for (env = environ; *env != NULL; env++)
				if (_strstr(*env, name))
					break;
			cladd_denv(*env, 1);
			cladd_denv(siter, 2);
			*env = siter;
			free(keyval);
			return (1);
		}
		envcopy = envcpy(envcopy);
		cladd_denv(NULL, 3);
		cladd_denv(envcopy, 2);
		environ = envcopy;
		for (env = envcopy; *env != NULL; env++)
			cladd_denv(*env, 2);
		*env = siter;
		cladd_denv(*env, 2);

		return (1);
	}
	return (0);
}


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
