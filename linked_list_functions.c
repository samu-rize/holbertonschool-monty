#include "monty.h"
/**
 * add_dnodeint - function that adds a new node
 * at the beginning of a stack_t list
 * @n: number
 * @head: head address
 * Return: new node address
*/
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node = (stack_t *)malloc(sizeof(stack_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	if (*head == NULL)
		new_node->next = NULL;
	else
	{
		new_node->next = *head;
		(*head)->prev = new_node;
	}
	*head = new_node;
	return (new_node);
}
/**
 * add_dnodeint_end - function that adds a new node
 * at the end of a stack_t list
 * @n: number
 * @head: head address
 * Return: new node address
*/
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new_node = (stack_t *)malloc(sizeof(stack_t));


	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	if (*head == NULL)
		*head = new_node;
	else
	{
		stack_t *current = *head;

		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
		new_node->prev = current;
	}

	return (new_node);
}
/**
 * free_dlistint - function that frees a stack_t list.
 * @head: list
 * Return: void
*/
void free_dlistint(stack_t *head)
{
	stack_t *current = head;

	while (current != NULL)
	{
		stack_t *next_node = current->next;

		free(current);

		current = next_node;
	}
}
