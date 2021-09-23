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
	char *delim = " \n*~$%)\r(\t";
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
		/**
		 * I should call a function that tokenizes each line and pass the token to a function pointer that
		 * selects which function should use
		 */
		token = strtok(line, delim);
		/*maybe check if token null here??????*/
		//printf("line:%d, %s\n",(line_count + 1), token);
		if(strcmp(token, "push") == 0)
		{
			/*check with isdigit if the rest of the line has a number
			 *create a function that uses isdigit named int check_num(int), that returns the number if it is a digit and 0(false) if not
			*/
			token = strtok(NULL, delim);

			if (token == NULL)
			{
				free(line);
				fprintf(stderr, "L%d: usage: push integer\n", line_count);
				exit (EXIT_FAILURE);
			}
			while (token != NULL)
			{
				token = strtok(NULL, delim);
				if (atoi(token) != 0)
				{
					printf("trying to push: %d\n", atoi(token));
					break;
				}
			}
		}
		else if (strcmp(token, "pall") == 0)
			printf("I should print the stack!\n");
		/*this is to keep track of the line count*/
		line_count++;
	}
	/*free line after we don't need it anymore*/
	free(line);
	fclose(fp);
}
