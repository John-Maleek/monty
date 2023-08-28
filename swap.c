#include "monty.h"

/**
* swap - swaps the value of the top two elements
* @stack: pointer to the stack
* @line_number: line number of instruction
* Return: void, exit with -1 on failure
**/

void swap(stack_t **stack, unsigned int line_number)
{
	int val;

	if (len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	val = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = val;
}
