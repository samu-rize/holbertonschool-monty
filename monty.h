#ifndef MONTY
#define MONTY

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

/* MACRO */
#define BUFSIZE 1024
#define DELIM " \n\t"

/* COMPILING */

/* gcc -Wall -Werror -Wextra -pedantic *.c -o monty */

/* STRUCTURES */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;



/* GLOBAL VARIABLES */


/* ERROR FUNCTION */
void error_exit_s(const char *message, const char *extra_info, int code);
void error_exit_d(const char *message, const int extra_info, int code);
void invalid_opcode(const int line, const char *opcode);

/* LINKED LIST FUNCTION */

stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_dlistint(stack_t *head);

/* OPCODE FUNCTION */
void (*get_op_func(char *opcode))(stack_t **, unsigned int);

void push(stack_t **stack, unsigned int line);
void pall(stack_t **stack, unsigned int line);
void pop(stack_t **stack, unsigned int line);
void pint(stack_t **stack, unsigned int line);
void nop(stack_t **stack, unsigned int line);


#endif
