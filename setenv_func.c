#include "s_shell.h"

/**
 * setenv_func - creates new environment variable or update the the variable if present already
 * @argvec: environment variable
 */

void setenv_func(char **argvec)
{
	char *env_name;
	int overwrite;
	char *check_env_name;

	/*check if argvec[0] or argvec[1] is NULL*/
	if (argvec[0] == NULL || argvec[1] == NULL){
		perror("Invalid argument");
		return;
	}

	/*check if env_name already exist*/
	check_env_name = getenv(argvec[0]);
	if (check_env_name != NULL){
		printf("%s already exist\n", argvec[0]);
		return;
	}

	/*pairing keys and values*/
	overwrite = snprintf(NULL,0, "%s=%s", argvec[0], argvec[1]);

	env_name = (char*)malloc(overwrite + 1);
	snprintf(env_name, overwrite + 1, "%s=%s", argvec[0], argvec[1]);

	/*if the env_name does not exist, add the environment variable*/
	if (putenv(env_name) != 0){
		printf("Failure: can't set %s", argvec[0]);
		free (env_name);
		return;
	}

	printf("%s is set to %s", argvec[0], argvec[1]);
}
