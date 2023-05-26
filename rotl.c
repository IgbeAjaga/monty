#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the Monty bytecode.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *last;

	(void)line_number;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		last = *stack;

		while (last->next)
			last = last->next;

		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		last->next = first;
		first->prev = last;
		first->next = NULL;
	}
}

