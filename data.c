#include "monty.h"
/**
*pint - print data
*@stack: double pointer
*@line_number: how many lines
*Return: nothing
*
*
*
*
*
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
