#ifndef _SIMPLE_SHELL_
#define _SIMPLE_SHELL_

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char **environ;

char **tokenize(char *);
#endif
