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
 * @head: pointer to head of commands linked list
 *
 */

void freeComNode(commands **head)
{
	commands *temp;
	commands *current;

	if (head != NULL)
	{
		current = *head;
		temp = current;
		while (current != NULL)
		{
			current = current->next;
			free(temp);
			temp = current;
		}
		*head = NULL;
	}
}

/**
 * freeSepNode - frees a singly linked list (sep)
 *
 * @head: pointer to head of sep linked list
 *
 */

void freeSepNode(sep **head)
{
	sep *temp;
	sep *current;

	if (head != NULL)
	{
		current = *head;
		temp = current;
		while (current != NULL)
		{
			current = current->next;
			free(temp);
			temp = current;
		}
		*head = NULL;
	}
}
