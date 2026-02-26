#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    fp = fopen("dados.csv", "r");
    if (fp == NULL)
    {
        printf("no\n");
        exit(1);
    }

    int ID, idade;
    char nome[20];

    fscanf(fp, "%*[^,],%*[^,],%*s");
    while (fscanf(fp, "%i,%19[^,],%d", &ID, nome, &idade) == 3)
    {
        printf("ID: %i, Nome: %s, Idade: %i\n", ID, nome, idade);
    }

    fclose(fp);
    return 0;
}