#include "monty.h"
/*File for the advanced tasks functions*/

/**
 *sub - sub the top two element from the stack
 *@stack: sequencial data structure
 *@line_number: line num
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = *stack;
		*stack = temp->next;
		(*stack)->n = temp->n - (*stack)->n;
		(*stack)->prev = temp->prev;
		free(temp);
	}
}
/**
 *division - divides top two elements from stack
 *@stack: the stack of nodes
 *@line_number: line number from which div was called
 */
void division(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = *stack;
		*stack = temp->next;
		(*stack)->n = temp->n / (*stack)->n;
		(*stack)->prev = temp->prev;
		free(temp);
	}
}
/**
 *multiplication - multiplies top two elements from stack
 *@stack: the stack of nodes
 *@line_number: line number from which div was called
 */
void multiplication(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = *stack;
		*stack = temp->next;
		(*stack)->n = temp->n * (*stack)->n;
		(*stack)->prev = temp->prev;
		free(temp);
	}
}
/**
 *mod - gives the rest of the division of the top two elements of stack
 *@stack: the stack
 *@line_number: line from which mod was called
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);

	}
	else
	{
		temp = *stack;
		*stack = temp->next;
		(*stack)->n = temp->n % (*stack)->n;
		(*stack)->prev = temp->prev;
		free(temp);
	}
}

