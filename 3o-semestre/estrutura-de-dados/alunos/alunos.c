#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 32
#define MAX_ALUNOS 100

typedef struct
{
    char nome[MAX_NAME_LENGTH];
    float n1;
    float n2;
} Aluno;

int alunosAprovados(char * filename, char ** arr)
{
    Aluno * alunos = malloc(MAX_ALUNOS * sizeof(Aluno));
    FILE * fr = fopen(filename, "r");

    char buffer[1024];
    
    // Discarding first line
    fgets(buffer, sizeof(buffer), fr);
    
    int i = 0;
    while (fgets(buffer, sizeof(buffer), fr) != NULL)
    {
        sscanf(buffer, "%[^,],%f,%f", alunos[i].nome, &alunos[i].n1, &alunos[i].n2);
        i++;
    }
    
    int qt_aprov = 0;
    for (int i = 0; i < MAX_ALUNOS; i++)
    {
        if ((alunos[i].n1 + alunos[i].n2) / 2 >= 7)
        {
            arr[qt_aprov] = strdup(alunos[i].nome); // Must be used on char ** logic
            qt_aprov++;
        }
    }

    fclose(fr); free(alunos);
    return qt_aprov;
}

int main(void)
{
    char ** aprovados = malloc(MAX_ALUNOS * sizeof(char *));

    int qtAprovados = alunosAprovados("alunos.csv", aprovados);
    for (int i = 0; i < 4; i++)
    {
        printf("%s\n", aprovados[i]);
    }

    free(aprovados);
}