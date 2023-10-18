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

/**
 * customRealloc - custom function to resize a double pointer
 *
 * @p: double pointer to be resized
 * @oldlen: old size of the double pointer
 * @newlen: new size of the double pointer
 *
 * Return: return new double pointer of size new_size
 *
 */

char **customRealloc(char **p, unsigned int oldlen, unsigned int newlen)
{
	char **new;
	unsigned int i = 0;

	if (p == NULL)
		return (malloc(sizeof(char *) * newlen));

	if (newlen == oldlen)
		return (p);

	new = malloc(sizeof(char *) * newlen);
	if (new == NULL)
		return (NULL);

	while (i < oldlen)
		new[i] = p[i], i++;

	free(p);

	return (new);
}

/**
 * _realloc - resizes a pointer variable
 *
 * @ptr: pointer to be resized
 * @oldlen: old lenght of pointer
 * @newlen: new lenght to be resized to
 *
 * Return: new ptr with size newlen
 *
 */

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


