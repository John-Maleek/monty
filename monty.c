#include "main.h"

/**
  * main - The Monty Interpreter entry point
  * @argc: number of args
  * @argv: args passed to the interpreter
  *
  * Return: Always 0
  */

int main(int argc, char const *argv[])
{
    stack_t *stack = NULL, *curr;
    int line_number = 0;
    int read;
    char *buff = NULL, *opcode, *n;
    size_t lol = 0;
    FILE *fd;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return (EXIT_FAILURE);
    }

    fd = fopen(argv[1], "r");
    if (fd == NULL)
    {
        fprintf(stderr, "Error: can't open file %s\n", argv[1]);
        exit(1);
    }

    while ((read = getline(&buff, &lol, fd)) != -1)
    {
        line_number++;
        opcode = strtok(buff, DELIMATOR);
        if (opcode == NULL || opcode[0] == '#')
            continue;
        if (!strcmp(opcode, "nop"))
            continue;
        else if (!strcmp(opcode, "push"))
        {
            n = strtok(NULL, DELIMATOR);
            push(&stack, n, line_number);
        }
        else
        {
            get_opcode(&stack, opcode, line_number);
        }
    }
    fclose(fd);
    free(buff);
    while (stack != NULL)
    {
        curr = stack;
        stack = stack->next;
        free(curr);
    }
    return (0);
}
