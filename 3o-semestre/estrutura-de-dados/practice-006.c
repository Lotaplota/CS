#include <stdio.h>
#include <stdlib.h>
// Escreva código-fonte em C para ler cada linha de um arquivo e exibi-la na tela.
int main(void)
{
    FILE *fp;
    fp = fopen("text.txt", "r");
    if (fp == NULL)
    {
        printf("no\n");
        exit(1);
    }

    char line[100];

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        printf("%s", line);
    }

    fclose(fp);
    return 0;
}