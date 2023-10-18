#include "shell.h"



/**
 * addRepVarNode - adds a value at the end
 * of a repVar struct.
 *
 * @head: pointer to head of repVar linked list.
 * @varLen: length of the variable.
 * @valuen: value of the replacement.
 * @repLen: length of the replacement.
 *
 * Return: address of head.
 */

repVar *addRepVarNode(repVar **head, int varLen, char *value, int repLen)
{
	repVar *new, *temp;

	new = malloc(sizeof(repVar));
	if (new == NULL)
		return (NULL);

	new->varLen = varLen;
	new->replace = value;
	new->repLen = repLen;
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
		*head = new;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}


/**
 * freeRepVarNode - frees a repVar struct
 *
 * @head: pointer to head of the linked list.
 *
 * Return: no return.
 *
 */

void freeRepVarNode(repVar **head)
{
	repVar *temp;
	repVar *n;

	if (head != NULL)
	{
		n = *head;
		while ((temp = n) != NULL)
		{
			n = n->next;
			free(temp);
		}
		*head = NULL;
	}
}
