#include "monty.h"

/**
 * is_number - Check if a string is a number
 * @str: String to check
 * Return: 1 if true, 0 if false
 */
int is_number(char *str)
{
    if (!str)
        return (0);
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == '-' && i == 0) /* Allow negative sign */
            continue;
        if (!isdigit(str[i]))
            return (0);
    }
    return (1);
}

/**
 * free_stack - Frees a stack
 * @stack: Stack to free
 */
void free_stack(stack_t *stack)
{
    stack_t *temp;

    while (stack)
    {
        temp = stack->next;
        free(stack);
        stack = temp;
    }
}
