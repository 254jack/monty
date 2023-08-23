#include "monty.h"
/**
 * pop - A function that removes the top element of the stack.
 * @head: A pointer to the stack.
 * @num: The line number.
 */
void pop(stack_t **head, unsigned int num)
{
    stack_t *h;

    if (*head == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", num);
        fclose(j.file);
        free(j.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    h = *head;
    *head = h->next;
    free(h);
}
