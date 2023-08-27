#include "main.h"

/**
*pall - function that prints all elements in a stack
*@line_number: will not be used , we usse attribute not void
*@stack: pointer to the doubly linked list
*Return: void
*/

void pall(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	stack_t *curr = *stack;

	if (stack == NULL || *stack == NULL)
		return;

	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}
