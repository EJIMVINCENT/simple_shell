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


#define TOKBUFF 128
#define DELIM " \t\r\n\a"
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



/**
 * struct sep - single linked list
 *
 * @separator: (; | &)
 * @next: pointer to next node
 *
 * Description: single linked list to store store separators
 *
 */

typedef struct sep
{
	char separator;
	struct sep *next;
} sep;



/**
 * struct commands - single linked list
 *
 * @command: command line
 * @next: pointer to  next node
 *
 * Description: single linked list to store command line arguments
 */

typedef struct commands
{
	char *command;
	struct commands *next;
} commands;



/* string function */ 

char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);

#endif
