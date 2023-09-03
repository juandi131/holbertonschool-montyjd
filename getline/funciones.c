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
    for (int i = 0; i < len; i++) {
        if (isdigit(line[i])) {
            numero = atoi(line + i);
            return 1;
        }
    }
    return 0;
}
char *eliminarNumeros(char *cadena)
{
    int len = strlen(cadena);
    int i, j = 0;

    for (i = 0; i < len; i++) {
        if (!isdigit(cadena[i])) {
            cadena[j++] = cadena[i];
        }
    }
    cadena[j] = '\0';
    return(cadena);
}
