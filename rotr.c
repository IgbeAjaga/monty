#include "monty.h"

/**
 * rotr - Rotates the stack to the bottom.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the Monty bytecode.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last;

	(void)line_number;

	if (*stack && (*stack)->next)
	{
		last = *stack;

		while (last->next)
			last = last->next;

		last->prev->next = NULL;
		last->next = *stack;
		last->prev = NULL;
		(*stack)->prev = last;
		*stack = last;
	}
}

