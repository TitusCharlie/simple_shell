#include "s_shell.h"

/**
 * exec_err - Prints error message when executable is not found
 * @prog: Program name
 * @com: Command name
 *
 * Return: Void (Nothing)
 */
void exec_err(char *prog, char *com)
{
	print_strerr(prog);
	print_strerr(": ");
	printerr_num(com_number(0));
	fflush(NULL);
	print_strerr(": ");
	print_strerr(com);
	print_strerr(": ");
	print_strerr("not found\n");
}

/**
 * exit_err - Prints error message when executable is not found
 * @prog: Program name
 * @com: Command name
 *
 * Return: Void (Nothing)
 */
void exit_err(char *prog, char **com)
{
	print_strerr(prog);
	print_strerr(": ");
	printerr_num(com_number(0));
	fflush(NULL);
	print_strerr(": ");
	print_strerr(com[0]);
	print_strerr(": ");
	print_strerr("Illegal number");
	print_strerr(": ");
	print_strerr(com[1]);
	print_strerr("\n");
}
