#include "monty.h"
/**
 *read_textfile - parses through each line of a file looking for monty code
 *@filename: contains monty code
 */
void read_textfile(const char *filename)
{
	char *delim = " \n*~$%)(\t\r", *line = NULL, *token = NULL;
	size_t line_size = 0;
	int line_count = 1;
	FILE *fp = fopen(filename, "r");
	stack_t *node = NULL;

	if (!fp)
		nofile(filename);
	while (getline(&line, &line_size, fp) != EOF)
	{
		token = strtok(line, delim);
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, delim);
			if (token == NULL)
			{
				fclose(fp);
				push_error_handler(line_count, line);
			}
			if (check_num(token) == 0)
			{
				func_selec("push")(&node, atoi(token));
			}
			else if (check_num(token) == 1)
			{
				fclose(fp);
				push_error_handler(line_count, line);
			}
		}
		else
		{
			func_selec(token)(&node, line_count);
		}
		line_count++;
	}
	free_list(node);
	free(line);
	fclose(fp);
}
/**
 *nofile - error when no file
 *@filename: name of file
 */
void nofile(char *filename)
{
	fprintf(stderr, "Error: can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}
