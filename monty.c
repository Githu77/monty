#include "monty.h"


/**
* find_opcode - find opcode
* @stack: pointer
* @opcode: input
* @line_number: line
* Return: Always 1 / stderr
*
*
*
*
*
*/
int find_opcode(stack_t **stack, char *opcode, int line_number)
{
instruction_t opcodes[] = {
{"stck", stck},
{"rem", rem},
{"swap", swap},
{"data", data},
{NULL, NULL}
};

int x;

for (x = 0; opcodes[x].opcode; x++)
{
if (strcmp(opcode, opcodes[x].opcode) == 0)
{
(opcodes[x].f)(stack, line_number);
return (EXIT_SUCCESS);
}
}
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
exit(EXIT_FAILURE);
}


/**
* main - Process byte codes
* @argc: size of argv
* @argv: double poin
* Return: EXIT_SUCCESS
*
*
*
*
*
*/

int main(__attribute__((unused)) int argc, char const *argv[])
{
FILE *mf;
char *buff = NULL, *opcode, *n;
size_t lol = 0;
int line_number = 0;
stack_t *stack = NULL, *current;

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
return (EXIT_FAILURE);
}
mf = fopen(argv[1], "r");
if (mf == NULL)
{
fprintf(stderr, "Error: can't open file %s\n", argv[1]);
exit(1);
}
while ((getline(&buff, &lol, mf)) != -1)
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
add(&stack, n, line_number);
}
else
find_opcode(&stack, opcode, line_number);
}
fclose(mf);
free(buff);
while (stack != NULL)
{
current = stack;
stack = stack->next;
free(current);
}
return (0);
}

/**
* free_stack - frees stack
* @stack: pointer
*
*
*
*
*
*/
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
