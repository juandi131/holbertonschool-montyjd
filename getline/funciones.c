#include "monty.h"

void serch_the_function(char *cleaned_token, stack_t **stack, unsigned int line_number)
{
    instruction_t op[] = {
        {"push", m_push},
        {"pall", m_pall},
        {NULL, NULL}
    };

    for (int i = 0; op[i].opcode != NULL; i++) {
        if (strcmp(op[i].opcode, cleaned_token) == 0) {
            op[i].f(stack, line_number);
            return;
        }
    }

    printf("Error: Comando desconocido en la línea %u: %s\n", line_number, cleaned_token);

}
int contieneNumero(const char *line)
{
    int len = strlen(line);
    for (int i = 0; i < len; i++)
    {
        if (isdigit(line[i])) {
            numero = atoi(line + i);
            return 1;
        }
    }
    return 0;
}
int error_numeros(const char *line)
{
    int len = strlen(line);
    int a = 0;

    for (int i = 0; i < len; i++)
    {
        if (isdigit(line[i])) {
            a++;
        }
    }
    if (a != 0)
    {
        fprintf(stderr, "L%d: usage: push integer\n", linea);
		exit(EXIT_FAILURE);
    }
    return 0;
}
char *eliminarNumeros(char *cadena)
{
    int len = strlen(cadena);
    int i, j = 0;
    char *push = "push";

    for (i = 0; i < len; i++)
    {
        if (!isdigit(cadena[i]))
        {
            cadena[j++] = cadena[i];
        }
    }

    cadena[j] = '\0';

    return(cadena);
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