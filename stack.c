#include "monty.h"
/**
*stack - print stack
*@line_number: www
*@stack: pointer
*Return: Nothing
*
*
*
*
*
*
*
*/
void stack(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
stack_t *current = *stack;

if (stack == NULL || *stack == NULL)
return;

while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
}
}
