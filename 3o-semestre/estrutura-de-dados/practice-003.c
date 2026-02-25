#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    fp = fopen("times-table.txt", "w");

    if (fp == NULL)
    {
        printf("null pointer!\n");
        exit(1);
    }

    int n = 5;

    for (int i = 0; i < 20; i++)
    {
        fprintf(fp, "%i.\t%i * %i\t=\t%i\n", i, n, i, n * i);
    }
}