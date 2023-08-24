#include "monty.h"
j_t j = {NULL, NULL, NULL, 0};

/**
 * main - The main function entry point
 * @argc: Number of arguments
 * @argv: Argument vector
 * Return: 0
 */

int main(int argc, char *argv[])
{
	char *content;
	size_t size = 0;
	ssize_t read_line = 0;
	stack_t *stack = NULL;
	unsigned int num = 0;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	j.file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read_line = getline(&content, &size, file)) != -1)
	{
		j.content = content;
		num++;

		if (read_line > 0)
		{
			execute(content, &stack, num, file);
		}
	}
	free(content);
	free_stack(stack);
	fclose(file);
	return (0);
}
