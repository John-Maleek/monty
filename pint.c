#include "monty.h"

/**
*pint - prints the data at the top of the stack
*@stack: double pointer to the head
*@line_number: number of lines
*Return: void
*/

void pint(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
