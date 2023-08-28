#include "main.h"
/**
*push - adds a new node to the stack
*@stack: pointer to a pointer to the doubly linked list
*@line_number: line where there is an error
*Return: void
*/

void push(stack_t **stack, char *n, unsigned int line_number)
{
	stack_t *new_node = NULL;
	int i;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (n == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 0; n[i]; i++)
	{
		if (n[0] == '-' && i == 0)
			continue;
		if (n[i] < 48 || n[i] > 57)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	new_node->n = atoi(n);
	new_node->prev = NULL;
	new_node->next = NULL;
	if (*stack != NULL)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
