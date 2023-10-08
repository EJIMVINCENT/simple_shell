#include "shell.h"







int main(int ac, char *argv[]) 
{
	(void) ac;
	(void) argv;
	shellData sd = INIT_sd;  

	shellLoop(&sd);
}
