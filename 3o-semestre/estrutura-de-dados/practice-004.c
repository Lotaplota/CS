#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    fp = fopen("scan-me.txt", "r");
    if (fp == NULL)
    {
        printf("no\n");
        exit(1);
    }

    int fnumber;
    char ftext[100];

    fscanf(fp, "%i %s", &fnumber, ftext);

    printf("number: %i\ntext: %s\n", fnumber, ftext);
}