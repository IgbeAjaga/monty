#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * parse_line - Parses a line of Monty bytecode.
 * @line: Line of Monty bytecode.
 * @stack: It is the stack
 * @line_number: Line number of the bytecode.
 * Return: On success, returns 0. Otherwise, returns -1.
 */
/* #define DELIMITERS " \t\n" */
#define MODE_STACK 0
#define MODE_QUEUE 1

int parse_line(char *line, stack_t **stack, unsigned int line_number)
{
    /* Parse the line and execute the corresponding command */
    if (strncmp(line, "push", 4) == 0)
    {
        /* Extract the value from the line */
        int value = atoi(line + 5);
        push(stack, value);
    }
    else if (strncmp(line, "pop", 3) == 0)
    {
        pop(stack, line_number);
    }
    else if (strncmp(line, "pall", 4) == 0)
    {
        pall(stack, line_number);
    }
    else if (strncmp(line, "add", 3) == 0)
    {
        add(stack, line_number);
    }
    else
    {
        printf("Unknown command at line %u: %s\n", line_number, line);
        /* Handle unrecognized command */
    }

    return 0;
}
