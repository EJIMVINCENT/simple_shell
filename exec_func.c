void exeCom(char **commands)
 26 {
 27         pid_t child_pid = fork();
 28 
 29         if (child_pid == -1)
 30         {
 31                 write(STDERR_FILENO, "Error forking process.\n", sizeof(    "Error forking process.\n"));
 32                 exit(EXIT_FAILURE);
 33 
 34         }
 35         else if (child_pid == 0)
 36         {
 37                 execvp(commands[0], commands);
 38         }
 39 
 40 }
