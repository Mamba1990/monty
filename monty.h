#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct busS - struture of var, args, file, line 
 * @arg: value
 * @file: pointer to monty file
 * @cont: line content
 * @lf: flag to change stack/queue
 * Description: program's values carrier
 */
typedef struct stc_bus
{
	char *arg;
	FILE *file;
	char *cont;
	int lf;
}  bus_t;
extern bus_t buss;

/* Caluclation functioons */
/* 1 */
void _add_(stack_t **h, unsigned int ct);
void _sub_(stack_t **h, unsigned int ct);
/* 2 */
void _mul_(stack_t **h, unsigned int ct);
void _div_(stack_t **h, unsigned int ct);

/* push-pall-pint functions */
void _push_(stack_t **h, unsigned int ct);
void _pall_(stack_t **h, unsigned int ct);
void _pint_(stack_t **h, unsigned int ct);
/* pop- */
void _pop_(stack_t **h, unsigned int ct);
#endif
