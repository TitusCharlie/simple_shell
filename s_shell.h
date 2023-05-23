#ifndef S_SHELL_H
#define S_SHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define ARG_SIZE 256
#define ARG_VECTOR_SIZE 256

extern char **environ;

/**
 * struct builtin_func - Struct containing function for built-in command
 * @name: Name of built-in command
 * @func: Function for command
 *
 * Description: Command name
 * and corresponding function
 */
struct builtin_func
{
	char *name;
	void (*func)(char **);
};

/**
 * builtin_f - typedef for struct builtin_func
 */
typedef struct builtin_func builtin_f;

ssize_t _getline(char **, size_t *, int);

void prompt(char *);

int com_number(int);

int is_builtin(char *);

void builtin_or_exec(char **, char *, char **);

char **get_builtin_commands();

void handle_builtin(char **, size_t);

void handle_exec(char **, char **);

void free_p2p2c(char **);

void *_realloc(void *, unsigned int, unsigned int);

char *_memset(char *, char, unsigned int);

void p_exit(char *, int);

char *resolve_path(char *);

char *_strstr(char *, char *);

char *_strcpy(char *, char *);

char *_strncpy(char *, char *, int);

char *_strcat(char *, char *);

int _strcmp(char *, char *);

char *_strdup(char *);

char *get_env(char *);

char *isenv(char *, char *);

int _setenv(char *, char *, int);

int cladd_denv(void *, int);

void place_env(char *, char *, char *);

int _strlen(char *);

const char *_strchr(const char *, char);

char *_strtok(char *, const char *);

int _putchar(char);

int print_str(const char *);

void env_func(char **);

char **envcpy(char **);

void setenv_func(char **);

void place_env(char *, char *, char *);

void unsetenv_func(char **);

int _atoi(char *);

int evalInt(char *, char *);

void print_num(int);

int _pow(int, int);

void cd_func(char **);

void cd_arg(char *, char *, char *);

void change_dir(char *);

void clear_bckw(char *, char);

int p_exit_status(char *, char **);

int _putcherr(char);

void printerr_num(int);

int print_strerr(const char *);

void exec_err(char *, char *);

void exit_err(char *, char **);

#endif /* S_SHELL_H */
