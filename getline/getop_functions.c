#include "monty.h"


/**
 * m_push - pushes an element to the stack
 * @stack: the stack to add the elements to
 * @line_number: the line number of the command
*/
void m_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	stack_t *aux;

	(void)line_number;
	if (stack == NULL)
		return;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		freeList(*stack);
		fprintf(stderr, "Error: malloc failed\n");
		_exit(EXIT_FAILURE);
	}

	if (*stack != NULL)
	{
		aux = *stack;
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = new;
		new->prev = aux;
	}
	else
		*stack = new;
	new->next = NULL;
	new->n = numero;
}

/**
 * m_pall - prints all the values on the stack, starting from the top
 * @stack: the stack to print
 * @line_number: the line number of the command
*/
void m_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
		return;
	(void)line_number;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	while (temp->prev != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}
	printf("%d\n", temp->n);
}
/**
 * freeExit - functions made because of betty
 * @token: the string for the error message
 * @buff: the buff to free
 * @line: the line number
 * @stack: the stack to free
*/
void freeExit(char *buff, stack_t **stack, int line, char *token)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line, token);
	free(buff);
	freeList(*stack);
	_exit(EXIT_FAILURE);
}
/**
 * freeList - free a linked list
 * @stack: the list to free
*/
void freeList(stack_t *stack)
{
	if (stack != NULL)
	{
		if (stack->next != NULL)
			freeList(stack->next);
		free(stack);
	}
}
