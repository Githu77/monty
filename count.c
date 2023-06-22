#include "monty.h"

/**
* count - length
* @stack: pointer
* Return: unsigned int
*
*
*
*
*
*
*
*/
unsigned int count(stack_t **stack)
{
stack_t *current;
unsigned int x = 0;

current = *stack;
while (current)
{
current = current->next;
x++;
}
return (l);
}
