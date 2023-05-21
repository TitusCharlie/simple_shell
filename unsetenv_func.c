#include "s_shell.h"

/**
 * unsetenv_func - unsets the environmentvariable if it exist
 * @argvec: environment variable
 */

void unsetenv_func(char **argvec)
{
	int num = 0;
	char *check_env, **env, *name;

	if (argvec[1] == NULL){
		print_str("unsetenv: variable required\n");
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
	/*
	while (argvec[num] != NULL){
		check_env_name = get_env(argvec[num]);

	if (check_env_name == NULL){
		perror("No such variable in the environment");
		return;
		}
		num++;
	}

	while (argvec[num] !=NULL){
		if (unsetenv_func(argvec[num] != 0)){
			perror("Failure: cannot unset variable");
			return;
		}
		num++;
	}
	*/
}
