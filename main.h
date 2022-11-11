#ifndef _SIMPLE_SHELL_
#define _SIMPLE_SHELL_

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


extern char **environ;

char **tokenize(char *);
int strcompare(char *str1, char *str2);

void printstr(char **str_arr);

#endif
