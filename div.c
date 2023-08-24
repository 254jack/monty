#include "monty.h"
/**
 * f_div - A function that divides the top two elements of the stack.
 * @head: A pointer to the head of the stack.
 * @num: The line number.
 * Return: 0
 */
void f_div(stack_t **head, unsigned int num)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", num);
		fclose(j.file);
		free(j.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", num);
		fclose(j.file);
		free(j.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n / h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
