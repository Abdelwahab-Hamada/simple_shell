#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include<stdbool.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/**
 * struct pair - cmd pair
 * @path: path
 * @cmd: command
 */
struct pair
{
	char *path;
	char **cmd;
} token_pair;

int _putchar(char);
void _puts(char *);
void _print(char *);

void prompt(void);

void hsh(char **);
void fork_hsh(char **);

void _strcat(char *, char *);

void tokenize(char *);

int check_cmd(char *);

int _strstr(char *, char *);

int _strlen(char *);

void penv(char **);

#endif

