#include "shell.h"

/**
 * addSepNode - Adds a node to the end
 * singley linked list that store com seperators.
 *
 * @sepHead: pointer to head of sep singley linked list
 * @s: seperator to be added
 *
 * Return: pointer to sephead
 *
 */

sep *addSepNode(sep **sepHead, char s)
{
	sep *n, *t;

	n = malloc(sizeof(sep));
	if (!n)
		return (NULL);

	n->separator = s;
	n->next = NULL;
	t = *sepHead;
	if (t == NULL)
		*sepHead = n;
	else
	{
		while (t->next != NULL)
			t = t->next;
		t->next = n;
	}
	return (*sepHead);
}


/**
 * addComNode - Adds a node to the end
 * singley linked list that store commands.
 *
 * @comHead: pointer to head of sep singley linked list
 * @command: seperator to be added
 *
 * Return: pointer to comhead
 *
 */

commands *addComNode(commands **comHead, char *command)
{
	commands *n, *t;

	n = malloc(sizeof(commands));
	if (!n)
		return (NULL);

	n->command = command;
	n->next = NULL;
	t = *comHead;
	if (!t)
		*comHead = n;
	else
	{
		while (t->next)
			t = t->next;
		t->next = n;
	}
	return (*comHead);
}

/**
 * freeComSepNode - frees a singly linked list (sep, commands)
 *
 * @comHead: pointer to head of commands linked list
 * @sepHead: pointer to head of sep linked list
 *
 */

void freeComSepNode(commands **comHead, sep **sepHead)
{
	commands *temp;
	commands *current;
	sep *temp1;
	sep *current1;

	if (comHead != NULL)
	{
		current = *comHead;
		temp = current;
		while (current != NULL)
		{
			current = current->next;
			free(temp);
			temp = current;
		}
		*comHead = NULL;
	}
	if (sepHead != NULL)
	{
		current1 = *sepHead;
		temp1 = current1;
		while (current1 != NULL)
		{
			current1 = current1->next;
			free(temp1);
			temp1 = current1;
		}
		*sepHead = NULL;
	}

}
