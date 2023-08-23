#include "monty.h"
/**
 * push - A function that pushes a new node onto the stack.
 * @head: A pointer to the stack.
 * @num: The line number.
 */
void push(stack_t **head, unsigned int num)
{
    int n, k = 0, flag = 0;

    if (j.arg)
    {
        if (j.arg[0] == '-')
            k++;
        for (; j.arg[k] != '\0'; k++)
        {
            if (j.arg[k] > 57 || j.arg[k] < 48)
                flag = 1;
        }
        if (flag == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", num);
            fclose(j.file);
            free(j.content);
            free_stack(*head);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "L%d: usage: push integer\n", num);
        fclose(j.file);
        free(j.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    n = atoi(j.arg);
    if (j.lifi == 0)
        addnode(head, n);
    else
        addqueue(head, n);
}
