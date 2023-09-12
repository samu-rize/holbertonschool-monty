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
/**
 * swap -swap the top two elements of the stack.
 * @stack: pointer to the top of the stack.
 * @line_number: current number in the script.
 *
 * Return: void.
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		error_exit_d("L%u: can't swap, stack too short\n",
		line_number, EXIT_FAILURE);
	}
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = (*stack);
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}
/**
 * add -adds the top two elements of the stack.
 * @stack: pointer to the top of the stack.
 * @line_number: current number in the script.
 *
 * Return: void.
*/
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		error_exit_d("L%u: can't add, stack too short\n", line_number, EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
