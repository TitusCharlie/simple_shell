#include "s_shell.h"

/**
 * cd_func - cd command implementation
 * @argvec: Vector of arguments
 *
 * Return: Void (Nothing)
 */
void cd_func(char **argvec)
{
	char *home, **env, res[256], oldpath[256];/*Here*/

	for (env = environ; *env != NULL; env++)
		if (isenv(*env, "HOME"))/*Here*/
		{
			home = *env;
			while (*home != '=')
				home++;
			home++;
		}
	getcwd(res, sizeof(res) - 1);/*Here*/
	getcwd(oldpath, sizeof(oldpath) - 1);/*Here*/
	if (argvec[1])
		cd_arg(argvec[1], res, home);
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

void cd_arg(char *path, char *res, char *home)
{
	char *piter;
	int len;

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
		change_dir(res);
		break;
	case '/':
		change_dir(path);
		break;
	case '-':
		len = _strlen("OLDPWD") + 1;
		path = get_env("OLDPWD");
		piter = path + len;
		if (!path)
			piter = home;
		change_dir(piter);
		print_str(piter);
		print_str("\n");
		if (path)
			free(path);
		break;
	default:
		_strcat(res, "/");
		_strcat(res, path);
		change_dir(res);
		break;
	}
}

void change_dir(char *res)
{
	if (chdir(res) == -1)
		perror(res);
	_setenv("PWD", res, 1);
}
