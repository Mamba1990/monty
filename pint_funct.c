#include "monty.h"
/**
 * _pint_ - displayss the top
 * @h: head of stack
 * @ct: number's line
 * Return: nothing
*/
void _pint_(stack_t **h, unsigned int ct)
{
	if (*h == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", ct);
		fclose(buss.file);
		free(buss.cont);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*h)->n);
}
