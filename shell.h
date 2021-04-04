#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


void user_prompt(void);
char *read_cmd(void);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);

#endif
