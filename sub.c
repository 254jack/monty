#include "monty.h"
/**
 * sub - A function that subtracts the top element of the stack
 * from the second top element of the stack.
 * @head: A pointer to the stack.
 * @num: The line number.
 */
void sub(stack_t **head, unsigned int num)
{
    stack_t *h;
    int len = 0, result;

    h = *head;
    while (h)
    {
        h = h->next;
        len++;
    }
    if (len < 2)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", num);
        fclose(j.file);
        free(j.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    h = *head;
    result = h->next->n - h->n;
    h->next->n = result;
    *head = h->next;
    free(h);
}
