#include "monty.h"
#include <stdio.h>

int main(void) {
    stack_t *stack = NULL;
    char *line = NULL;
    size_t line_len = 0;
    unsigned int line_number = 0;
    int ret;

    while (getline(&line, &line_len, stdin) != -1) {
        line_number++;
        ret = parse_line(line, line_number, &stack);
        if (ret == -1) {
            fprintf(stderr, "Error: Failed to parse line %u\n", line_number);
            break;
        }
    }

    free_stack(stack);
    free(line);
    return 0;
}
