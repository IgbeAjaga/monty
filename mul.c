#include "monty.h"

/**
 * mul_op - Multiplies the second top element of the stack by the top element.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the opcode.
 */
void mul_op(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}

