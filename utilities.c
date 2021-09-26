#include "monty.h"
/**
 *check_num - function that parses through token to check if there is a digit
 *@token: the token that should contain an int
 *Return: 0 if num found 1 otherwise
 */
int check_num(char *token)
{
	int i;

	for (i = 0; token[i] != '\0'; i++)
	{
		if (isdigit(token[i]) == '-')
		{
			if (isdigit(token[i + 1]) != 0)
				continue;
			else
				return (1);
		}
	}
	return (1);
}
/**
 *push_error_handler - prints to stderr for error with push
 *@line_count: count of lines
 *@line: line of file to be freed
 */
void push_error_handler(int line_count, char *line)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_count);
	free(line);
	exit(EXIT_FAILURE);
}

/**
 * *func_selec - selects proper function according to token
 *@keyword: string that contains func name
 *Return: func to be executed
 */
void (*func_selec(char *keyword))(stack_t **node, unsigned int line_count)
{
	/*fpointer shenanigans here*/
	int i;

	instruction_t fp[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	for (i = 0; fp[i].opcode != NULL; i++)
	{
		if (strcmp(fp[i].opcode, keyword) == 0)
			return (fp[i].f);
	}
	return (NULL);
}

/**
 *free_list - frees up every node of type list_t type
 *@node: pointer to the first node of list_t
 */
void free_list(stack_t *node)
{
	stack_t *temp;

	while (node != NULL)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
}
