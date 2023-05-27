#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

int main(void)
{
   stack_t *stack = NULL;
   char line[] = "push 5";
   unsigned int line_number = 1;

   /* Example usage of push() from push.c */
   printf("Pushing values onto the stack...\n");
   push(&stack, 5);
   push(&stack, 10);

   add(&stack, 3);

   /* Example usage of pall() from pall.c */
   printf("Printing all values in the stack...\n");
   pall(&stack, 4);

   /* Free the stack memory */
   free_stack(stack);

   /* Example usage of pop() from pop.c */
   printf("Popping values from the stack...\n");
   pop(&stack, 1);
   pop(&stack, 2);

   /* Example usage of parse_line() from monty.c */
   printf("Parsing and executing Monty bytecode...\n");
   parse_line(line, &stack, line_number);

   return 0;
}

