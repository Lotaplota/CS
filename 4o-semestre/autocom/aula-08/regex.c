#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    FILE * fp = fopen("bd.csv", "r");

    char Nome[50];
    char Telefone[20];

    fscanf(fp, "%[^;];%[^\n]", Nome, Telefone); // It works, but I feel there's a bug...
    printf("%s\t%s", Nome, Telefone);
}