#include "monty.h"
#include <ctype.h>
#include <string.h> 

int numero;
int main(int argc, char *argv[])
{
    char *comandos = NULL, *line = NULL;
    size_t bufsize = 0;
    ssize_t bytesRead;
    unsigned int linea = 0;
    stack_t *nod = NULL;
	stack_t **stack = &nod;

    if (argc != 2) {
        printf("Uso: %s <nombre_archivo>\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }
    while ((bytesRead = getline(&line, &bufsize, file)) != -1) {
        char *token = strtok(line, "$\n");
        while (token != NULL) {
            char *cleanedToken = malloc(strlen(token) + 1);
            //insertar error del malloc
            if (cleanedToken) {
                int j = 0;
                for (int i = 0; token[i] != '\0' ; i++)
                {
                    if (token[i] != ' ')
                    {
                        cleanedToken[j++] = token[i];
                    }
                }
                cleanedToken[j] = '\0';
                linea++;
                contieneNumero(cleanedToken);
                comandos = eliminarNumeros(cleanedToken);
                serch_the_function(comandos, stack, linea);
                free(cleanedToken);
            }
            token = strtok(NULL, "$\n");
        }
    }
    free(line);
    fclose(file);
    return 0;
}