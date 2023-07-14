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

int _putchar(char);
void _puts(char *);
void _print(char *);

int _eputchar(char);
void _eputs(char *);
void _eprint(char *);

char *_parse(char *);

void prompt(void);
void hsh(void);
void fork_hsh(char *);

#endif
