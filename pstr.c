#include "monty.h"
/**
 * pstr - A function that prints the string starting at the top of the stack,
 * followed by a new line.
 * @head: A pointer to the stack.
 * @num: The line number.
 */
void pstr(stack_t **head, unsigned int num)
{
    stack_t *h;
    (void)num;

    h = *head;
    while (h)
    {
        if (h->n > 127 || h->n <= 0)
        {
            break;
        }
        printf("%c", h->n);
        h = h->next;
    }
    printf("\n");
}
