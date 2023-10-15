#include "shell.h"



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
