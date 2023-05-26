#include "monty.h"

/**
 * add_node_top - add node to the top.
 * @stack: Double pointer to the stack.
 * @n: Integer.
 * @stack_t: stack.
 */
void add_node_top(stack_t **stack, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * add_node_end - add node to the end.
 * @stack: Double pointer to the stack.
 * @n: Integer.
 * @stack_t: stack.
 */
void add_node_end(stack_t **stack, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*stack == NULL)
	{
		*stack = new_node;
	}
	else
	{
		stack_t *current = *stack;
		while (current->next != NULL)
			current = current->next;

		current->next = new_node;
		new_node->prev = current;
	}
}

