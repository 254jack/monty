#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"

/**
 * push - Pushes an element onto the stack
 * @stack: Pointer to a pointer to the stack
 * @value: Integer value to be pushed onto the stack
 * Return: void
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
 * pall - Prints all values in the stack
 * @stack: Pointer to a pointer to the stack
 * Return: void
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
 * free_stack - Frees the memory allocated for the stack
 * @stack: Pointer to the stack
 * Return: void
 */
void free_stack(stack_t *stack)
{
	while (stack)
	{
		stack_t *temp = stack;
		stack = stack->next;
		free(temp);
	}
}

/**
 * main - Main function that reads and executes Monty bytecode
 * @argc: Argument count
 * @argv: Argument vector
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;
	char line[100];
	char *opcode;
	char *arg;
	int value;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		opcode = strtok(line, " \t\n");
		if (opcode)
		{
			if (strcmp(opcode, "push") == 0)
			{
				arg = strtok(NULL, " \t\n");
				if (!arg || (!isdigit(*arg) && *arg != '-' && *arg != '+'))
				{
					fprintf(stderr, "L%u: usage: push integer\n", line_number);
					fclose(file);
					free_stack(stack);
					exit(EXIT_FAILURE);
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
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
				fclose(file);
				free_stack(stack);
				exit(EXIT_FAILURE);
			}
		}
	}

	fclose(file);
	free_stack(stack);
	return EXIT_SUCCESS;
}
