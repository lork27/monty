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
		if (isdigit(token[i]) != 0)
		{
			return (0);
		}
	}
	return (1);
}
/**
 *error_handler - prints to stderr
 *@line_count: count of lines
 *@line: line of file to be freed
 */
void error_handler(int line_count, char *line)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_count);
	free(line);
	exit(EXIT_FAILURE);
}
