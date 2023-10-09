#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>



typedef struct shellData
{
	char **_environ;
	char **args;
	char *input;
	char **commands;
	char *epath;
	int status;
	
} shellData;

#define INIT_sd {NULL, NULL, NULL, NULL, 0}

/* string functions [str_func] */

int _strlen(char *string);
int _strcmp(char *s1, char *s2);
char * _strdup(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strtok(char *input, char *d);



/* prompt function */


/* execute functions */

void exeCom(shellData *sd);


/* perse function [perse_func] */

void parseCom(shellData *sd);

extern char** environ;

#endif /* SHELL_H */
