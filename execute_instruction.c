#include "monty.h"

/**
 * execute_instruction - Match the opcode and execute the corresponding function
 * @opcode: The opcode to execute
 * @stack: Double pointer to the stack
 * @line_number: The line number of the command
 * @arg: Argument for the push opcode
 */
void execute_instruction(char *opcode, stack_t **stack, unsigned int line_number, char *arg)
{
    instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL}
    };

    int i = 0;

    while (instructions[i].opcode)
    {
        if (strcmp(opcode, instructions[i].opcode) == 0)
        {
            if (strcmp(opcode, "push") == 0)
                instructions[i].f(stack, line_number, arg);
            else
                instructions[i].f(stack, line_number);
            return;
        }
        i++;
    }

    fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}
