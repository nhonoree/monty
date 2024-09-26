#include "monty.h"

int global_variable = 0;

void free_stack(stack_t *stack);

/**
 * main - Entry point for Monty interpreter
 * @argc: Argument count
 * @argv: Argument vector
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error
 */
int main(int argc, char **argv)
{
    FILE *file;
    char *line = NULL, *opcode, *arg;
    size_t len = 0;
    unsigned int line_number = 0;
    stack_t *stack = NULL;
    instruction_t instructions[] = {
        {"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop},
        {"swap", swap}, {"add", add}, {"nop", nop}, {NULL, NULL}
    };
    int i;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return (EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return (EXIT_FAILURE);
    }

    while (getline(&line, &len, file) != -1)
    {
        line_number++;
        opcode = strtok(line, " \t\n");
        if (opcode && opcode[0] != '#')  /* Ignore comments */
        {
            arg = strtok(NULL, " \t\n");

            for (i = 0; instructions[i].opcode; i++)
            {
                if (strcmp(opcode, instructions[i].opcode) == 0)
                {
                    instructions[i].f(&stack, line_number);
                    break;
                }
            }

            if (!instructions[i].opcode)
            {
                fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
                free_stack(stack);
                fclose(file);
                free(line);
                return (EXIT_FAILURE);
            }
        }
    }

    free_stack(stack);
    fclose(file);
    free(line);
    return (EXIT_SUCCESS);
}
