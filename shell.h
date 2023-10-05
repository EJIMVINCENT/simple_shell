#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>



/* string functions [str_func] */

int _strlen(char *string);
int _strcmp(char *s1, char *s2);
int _strdup(char *str);
char *_strcat(char *dest, char *src);
char *strcpy(char *dest, char *src);



/* print functions [print_func] */

int putString(char *string);


/* prompt function */

void printPrompt();
void getPrompt(char *input, int *count);

/* execute functions */

void exeCom(char **commands);

#endif /* SHELL_H */
