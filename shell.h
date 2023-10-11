#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>

#define DELIM  " \t\n"
#define BUFFERSIZE 1024

extern char **environ;


typedef struct shellData
{
	char **argv;
	char **_environs;
	char *pid;
	int count;
	int stat;
	char *userInput;
	char **commands;
} shellData;


/* string function */ 

char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);

#endif
