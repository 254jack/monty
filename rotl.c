#include "monty.h"
/**
 * rotl - A function that rotates the stack to the top.
 * @head: A pointer to the stack.
 * @num: The line number.
 */
void rotl(stack_t **head, unsigned int num)
{
    (void)num;
    stack_t *copy;

    copy = *head;
    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }
    while (copy->next)
    {
        copy = copy->next;
    }
    copy->next = *head;
    copy->prev->next = NULL;
    copy->prev = NULL;
    (*head)->prev = copy;
    (*head) = copy;
}
