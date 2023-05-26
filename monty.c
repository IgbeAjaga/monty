#include "monty.h"

/**
 * parse_line - Parses a line of Monty bytecode.
 * @line: Line of Monty bytecode.
 * @line_number: Line number of the bytecode.
 * Return: On success, returns 0. Otherwise, returns -1.
 */
#define DELIMITERS " \t\n"
#define MODE_STACK 0
#define MODE_QUEUE 1

void mul(stack_t **stack, unsigned int line_number);

int parse_line(char *line, unsigned int line_number)
{
	char *opcode = NULL;
	int arg = 0;
	stack_t *stack = NULL;
		
	opcode = strtok(line, DELIMITERS);
	if (opcode == NULL || opcode[0] == '#') /* Ignore empty lines and comments */
		return 0;

	if (strcmp(opcode, "push") == 0)
	{
		char *arg_str = strtok(NULL, DELIMITERS);

		if (arg_str == NULL)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		arg = atoi(arg_str);
		push(&stack, arg);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(&stack, line_number);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		pint(&stack, line_number);
	}
	else if (strcmp(opcode, "pop") == 0)
	{
		pop(&stack, line_number);
	}
	else if (strcmp(opcode, "swap") == 0)
	{
		swap(&stack, line_number);
	}
	else if (strcmp(opcode, "add") == 0)
	{
		add(&stack, line_number);
	}
	else if (strcmp(opcode, "nop") == 0)
	{
		/* Do nothing */
	}
	else if (strcmp(opcode, "sub") == 0)
	{
		sub(&stack, line_number);
	}
	else if (strcmp(opcode, "div") == 0)
	{
		div_op(&stack, line_number);
	}
	else if (strcmp(opcode, "mul") == 0)
	{
		mul(&stack, line_number);
	}
	else if (strcmp(opcode, "mod") == 0)
	{
		mod_op(&stack, line_number);
	}
	else if (strcmp(opcode, "pchar") == 0)
	{
		pchar(&stack, line_number);
	}
	else if (strcmp(opcode, "pstr") == 0)
	{
		pstr(&stack, line_number);
	}
	else if (strcmp(opcode, "rotl") == 0)
	{
		rotl(&stack, line_number);
	}
	else if (strcmp(opcode, "rotr") == 0)
	{
		rotr(&stack, line_number);
	}
	else if (strcmp(opcode, "stack") == 0)
	{
		mode = MODE_STACK;
	}
	else if (strcmp(opcode, "queue") == 0)
	{
		mode = MODE_QUEUE;
	}
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}

	return 0;
}

