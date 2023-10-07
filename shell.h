#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


/* string functions [str_func] */

int _strlen(char *string);
int _strcmp(char *s1, char *s2);
char * _strdup(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);



/* print functions [print_func] */

int putString(char *string);


/* prompt function */

void printPrompt();
char *getPrompt(size_t *count);

/* execute functions */

void exeCom(char **commands);


/* perse function [perse_func] */

char **perseCom(char *input);

#endif /* SHELL_H */
