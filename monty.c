#include "main.h"
/**
 * push - a function that push an object to the struct
 * @stack: pointer to a pointer to stack_t
 * @value: integer arguments
 * Return: 0
*/
void push(stack_t **stack, int value)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;

    if (*stack)
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
    }
    else
    {
        new_node->next = NULL;
    }

    *stack = new_node;
}
/**
 * pall - a function that removes an object to the struct
 * @stack: pointer to a pointer to stack_t
 * Return: 0
*/
void pall(stack_t **stack)
{
    stack_t *current = *stack;
    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
/**
 * main - main entry function
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
*/
int main(int argc, char *argv[])
{
    FILE *file;
    stack_t *stack = NULL;
    char line[100];
    char *opcode;
    int value;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Unable to open file\n");
        return EXIT_FAILURE;
    }

    while (fgets(line, sizeof(line), file) != NULL)
    {
        opcode = strtok(line, " \t\n");
        if (strcmp(opcode, "push") == 0)
        {
            char *arg = strtok(NULL, " \t\n");
            if (arg == NULL)
            {
                fprintf(stderr, "Error: Invalid push usage\n");
                return EXIT_FAILURE;
            }
            value = atoi(arg);
            push(&stack, value);
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall(&stack);
        }
        else
        {
            fprintf(stderr, "Error: Unknown opcode %s\n", opcode);
            return EXIT_FAILURE;
        }
    }

    fclose(file);
    return EXIT_SUCCESS;
}
