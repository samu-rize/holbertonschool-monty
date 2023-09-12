#include "monty.h"
/**
 * pint - print the value of the top of the stack.
 * @stack:the stack
 * @line: line number.
 * Return: void
*/
void pint(stack_t **stack, unsigned int line)
{
	if (*stack == NULL || stack == NULL)
	{
        error_exit_d("L%u: can't pint, stack empty\n", line, EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - remove the top element of the stack.
 * @stack:the stack
 * @line: line number.
 * Return: void
*/
void pop(stack_t **stack, unsigned int line)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}

	stack_t *temp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
}
/**
 * nop - doesn't do anything.
 * @stack:the stack
 * @line: line number.
 * Return: void
*/
void nop(stack_t **stack, unsigned int line)
{
	(void)line;
	(void)stack;
}
