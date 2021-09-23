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

	if (!fp)
	{
		fprintf(stderr, "Error: can't open file %s\n", filename);
		return;
	}
	while (getline(&line, &line_size, fp) != EOF)
	{
		token = strtok(line, delim);
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, delim);
			if (token == NULL)
				error_handler(line_count, line);
			if (check_num(token) == 0)
				printf(": %d\n", atoi(token));
			else if (check_num(token) == 1)
				error_handler(line_count, line);
		}
		if (strcmp(token, "pall") == 0)
		{
			printf("I should print the stack!\n");
		}
		line_count++;
	}
	free(line);
	fclose(fp);
}