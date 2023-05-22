#include "s_shell.h"

/**
 * cd_func - cd command implementation
 * @argvec: Vector of arguments
 *
 * Return: Void (Nothing)
 */
void cd_func(char **argvec)
{
	char *home, *path = argvec[1], **env, res[256], *oldpath, *piter;
	int len;

	for (env = environ; *env != NULL; env++)
		if (_strstr(*env, "HOME="))
		{
			home = *env;
			while (*home != '=')
				home++;
			home++;
		}
	oldpath = getcwd(res, sizeof(res) - 1);
	if (!oldpath)
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
			_setenv("PWD", res, 1);
			break;
		case '/':
			if (chdir(path) == -1)
				perror(path);
			_setenv("PWD", path, 1);
			break;
		case '-':
			len = _strlen("OLDPWD") + 1;
			path = get_env("OLDPWD");
			piter = path + len;
			if (!path)
				piter = home;
			if (chdir(piter) == -1)
				perror(piter);
			_setenv("PWD", piter, 1);
			print_str(piter);
			print_str("\n");
			if (path)
				free(path);
			break;
		default:
			_strcat(res, "/");
			_strcat(res, path);
			if (chdir(res) == -1)
				perror(res);
			_setenv("PWD", res, 1);
			break;
		}
	else
	{
		if (chdir(home) == -1)
			perror(res);
		_setenv("PWD", home, 1);
	}
	_setenv("OLDPWD", oldpath, 1);
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
