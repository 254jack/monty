#include "monty.h"
/**
 * add_node - A function that adds a new node at the beginning of a stack.
 * @head: A pointer to the head of the stack.
 * @n: The value to be added to the new node.
 * Return: 0
 */
void addnode(stack_t **head, int n)
{
    stack_t *new_node, *aux;

    aux = *head;
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        printf("Error\n");
    }
    if (aux)
        aux->prev = new_node;
    new_node->n = n;
    new_node->next = *head;
    new_node->prev = NULL;
    *head = new_node;
}
