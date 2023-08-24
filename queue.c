#include "monty.h"
/**
 * f_queue - function that prints the top
 * @head: head
 * @num: line number
 * Return: 0
*/
void f_queue(stack_t **head, unsigned int num)
{
	(void)head;
	(void)num;
	j.lifi = 1;
}
/**
 * addqueue - A function that sets the format of the data to a queue (FIFO).
 * @head: A pointer to the stack.
 * @num: The line number.
 * Return: 0
 */
void addqueue(stack_t **head, unsigned int num)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\num");
	}
	new_node->n = num;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}
