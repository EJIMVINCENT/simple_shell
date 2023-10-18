#include "shell.h"

/**
 * replaceVar - replaces variable
 * @h: pointer to a pointer
 * @input: A pointer
 * @result: A pointer
 * @len: integer
 *
 * Return: result
 */
char *replaceVar(repVar **h, char *input, char *result, int len)
{
	repVar *temp;

	int i = 0, j = 0, k = 0;

	temp = *h;
	for (; i < len; i++)
	{
		if (input[j] == '$')
		{
			if (!(temp->repLen) && !(temp->varLen))
			{
				result[i] = input[j];
				j++;
			}
			else if (!(temp->repLen) && (temp->varLen))
			{
				for (k = 0; k < temp->varLen; k++)
					j++;
				i--;
			}
			else
			{
				for (k = 0; k < temp->repLen; k++)
				{
					result[i] = temp->replace[k];
					i++;
				}
				j += (temp->varLen), i--;
			}
			temp = temp->next;
		}
		else
			result[i] = input[j], j++;
	}
	return (result);
}


/**
 * varExpansion - Expands variable
 * @input: char pointer
 * @s: pointer to shellData
 *
 * Return: result
 */
char *varExpansion(char *input, shellData *s)
{
	repVar *head = NULL, *temp;
	char *status, *result;
	int lenV, len = 0;

	status = _itoa(s->stat);

	lenV = varCheck(&head, input, status, s);

	if (head == NULL)
	{
		free(status);
		return (input);
	}

	temp = head;

	while (temp)
	{
		len += (temp->repLen - temp->varLen);
		temp = temp->next;
	}

	len += lenV;

	result = malloc(sizeof(char) * (len + 1));
	result[len] = '\0';

	result = replaceVar(&head, input, result, len);

	free(input);
	free(status);
	freeRepVarNode(&head);

	return (result);
}


/**
 * varCheck - checks variable
 * @head: pointer to pointer
 * @input: char pointer
 * @stat: char pointer
 * @s: pointer to shellData
 *
 * Return: i for success
 */
int  varCheck(repVar **head, char *input, char *stat, shellData *s)
{
	int i = 0, statlen, pidlen;
	char *vpid;

	vpid = s->pid;
	statlen = _strlen(stat);
	pidlen = _strlen(vpid);

	for (; input[i]; i++)
	{
		if (input[i] == '$')
		{
			if (input[i + 1] == '$')
			{
				addRepVarNode(head, 2, vpid, pidlen);
				i++;
			}
			else if (input[i + 1] == '?')
			{
				addRepVarNode(head, 2, stat, statlen);
				i++;
			}
			else if (input[i + 1] == ' ')
				addRepVarNode(head, 0, NULL, 0);
			else if (input[i + 1] == '\n')
				addRepVarNode(head, 0, NULL, 0);
			else if (input[i + 1] == '\t')
				addRepVarNode(head, 0, NULL, 0);
			else if (input[i + 1] == '\0')
				addRepVarNode(head, 0, NULL, 0);
			else if (input[i + 1] == ';')
				addRepVarNode(head, 0, NULL, 0);
			else
				envRepCheck(head, input + i, s);
		}
	}
	return (i);
}

/**
 * envRepCheck - ....
 * @head: pointer to a pointer
 * @input: char pointer
 * @s: pointer to shellData
 *
 * Return: void
 */
void envRepCheck(repVar **head, char *input, shellData *s)
{
	int i, j, k, varlen;
	char **e;

	varlen = 0;
	e = s->_environ;

	for (i = 0; e[i]; i++)
	{
		for (j = 0, k = 1; e[i][j]; j++)
		{
			if (e[i][j] == '=')
			{
				varlen = _strlen(e[i] + j + 1);
				addRepVarNode(head, k, e[i] + j + 1, varlen);
				return;
			}
			if (input[k] == e[i][j])
				k++;
			else
				break;
		}
	}

	for (i = 0; input[i]; i++)
	{
		if (input[i] == ' ' ||
		    input[i] == '\t' ||
		    input[i] == ';' ||
		    input[i] == '\n')
			break;
	}

	addRepVarNode(head, i, NULL, 0);
}
