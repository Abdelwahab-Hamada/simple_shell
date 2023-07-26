#ifndef _MAIN_H
#define _MAIN_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define CMD_SIZE 64

extern char **environ;

void hsh(int , char **);

char *read_line();

char **tokenize(char *);

int exec_toks(char **);

size_t _strspn(char *, char *);

size_t _strlen(const char *);

char *_strdup(const char *);

void *_realloc(void *, unsigned int , size_t);

void handle_builtin(char **);

char *check_cmd(char *);

int _atoi(char *);

char *_getenv(const char *);

void penv(void);

int _strcmp(char *, char *);

char *_strcpy(char *, char *);

int _strncmp(const char *, const char *, int);

void free_ptr(char **);

#endif

