#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    fp = fopen("file-to-write.txt", "w");

    if (fp == NULL)
    {
        printf("null pointer!\n");
        exit(1);
    }

    int n = 4;
    char *text = "th written text!\nAnd the pointer wasn't null :^]";

    fprintf(fp, "%i%s", n, text);

    fclose(fp);
}