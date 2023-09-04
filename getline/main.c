#include "monty.h"

int numero;
int error;

int main(int argc, char *argv[])
{
    char *comandos = NULL, *line = NULL;
    size_t bufsize = 0;
    ssize_t bytesRead;
    unsigned int linea = 0;
    stack_t *nod = NULL;
	stack_t **stack = &nod;

    error = 0;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
    FILE *file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
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
                error = 0;
                free(cleanedToken);
            }
            token = strtok(NULL, "$\n");
        }
    }
    free(line);
    fclose(file);
    return 0;
}