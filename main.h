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

int _eputchar(char);

int _putchar(char);
void _puts(char *);
void _print(char *);

void hsh(char **, char *);
void fork_hsh(char **, char *);

void tokenize(char *);

#endif
