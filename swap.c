#include "monty.h"
/**
 * swap - A function that swaps the top two elements of the stack.
 * @head: A pointer to the stack.
 * @num: The line number.
 */
void swap(stack_t **head, unsigned int num)
{
    int temp;
    stack_t *h;

    h = *head;
    if (!h || !h->next)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", num);
        fclose(j.file);
        free(j.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    temp = h->n;
    h->n = h->next->n;
    h->next->n = temp;
}
