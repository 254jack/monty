#include "monty.h"
/**
 * pall - A function that prints all the elements of the stack.
 * @head: A pointer to the stack.
 * @num: The line number.
 */
void pall(stack_t **head, unsigned int num)
{
    stack_t *h;
    (void)num;

    h = *head;
    if (h == NULL)
        return;
    while (h)
    {
        printf("%d\n", h->n);
        h = h->next;
    }
}
