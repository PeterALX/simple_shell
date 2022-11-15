#ifndef _SIMPLE_SHELL_
#define _SIMPLE_SHELL_

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>


extern char **environ;

char **tokenize(char *, char *);
int strcompare(char *str1, char *str2);
int is_substring(char *str1, char *str2);
char *find_command(char *command, char **environ);
char *str_append(char *dest, char *substr);

void printstr(char **str_arr);
char *_strcpy(char *src);

#endif
