#include "monty.h"
/**
 * pall - a function that prints the list
 * @stack: Double pointer
 * @ln: line execution
 */
void pall(stack_t **stack, unsigned int ln)
{
    stack_t *tmp = *stack;
    (void)ln;

    if (!tmp)
        return;
    while (tmp)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
}

/**
 * push - a function that inserts a new value in list
 * @stack: Double pointer
 * @ln: ine execution
 */
void push(stack_t **stack, unsigned int ln)
{
    stack_t *tmp = NULL, *tm = *stack;
    char *num;

    num = strtok(NULL, " \r\t\n");
    if (num == NULL || (_isdigit(num) != 0 && num[0] != '-'))
    {
        fprintf(stderr, "L%u: usage: push integer\n", ln);
        free_all();
        exit(EXIT_FAILURE);
    }
    tmp = malloc(sizeof(stack_t));
    if (!tmp)
    {
        fprintf(stderr, "Error: malloc failed\n");
        free_all();
        exit(EXIT_FAILURE);
    }
    tmp->n = atoi(num);
    if (var.MODE == 0 || !*stack)
    {
        tmp->next = *stack;
        tmp->prev = NULL;
        if (*stack)
            (*stack)->prev = tmp;
        *stack = tmp;
    }
    else
    {
        while (tm->next)
            tm = tm->next;
        tm->next = tmp;
        tmp->prev = tm;
        tmp->next = NULL;
    }
}
