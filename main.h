#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stddef.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>


void execdo(char **argv);
char *get_way(char *cmnd);


extern char **environ;

void *_realloc(void *ptr, unsigned int nv_size);
unsigned int _strlen(char *str);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, int n);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *_strdup(const char *str);

/* get_line.c */
#define READ_BUF_SIZE 1024

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);


#endif
