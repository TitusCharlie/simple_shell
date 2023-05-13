#include "s_shell.h"

/**
 * cd_func - cd command implementation
 * @argvec: Vector of arguments
 *
 * Return: Void (Nothing)
 */
void cd_func(char **argvec)
{
	char *home, *path = argvec[1], **env, res[256];

	for (env = environ; *env != NULL; env++)
		if (_strstr(*env, "HOME="))
		{
			home = *env;
			while (*home != '=')
				home++;
			home++;
		}
	if (!getcwd(res, sizeof(res) - 1))
		perror("getcwd error");
	if (path)
		switch (*path)
		{
		case '.':
			if (*(path + 1) == '.')
			{
				clear_bckw(res, '/');
				_strcat(res, path + 2);
			}
			else
				_strcat(res, path + 1);
			if (chdir(res) == -1)
				perror(res);
			break;
		case '/':
			if (chdir(path) == -1)
				perror(path);
			break;
		default:
			_strcat(res, "/");
			_strcat(res, path);
			if (chdir(path) == -1)
				perror(res);
			break;
		}
	else
		if (chdir(home) == -1)
			perror(res);
}

/**
 * clear_bckw - Clears a string backwards until character specified by lim
 * @ptr: String to work on
 * @lim: character marking the limit
 *
 * Return: Void (Nothing)
 */
void clear_bckw(char *ptr, char lim)
{
	while (*ptr)
		ptr++;
	while (*ptr != lim)
	{
		*ptr = '\0';
		ptr--;
	}
	*ptr = '\0';
}
