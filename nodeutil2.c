#include "monty.h"

/**
 *swap - swaps top to elemens of stack
 *@stack: stacked data struct
 *@line_number: line num
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *node_next, *head;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	head = *stack;
	node_next = head->next;
	if (node_next->next == NULL)
	{
		node_next->prev = NULL;
		node_next->next = head;
		head->next = NULL;
		head->prev = node_next;
		*stack = node_next;
	}
	else
	{
		node_next->next->prev = head;
		head->next = node_next->next;
		head->prev = node_next;
		node_next->next = head;
		node_next->prev = NULL;
		*stack = node_next;
	}
}
/**
 *add - add first two elemens of stack
 *@stack: data structure
 *@line_number: line num
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = *stack;
		*stack = temp->next;
		(*stack)->n += temp->n;
		(*stack)->prev = temp->prev;
		free(temp);
	}
}
/**
 *nop - does nothing
 *@stack: does nothing here
 *@line_number: does nothing here
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
