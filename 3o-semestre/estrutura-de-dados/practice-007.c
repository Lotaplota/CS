#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    fp = fopen("path-to-file.txt", "r");
    if (fp == NULL)
    {
        printf("no\n");
        exit(1);
    }

    char path[100], file[20];

    fscanf(fp, "%[^/]/%[^.]", path, file);

    printf("path: %s\nfilename: %s\n", path, file); // Not working btw...

    fclose(fp);
    return 0;
}