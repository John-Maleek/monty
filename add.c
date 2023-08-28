#include "main.h"

/**
 * add - adds the top two elements of a stack
 * @stack: The head of the stack
 * @line_number: The line on which the error occurred
 *
 * Return: void
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *val = *stack;
	unsigned int x = 0, y = 0, length = 0;

	length = len(*stack);

	if (length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	}

	x = val->n;
	y = val->next->n;
	val->next->n = x + y;
	*stack = val->next;
	free(val);
}
