#include "monty.h"
/**
 * pint - A function that prints the value at the top of the stack.
 * @head: A pointer to the stack.
 * @num: The line number.
 */
void pint(stack_t **head, unsigned int num)
{
    if (*head == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", num);
        fclose(j.file);
        free(j.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*head)->n);
}
