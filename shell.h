#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>


char **tokenize(char *str);
char **tokenize1(char *buffer);
void user_prompt(void);
char *read_cmd(void);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strncpy(char *dest, char *src, int n);
char **token_test(char *str);
void execute(char **cmd);

#endif
