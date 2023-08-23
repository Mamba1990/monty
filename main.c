#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
bus_t buss = {NULL, NULL, NULL, 0};
/**
* main - the code interpreter
* @argc: arguments' number
* @argv: file's location
* Return: 0 always
*/
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t readLine = 1;
	stack_t *st = NULL;
	unsigned int ct = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	buss.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (readLine > 0)
	{
		content = NULL;
		readLine = getline(&content, &size, file);
		buss.cont = content;
		ct++;
		if (readLine > 0)
		{
			op_exec(content, &st, ct, file);
		}
		free(content);
	}
	freeStack(st);
	fclose(file);
return (0);
}
