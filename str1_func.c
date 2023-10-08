#include "shell.h"





int cmpChars(char str[], char *delim)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
	return (0);
}



char *_strtok(char string[], char *d)
{
	static char *split, *strend;
	char *strstart;
	unsigned int len, bool, i;

	if (string != NULL)
	{
		if (cmpChars(string, d))
			return (NULL);

		split = string;
		len = _strlen(string);
		 /*Store last address*/
		strend = &string[len];
	}
	strstart = split;
	/* check for end of string */
	if (strstart == strend)
		return (NULL);

	for (bool = 0; *split != '\0'; split++)
	{
		/* check if a non-deli has been found */
		if (split != strstart)
			if (*split != '\0' && *(split - 1) == '\0')
				break;
		/*Replacing delimiter for null char*/
		for (i = 0; d[i]; i++)
		{
			/*check if spilt is in delimetr*/
			if (*split == d[i])
			{
				*split = '\0';
				if (split == strstart)
					strstart++;
				break;
			}
		}
		if (bool == 0 && *split)
			/* a legit character found*/
			bool = 1;
	}
	if (bool == 0)
		return (NULL);
	return (strstart);
}
