#ifndef SHELL_H
#define SHELL_H

extern char **environ;


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>



#define TOKBUFF 128
#define DELIM " \t\r\n\a"
#define BUFFERSIZE 1024



/**
 * struct shellData - custome shell main structure
 *
 * @argv: pointer command line arguments
 * @_environ: pointer to array of environmental
 * variables
 * @pid: pointer to current proccess id
 * @count: variable to count execution
 * @stat: store execution exit status
 * @input: pointer to user input commands
 * @commands: pointer to an array containing commands
 * and args to be executed
 *
 */

typedef struct shellData
{
	char **argv;
	char **_environ;
	char *pid;
	int count;
	int stat;
	char *input;
	char **commands;
} shellData;


/**
 * struct replaceVar - linked list used to store
 * value for variable replacement.
 *
 * repLen: length of the value
 * varLen: length of the variable
 * next: pointer to next node
 *
 */

typedef struct replaceVar
{
	int repLen;
	int varLen;
	char *replace;
	struct replaceVar *next;
	
} repVar;




/**
 * struct builtin - A new struct type defining builtin commands.
 *
 * @name: The name of the builtin command.
 * @f: A function pointer
 */

typedef struct custome
{
	char *name;
	int (*f)(shellData *s);
} customeB;



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



/* shell.c */
void setData(shellData *shellD, char **argv);
void Csignal(int s);


/* parseCommands_func.c */
int parseCommands(char *input, shellData *shellD);
void addComSep(sep **sepHead, commands **comHead, char *input);
char **splitCommand(char *input);
char *charSwap(char *input, int status);
void findNext(sep *sepH, commands *comH, shellData *shellD);


/* addComSepNode_func.c */
commands *addComNode(commands **comHead, char *command);
sep *addSepNode(sep **sepHead, char s);
void freeComNode(commands **head);
void freeSepNode(sep **head);

/* addRepVarNode_func.c */
repVar *addRepVarNode(repVar **head, int varLen, char *value, int repLen);
void freeRepVarNode(repVar **head);

/* varExpansion_func.c */
char *replaceVar(repVar **h, char *input, char *result, int len);
char *varExpansion(char *input, shellData *s);
int  varCheck(repVar **head, char *input, char *stat, shellData *s);
void envRepCheck(repVar **head, char *input, shellData *s);



/* environ_func.c*/
int EnvCmp(const char *envName, const char *name);
char *_getenv(const char *name, char **_environ);
int _env(shellData *shellD);


/* errors_func.c */
char *errorEnv(shellData *shellD);
int getError(shellData *shellD, int value);
char *errorNotFound(shellData *s);
char *errorExit(shellData *s);
char *errorPath126(shellData *shellD);


/* error2_func.c */

char *cdStrcat(shellData *s, char *msg, char *error, char *ver_str);
char *errorCd(shellData *s);

/* executeCommand_func.c */

int _Find(shellData *shellD);
int exeCom(shellData *shellD);
int checkExec(shellData *shellD);
int isCdir(char *path, int *i);
char *findPath(char *command, char **_environ);


/* executeCommand2_func.c */
int checkPermission(char *path, shellData *s);



/* memory_func.c */
void _memcpy(void *newptr, const void *ptr, unsigned int size);
char **customRealloc(char **ptr, unsigned int old_size, unsigned int new_size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);



/* readUInput_func.c */
char *readLine(int *check);
int _getline(char **input, size_t *n, FILE *inputStream);
char *remComment(char *input);

/* shellFunction.c */
void shellLoop(shellData *shellD);


/* stdlib_func.c */
int intLen(int n);
char *_itoa(int n);
int _atoi(char *);


/* string2_function */
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);


/* string_func.c */
char *_strdup(const char *str);
int _strlen(const char *str);
int stringCmp(char *str, const char *delim);
char *_strtok(char *string, const char *delim);
int _isdigit(const char *s);

/* syntaxSErrorCheck_func.c */
int syntaxErrorCheck(char *input, shellData *shellD);
void printSError(shellData *shellD, char *input, int b, int x);
int countRepeat(char *input, int count);
int sepErrorCheck(char *input, int index, char prev);
int findFirst(char *input, int *b);

/* freeEnviron_func.c */
void freeEnviron(shellData *s);

/* builtincoms_func.c */
int (*findBuiltIn(char *input))(shellData *s);
int exitShell(shellData *shellD);

#endif /* shell.h */
