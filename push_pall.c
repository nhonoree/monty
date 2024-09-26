#include "monty.h"

/**
 * push - Push an integer onto the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the command
 * @arg: The argument to push
 */
void push(stack_t **stack, unsigned int line_number, char *arg)
{
    stack_t *new_node;
    int num;

    if (!arg || (sscanf(arg, "%d", &num) != 1))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = num;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;
}

/**
 * pall - Print all the values on the stack, starting from the top
 * @stack: Double pointer to the stack
 * @line_number: Line number of the command
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;
    (void)line_number;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
