#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    system("dir");

    printf("creating folders...\n");
    system("mkdir folder");
    system("md another-folder");
    printf("folders created!\n");

    system("dir");
}