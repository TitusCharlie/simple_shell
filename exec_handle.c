#include "s_shell.h"

/**
 * handle_exec - Handles possible executable or script
 * @argvec: Vector of arguments
 * @pargv: Vector of argument of current process
 *
 * Return: Void (Nothing)
 */
void handle_exec(char **argvec, char **pargv)
{
	pid_t pid;
	int cstatus;
	char *res_path;

	res_path = resolve_path(argvec[0]);
	if (!res_path)
	{
		perror(pargv[0]);
		/*exec_err(pargv[0], argvec[0]);*/
		return;
	}

	if (fflush(NULL))
		perror("fflush error");

	pid = fork();
	if (pid < 0)
		perror("fork() error");
	else if (pid > 0)
	{
		if (waitpid(pid, &cstatus, 0) < 0)
			perror("waitpid error");
		free(res_path);
	}
	else
	{
		if (execve(res_path, argvec, environ) < 0)
			perror(pargv[0]);
		exit(EXIT_FAILURE);
	}
}


/**
 * resolve_path - Attempts to resolve path before calling execve
 * @path: Path to resolve
 *
 * Return: Resolved path
 * NULL if path is not resolved
 */
char *resolve_path(char *path)
{
	char *progname = path, *pathvar, *freepath, execvar[256];

	if (*progname == '/' || *progname == '.')
	{
		pathvar = malloc(sizeof(*pathvar) * (_strlen(progname) + 1));
		if (!pathvar)
			perror("path malloc error");
		_strcpy(pathvar, progname);

		return (pathvar);
	}
	pathvar = get_env("PATH");
	freepath = pathvar;
	_strtok(pathvar, "=:");

	do {
		if (!_strcpy(execvar, _strtok(NULL, ":")))
			break;
		_strcat(execvar, "/");
		/*printf("%s\n", execvar);*/
		if (!access(_strcat(execvar, progname), F_OK))
		{
			free(freepath);
			pathvar = malloc(sizeof(*pathvar)
					 * (_strlen(execvar) + 1));
			if (!pathvar)
				perror("path malloc error");
			_strcpy(pathvar, execvar);
			return (pathvar);
		}
	} while (1);

	free(freepath);
	return (NULL);
}
