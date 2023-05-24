#include "s_shell.h"

/**
 * unsetenv_func - unsets the environmentvariable if it exist
 * @argvec: environment variable
 *
 * Return: Void (Nothing)
 */
void unsetenv_func(char **argvec)
{
	int num = 0;
	char *check_env, **env, *name;

	if (argvec[1] == NULL)
	{
		print_strerr("unsetenv: variable required\n");
		return;
	}

	name = argvec[1];
	check_env = get_env(name);
	if (!check_env)
	{
		print_str("unsetenv: ");
		print_str(name);
		print_str(" not found");
		return;
	}

	for (env = environ; *env != NULL; env++)
	{
		if (num)
		{
			*(env - 1) = *env;
		}
		if (_strstr(*env, name))
		{
			num = 1;
			cladd_denv(*env, 1);
		}
	}
	*(env - 1) = NULL;
	free(check_env);
}
