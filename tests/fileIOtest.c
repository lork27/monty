#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <string.h>
#include <ctype.h>

int check_num(char *token, int line);
void read_textfile(const char *filename);
/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
    if (ac != 2)
    {
        dprintf(2, "Usage: %s filename\n", av[0]);
        exit(1);
	}
	read_textfile(av[1]);
    return (0);
}

void read_textfile(const char *filename)
{
	/*this string will hold all the characters we don't want*/
	char *delim = " \n*~$%)(\t\r";
	/* These lines open the file for reading */
	char *line = NULL;
	size_t line_size = 0;
	int line_count = 1;
	FILE *fp = fopen(filename, "r");
	char *token = NULL;

	if (!fp)
	{
		fprintf(stderr, "Error: can't open file %s\n", filename);
		return;
	}
	/*get the first line of the file*/
	/*loop thru until file ends*/

	while (getline(&line, &line_size, fp) != EOF)
	{
		token = strtok(line, delim);
		//printf("line:%d, %s\n",(line_count + 1), token);
		if(strcmp(token, "push") == 0)
		{
			/*check with isdigit if the rest of the line has a number
			 *create a function that uses isdigit named int check_num(int), that returns the number if it is a digit and 0(false) if not
			 */
			/*edge case: if there is nothing after push what happens?*/
			token = strtok(NULL, delim);
			if (token == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_count);
				free(line);
				exit (EXIT_FAILURE);
			}
			if (check_num(token, line_count) == 0)
			{
				/*check if atoi(token) is digit, if not keep tokenizing until isdigit or null*/
				printf(": %d\n", atoi(token));
			}
		}
		if (strcmp(token, "pall") == 0)
		{
			printf("I should print the stack!\n");
		}
		/*this is to keep track of the line count*/
		line_count++;
	}
	/*free line buffer*/
	free(line);
	fclose(fp);
}

int check_num(char *token, int line)
{
	int i;
	
	for (i = 0; token[i] != '\0'; i++)
	{
		if(isdigit(token[i]) != 0)
		{
			printf("is a number ");
			return(0);
		}
	}
	fprintf(stderr, "L%d: usage: push integer\n", line);
	exit (EXIT_FAILURE);
}
