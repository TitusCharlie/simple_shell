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
	print_str(prog);
	print_str(": ");
	print_num(com_number(0));
	fflush(NULL);
	print_str(": ");
	print_str(com);
	print_str(": ");
	print_str("not found\n");
}
