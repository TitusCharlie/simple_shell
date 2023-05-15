#include "s_shell.h"

/**
 * unsetenv_func - unsets the environmentvariable if it exist
 * @argvec: environment variable
 */

void unsetenv_func(char **argvec)
{
	int num = 0;
	char *check_env_name;

	if (argvec[num] == NULL || argvec == NULL){
		perror("Invalid argument\n");
		return;
	}

	while (argvec[num] != NULL){
		check_env_name = get_env(argvec[num]);

	if (check_env_name == NULL){
		perror("No such variable in the environment");
		return;
		}
		num++;
	}

	/*
	while (argvec[num] !=NULL){
		if (unsetenv_func(argvec[num] != 0)){
			perror("Failure: cannot unset variable");
			return;
		}
		num++;
	}
	*/
}
