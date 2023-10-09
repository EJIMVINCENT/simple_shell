#include "shell.h"


char* _getenv(const char* name)
{
    if (name == NULL) {
        return NULL; // Handle the case of a NULL input gracefully.
    }

    extern char** environ;
    if (environ == NULL) {
        return NULL; // Handle the case where environ is NULL.
    }

    size_t name_len = strlen(name);

    for (char** env = environ; *env != NULL; env++) {
        if (strncmp(name, *env, name_len) == 0 && (*env)[name_len] == '=') {
            return &((*env)[name_len + 1]);
        }
    }

    return NULL; // Return NULL if the environment variable is not found.
}
