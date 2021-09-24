#include "monty.h"
/**
 * main - check the code
 * @ac: argument count
 * @av: arguments passed
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	if (ac != 2)
	{
		fprintf(stderr, "Usage: %s filename\n", av[0]);
		exit(EXIT_FAILURE);
	}
	read_textfile(av[1]);
	return (0);
}

