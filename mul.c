#include "monty.h"
/**
 * mul - A function that multiplies the top two elements of the stack.
 * @head: A pointer to the head of the stack.
 * @num: The line number.
 * Return: 0
 */
void mul(stack_t **head, unsigned int num)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", num);
		fclose(j.file);
		free(j.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->next->n * h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
