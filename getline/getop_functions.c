#include "monty.h"


/**
 * m_push - pushes an element to the stack
 * @stack: the stack to add the elements to
 * @line_number: the line number of the command
*/
void m_push(stack_t **stack, unsigned int linea)
 {
	stack_t *new;
	stack_t *aux;

	(void)linea;
    new = malloc(sizeof(stack_t));
	if (stack == NULL)
		return;
    if (new == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
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
void m_pall(stack_t **stack, unsigned int linea)
{
	stack_t *temp;

	if (*stack == NULL)
		return;
	(void)linea;
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
