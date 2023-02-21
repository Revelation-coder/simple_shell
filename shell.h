#ifndef _SHELL_H_
#define _SHELL_H_

#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "lists.h"
#include "shellvariables.h"

#define SPACE " "
#define EQUAL "="
#define COLON ":"
#define BSLASH "\\"
#define FSLASH "/"
#define BUF_SIZE 4096
#define PS1 write(STDOUT_FILENO, "MANDALORIAN$ ", 4)
#define PS2 write(STDOUT_FILENO, "\nMANDALORIAN$ ", 5)
#define NEWLINE write(STDOUT_FILENO, "\n", 1)
#define DELIM " \t"
#define LOGFILE ".simple_shell_history"
#define MAXLOGSIZE 4096
#define MAXBUFREAD 1024
#define MAXNUMLEN 1024
#define BYTE 255
#define BUF_SIZE 4096



/* mygetline.c */
ssize_t _getline(char **lineptr, size_t *n, int fd, list_t **mt);

/* log.c */
int add_log(sev_t *sev);
int write_log(sev_t *sev);
int get_log_count(sev_t *sev);

/**
 * struct builtin - struct contain func name
 * @funcname: name of func
 * @func: func to be called when name is invoked
 *
 * Description: struct of func name and its respective func
 */
typedef struct builtin
{
char *funcname;
void (*func)(sev_t *);
} built_t;

/* builtin1.c */
void exit_sh(sev_t *sev);
void _printenv(sev_t *sev);
void _setenv(sev_t *sev);
void _unsetenv(sev_t *sev);
int check_builtin(sev_t *sev);

/* builtin2.c */
void change_dir(sev_t *sev);
void history(sev_t *sev);
void alias(sev_t *sev);


/* error1.c */
char *fnotfound(sev_t *sev);
char *illnum(sev_t *sev);
char *perdenied(sev_t *sev);
char *invaldir(sev_t *sev);
char *invalalias(sev_t *sev, int reset);

/* error2.c */
char *helpfnotfound(sev_t *sev);
char *illoptions(sev_t *sev);
char *invalenv(sev_t *sev);


/* memory.c */
void reset_buffer(char *buffer, ssize_t buf_size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size, list_t **mt);


/* string1.c */
char *_strdup(char *str, list_t **mt);
unsigned int _strspn(char *s, char *accept);
char *_strpbrk(char *s, char *accept);
char *_strtok(char *s, const char *delim);
unsigned int _strlen(char *s);


/*  string2.c*/
int _strcmp(char *s1, char *s2);
int _atoi(char *s);
char *_strcat(char *s1, char *s2, list_t **mt);
char *_itoa(ssize_t num, list_t **mt);
char *reverse_str(char *s);


/*  string3.c*/
char *_strchr(char *s, char c);
void _chartostr(char *s, char c);


/* helper1.c */
void sig_hand(int signum);
void dis_prompt(sev_t sev);
char *getcom(sev_t *sev);
char **make_array_str(char *s, const char *delim, sev_t *sev);
int actions(sev_t *sev);


/* helper2.c */
char *_getenvironment(char *envar, sev_t *sev);
char *pathfind(sev_t *sev);
void cl_sev(sev_t *sev);
char **make_evp_array(sev_t *sev);
int _setenv_help(sev_t *sev, char *tofind, char *cwd);


/* helper3.c  */
sev_t *init_shell_env(sev_t *sev, char **av, char **ev);
list_t *read_environment(sev_t *sev, char **ev);
void dis_error(sev_t *sev);
void var_expan(sev_t *sev);
int p_alias_val(sev_t *sev, char *key, char *value, int flag);


/*helper4.c*/
void process_inputs(char *cmd, sev_t *sev);
void dis_banner(int ia_mode);
void checker_alias(sev_t *sev);

#endif
