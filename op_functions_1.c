#include "monty.h"
/**
 * push - push element in the stack.
 * @stack: the stack
 * @line: line number.
 * Return: void
*/
void push(stack_t **stack, unsigned int line)
{
	(void)line;
	int value = atoi(arg);

	add_dnodeint(stack, value);

}

/**
 * pall - print all element of the stack.
 * @stack: the stack
 * @line: line number.
 * Return: void
*/
void pall(stack_t **stack, unsigned int line)
{
	(void)line;

	if (*stack == NULL)
		return;
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
