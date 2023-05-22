#include "s_shell.h"

/**
 * main - Starting point of program
 * @argc: Number of process arguments
 * @argv: Argument vector of current process
 *
 * Return: EXIT_SUCCESS on success
 * EXIT_FAILURE when error occurs
 */
int main(__attribute__((unused)) int argc, char *argv[])
{
	char *argline = NULL, *argvec[ARG_VECTOR_SIZE];
	size_t arglen = 0, vec_iter = 0;
	char *delim = " \t\n";

	while (1)
	{
		prompt("titus&tunde$ ");
		if (_getline(&argline, &arglen, STDIN_FILENO) == -1)
		{
			prompt("\n");
			p_exit(argline, EXIT_SUCCESS);
		}
		argvec[0] = _strtok(argline, delim);
		for (vec_iter = 1; argvec[vec_iter - 1] != NULL; vec_iter++)
			argvec[vec_iter] = _strtok(NULL, delim);
		if (argvec[0] == NULL)
		{
			free(argline);
			argline = NULL;
			arglen = 0;
			continue;
		}

		builtin_or_exec(argvec, argline, argv);

		free(argline);
		argline = NULL;
		arglen = 0;
	}
	return (0);
}

/**
 * builtin_or_exec - Determines whether command is builtin or external
 * @argvec: Vector of tokens
 * @argline: Argument line
 * @argv: Vector of program arguments
 *
 * Return: Void (Nothing)
 */
void builtin_or_exec(char **argvec, char *argline, char **argv)
{
	size_t com_index;

	com_number(1);
	com_index = is_builtin(argvec[0]);
	if (com_index)
	{
		if (com_index == 1)
		{
			if (!argvec[1])
				p_exit(argline, EXIT_SUCCESS);
			p_exit(argline, p_exit_status(argv[0], argvec));
			return;
		}
		handle_builtin(argvec, com_index - 1);
	}
	else
		handle_exec(argvec, argv);

}

/**
 * com_number - Counts the total number of commands entered
 * @a: Set if new command is entered
 *
 * Return: Total number of commands entered
 */
int com_number(int a)
{
	static int cnt;
	int nstat;

	cnt += a;
	nstat = cnt;

	return (nstat);
}
