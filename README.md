Below are the prototypes, the structure, MACROS, and the global resource we employed to solving the simple shell project

inclusion are
<stdlib.h>
<unistd.h>
<stdio.h>
<string.h>
<sys/types.h>
<sys/wait.h>

MACRO definitions are

ARG_SIZE 256
ARG_VECTOR_SIZE 256

global resource is

extern char **environ;

Structure containing function for built-in command
struct builtin_func
{
	char *name;
	void (*func)(char **);
};

The prototypes we employed are:

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
int _setenv(char *, char *, int);
int cladd_denv(void *, int);
int _strlen(char *);
const char *_strchr(const char *, char);
char *_strtok(char *, const char *);
int _putchar(char);
int print_str(const char *);
void env_func(char **);
char **envcpy(char **);
void setenv_func(char **);
void unsetenv_func(char **);
int _atoi(char *);
int evalInt(char *, char *);
void print_num(int);
int _pow(int, int);
void cd_func(char **);
void clear_bckw(char *, char);
int p_exit_status(char *, char **);
int _putcherr(char);
void printerr_num(int);
int print_strerr(const char *);
void exec_err(char *, char *);
void exit_err(char *, char **);


Few things you need to know about our simple shell

-The simple shell works both in interractive and non-interractive mode
- It is more optimized than the bash shell
- Memory leaks are controlled extensively
- most bultin functions are custom functions created by us
- Errors are controlled and print to STANDARD ERROR as required

The list in inexhaustive as more on the simpleshell will go in much later for better usage 
