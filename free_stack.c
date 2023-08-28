#include "monty.h"

/**
* free_stack - frees the stack
* @stack: pointer to stack
*
* Return: Void
**/

void free_stack(stack_t *stack)
{
    stack_t *next;

    while (stack != NULL)
    {
        next = stack->next;
        free(stack);
        stack = next;
    }
}
