#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the opcode.
 */
#define MODE_STACK 0
#define MODE_QUEUE 1

int is_number(char *str);
int mode = MODE_STACK;

void push(stack_t **stack, int value)
{
	stack_t *new_node;
	stack_t *temp;
	
	new_node = malloc(sizeof(stack_t));

   if (new_node == NULL)
   {
      fprintf(stderr, "Error: malloc failed\n");
      new_node = new_node->next;
      free(temp);
      /*free_stack(*stack);*/
      exit(EXIT_FAILURE);
   }

   new_node->n = value;
   new_node->prev = NULL;
   

   if (*stack != NULL)
   {
      new_node->next = *stack;
      (*stack)->prev = new_node;
   }
   else
   {
      new_node->next = NULL;
   }

   *stack = new_node;
}

/**
 * is_number - Checks if a string is a number.
 * @str: The string to check.
 *
 * Return: 1 if the string is a number, 0 otherwise.
 */
int is_number(char *str)
{
	if (*str == '-' || *str == '+')
		str++;

	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}

	return (1);
}
