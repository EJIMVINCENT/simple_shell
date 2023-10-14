#include "shell.h"


/**
 * _memcpy - copies information from one memory to another
 *
 * @newptr: destination pointer.
 * @ptr: source pointer.
 * @size: size of the new pointer.
 *
 */

void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_newptr = (char *)newptr;
	unsigned int i;

	for (i = 0; i < size; i++)
		char_newptr[i] = char_ptr[i];
}



char **customRealloc(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **newptr;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(sizeof(char *) * new_size);
	if (newptr == NULL)
		return (NULL);

	for (i = 0; i < old_size; i++)
		newptr[i] = ptr[i];

	free(ptr);

	return (newptr);
}


void *_realloc(void *ptr, unsigned int oldlen, unsigned int newlen)
{
	void *newptr;

	if (ptr == NULL)
		return (malloc(newlen));

	if (newlen == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (newlen == oldlen)
		return (ptr);

	newptr = malloc(newlen);
	if (newptr == NULL)
		return (NULL);

	if (newlen < oldlen)
		_memcpy(newptr, ptr, newlen);
	else
		_memcpy(newptr, ptr, oldlen);

	free(ptr);
	return (newptr);
}


