#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "clientes.h"

void gerarDeArquivo(char * filename, Cliente * arr)
{
    FILE * fr = fopen(filename, "r");
    if (!fr) { perror("error reading from file"); return; }

    char buffer[1024];
    fgets(buffer, sizeof(buffer), fr);

    int i = 0;
    while (fgets(buffer, sizeof(buffer), fr))
    {
        Cliente aux;
        sscanf(buffer, "%i,%[^,],%[^,]", &aux.ID, aux.nome, aux.email);

        arr[i] = aux;
        i++;
    }

    fclose(fr);
}

void delete(char * filename, int id)
{
    // Preparing file to read contents from
    FILE * arquivo = fopen("clientes.csv", "r");
    if (!arquivo) { perror("Arquivo naum encontrado.\n"); return; }

    // Preparing file to save contents to
    FILE * temp = fopen("temp.csv", "w");
    if (!temp) { perror("Arquivo naum encontrado.\n"); return; }
    fprintf(temp, "ID,Nome,Email\n"); // Printing the header

    char buffer[1024];
    fgets(buffer, sizeof(buffer), arquivo);

    int i = 0;
    while(fgets(buffer, sizeof(buffer), arquivo))
    {
        Cliente cur;
        sscanf(buffer, "%i,%[^,],%[^,]", &cur.ID, cur.nome, cur.email);

        if (cur.ID != id)
        {
            fprintf(temp, "%i,%s,%s", cur.ID, cur.nome, cur.email);
        }

        i++;
    }

    fclose(arquivo);
    fclose(temp);

    remove("clientes.csv");
    rename("temp.csv", "clientes.csv");
}