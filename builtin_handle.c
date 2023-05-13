#include "s_shell.h"

/**
 * is_builtin - Evaluates whether string is builtin command or not
 * @str: String to evaluate
 *
 * Return: 1 if string is builtin command
 * 0 if string is not builtin
 */
int is_builtin(char *str)
{
	char **builtin_com = get_builtin_commands(), **builtin_copy;

	for (builtin_copy = builtin_com;
	     *builtin_copy != NULL; builtin_copy++)
	{
		if (!_strcmp(str, *builtin_copy))
		{
			free_p2p2c(builtin_com);
			return ((builtin_copy - builtin_com) + 1);
		}
	}
	free_p2p2c(builtin_com);
	return (0);
}

/**
 * handle_builtin - Handles builtin commands
 * @argvec: Vector of arguments
 * @index: Command index corresponding to handling function
 *
 * Return: Void (Nothing)
 */
void handle_builtin(char **argvec, size_t index)
{
	builtin_f com_struct[] = {{"exit", NULL}, {"env", env_func},
				  {"cd", cd_func}, {"setenv", setenv_func}
	};

	com_struct[index].func(argvec);
}

/**
 * get_builtin_commands - Gets all built-in commands available for the shell
 *
 * Return: List of strings
 */
char **get_builtin_commands()
{
	size_t comlen, iter;
	char **pptr;

	char *builtin_commands[] = {
		"exit", "env", "cd", "setenv", NULL
	};

	comlen = sizeof(builtin_commands);
	pptr = malloc(comlen);
	if (!pptr)
		perror("Malloc error for built-in commands");

	for (iter = 0; iter < (comlen / sizeof(char *)); iter++)
	{
		if (builtin_commands[iter])
		{
			pptr[iter] = strdup(builtin_commands[iter]);
			if (!pptr[iter])
				perror("strdup error");
		}
		else
			pptr[iter] = NULL;
	}

	return (pptr);
}
