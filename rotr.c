#include "monty.h"
/**
 * rotr - A function that rotates the stack to the bottom.
 * @head: A pointer to the stack.
 * @num: The line number.
 */
void rotr(stack_t **head, unsigned int num)
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
    copy = *head;
    while (copy->next)
    {
        copy = copy->next;
    }
}
