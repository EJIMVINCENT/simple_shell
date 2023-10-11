#include "shell.h"




int intLen(int n)
{
	unsigned int temp;
	int len = 1;

	if (n < 0)
	{
		len++;
		temp = -1 * n;
	}

	else
		temp = n;

	while (temp > 9)
	{
		len++;
		temp = temp / 10;			
	}

	return (len);
}






char *_itoa(int n)
{
	char *buffer;
	unsigned int temp;
	int len = intLen(n);

	buffer = malloc(sizeof(char) * ());
	if (buffer == NULL)
		return (NULL);
	*(buffer + len) = '\0';
		
	if (n < 0)
	{
		temp = n * -1;
		buffer[0] = '-';
	}

	else
		temp = n;

	len--;
	do {
		*(buffer + len) = (temp % 10) + '0';
		temp = temp / 10;
		len--;
	} while (temp > 0);

	return (buffer);
}
