#ifndef MONTY_H
#define MONTY_H


#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Buffsize 20

/**
 * struct stack_s - Doubly linked list representation of a stack (or queue)
 * @n: Integer
 * @prev: Points to the previous element of the stack (or queue)
 * @next: Points to the next element of the stack (or queue)
 *
 * Description: Doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int ln);
} instruction_t;


/**
 * struct global_var - global variables
 * @file: file name
 * @buff: buffer
 * @tmp: counter
 * @dict: dictionary
 * @head: pointer to list
 * @ln: Stores file current line
 * @MODE: stack || queue
 */
typedef struct global_var
{
	FILE *file;
	char *buff;
	size_t tmp;
	instruction_t *dict;
	stack_t *head;
	unsigned int ln;
	int MODE;
} vars;

extern vars var;

int start_vars(vars *var);
instruction_t *create_instru();
int call_funct(vars *var, char *opcode);
void free_all(void);
int _isdigit(char *string);

void pall(stack_t **stack, unsigned int ln);
void push(stack_t **stack, unsigned int ln);
void pint(stack_t **stack, unsigned int ln);
void pop(stack_t **stack, unsigned int ln);

void swap(stack_t **stack, unsigned int ln);
void add(stack_t **stack, unsigned int ln);
void sub(stack_t **stack, unsigned int ln);
void div(stack_t **stack, unsigned int ln);

void mul(stack_t **stack, unsigned int ln);
void mod(stack_t **stack, unsigned int ln);
void pchar(stack_t **stack, unsigned int ln);
void pstr(stack_t **stack, unsigned int ln);

void rot1(stack_t **stack, unsigned int ln);
void rotr(stack_t **stack, unsigned int ln);
void stack(stack_t **stack, unsigned int ln);
void queue(stack_t **stack, unsigned int ln);


#endif