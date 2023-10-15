#include "shell.h"

/**
 * intLen: finds the lenght of an int
 *
 * @n: int to be len checked
 *
 * Returns: lenght of input int
 *
 */

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



/**
 * _atoi - converts a string to an integer.
 *
 * @s: input string.
 *
 * Return: integer.
 *
 */

int _atoi(char *s)
{
	unsigned int count = 0, size = 0, oi = 0, pn = 1, m = 1, i;

	while (*(s + count) != '\0')
	{
		if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;

		if (*(s + count) == '-')
			pn *= -1;

		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		count++;
	}

	for (i = count - size; i < count; i++)
	{
		oi = oi + ((*(s + i) - 48) * m);
		m /= 10;
	}
	return (oi * pn);
}

/**
 * _itoa - converts int to string
 *
 * @n: int to be converted to string
 *
 * Return: returns n as a string
 *
 */

char *_itoa(int n)
{
	char *buffer;
	unsigned int temp;
	int len = intLen(n);

	buffer = malloc(sizeof(char) * len);
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
