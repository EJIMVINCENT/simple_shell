#include "shell.h"



int stringCmp(char *str, const char *delim)
{
	unsigned int i, j, k = 0;

	for (i = 0, str[i]; i++)
	{
		j = 0;
		while (delim[j])
		{
			if (str[i] == delim[j])
				k++, break;
			j++;
		}
	}
	if (i == k)
		return (1);
	return (0);
}



char *_strtok(char *string, const char *delim)
{
	static char *temp, *strEnd;
	char *strStart;
	unsigned int i, status;

	if (string != NULL)
	{
		if (stringCmp(string, delim))
			return (NULL);
		temp = str;
		i = _strlen(string);
		strEnd = &string[i];
	}
	strStart = temp;
	if (strStart == strEnd)
		return (NULL);

	for (status = 0; *temp; temp++)
	{
		if (temp != strStart)
			if (*temp && *(temp - 1) == '\0')
				break;
		for (i = 0; delim[i]; i++)
		{
			if (*temp == delim[i])
			{
				*temp = '\0';
				if (temp == strStart)
					strStart++;
				break;
			}
		}
		if (status == 0 && *temp)
			status = 1;
	}
	if (status == 0)
		return (NULL);
	return (strStart);
}
