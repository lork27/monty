#include "monty.h"
/**
 *push - add node to head
 *@stack: node added
 *@line_number: num to add to node
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = line_number;
	new->prev = NULL;
	if (*stack == NULL)
	{
		new->next = *stack;
		*stack = new;
	}
	else
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
}
/**
 *pall - prints stack
 *@stack: stack to be printed
 *@line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	if (*stack == NULL)
		return;
	tmp = *stack;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 *pint - prints val of node at the top
 *@stack: stack
 *@line_number: line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;

	printf("%d\n", tmp->n);
}
/**
 *pop - removes top element of stack
 *@stack: stack data structure
 *@line_number: line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;

	if (tmp->next != NULL)
	{
		*stack = tmp->next;
		(*stack)->prev = NULL;
		free(tmp);
	}
	else
		free(tmp);
}
