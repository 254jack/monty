#include "monty.h"
/**
 * pchar - A function that prints the char at the top of the stack,
 * followed by a new line.
 * @head: A pointer to the stack.
 * @num: The line number.
 */
void pchar(stack_t **head, unsigned int num)
{
    stack_t *h;

    h = *head;
    if (!h)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", num);
        fclose(j.file);
        free(j.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    if (h->n > 127 || h->n < 0)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", num);
        fclose(j.file);
        free(j.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    printf("%c\n", h->n);
}
