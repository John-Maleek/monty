#include "main.h"

/**
  * len - counts the number of elements in a stack
  * @stack: The stack to be counted
  *
  * Return: lenght of the stack
  */

unsigned int len(stack_t *stack)
{
	stack_t *curr = stack;
	unsigned int lenght = 0;

	while (curr != NULL)
	{
		++lenght;
		curr = curr->next;
	}

	return (lenght);
}
