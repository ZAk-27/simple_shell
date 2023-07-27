#ifndef MAIN_H
#define MAIN_H


#define PROMPT "#ZSELL$ "

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

extern char **environ;

/**
 * struct data - main data holder.
 * @av: tokens array
 * @cmd: user input nd command line
 * @shell_cr: the created shell name
 * @last_status: last status of last exit command 
 * @flg_setenv: 1 used to free memory if executed by user
 */
typedef struct data
{
	char **av;
	char *cmd;
	const char *shell_cr;
	int last_status;
	int flg_setenv;
} data;

/**
 * struct bltn - holds the main data.
 * @cmd: builted in cmd
 * @f: function of bltn cmd
 */
typedef struct bltn
{
	const char *cmd;
	void (*f)(data *d);
} bltn;

/* bltn.c */
int exec_bltn(data *d);
void bltn_exit(data *d);
void bltn_env(data *d);
void bltn_setenv(data *d);
void bltn_unsetenv(data *d);
void bltn_cd(data *d);


/* hlpr.c */
void _printf(const char *str);
void free_array(char **array);
void split(data *d, const char *delim);
void init_data(data *d, const char *shell_cr);
void read_cmd(data *d);

/* hlpr2.c */
void _perror(const char *str1, const char *str2);
void _trim(char *str);
void *_realloc(void *ptr, unsigned int new_size);

/* exec_t.c */
void process_start(data *d);
void signit_hand(int signal);
void _exect(data *d);


/* strl.c */
unsigned int _strlen(char *str);
int _strcmp(const char *s1, const char *s2);


/* strl2.c */
char *_strdup(const char *str);
int _isnumber(const char *status);
int _isdigit(int c);

/* getl_ine.c */
#define READ_BUF_SIZE 1024

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);


#endif
