#include "s_shell.h"

/**
 * env_func - Prints current environment
 * @argvec: Vector of arguments
 *
 * Return: Void (Nothing)
 */
void env_func(__attribute__((unused)) char **argvec)
{
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		print_str(*env);
		_putchar('\n');
	}
}
