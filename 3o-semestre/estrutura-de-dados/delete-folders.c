#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    system("rmdir folder");
    system("rmdir another-folder");

    system("cls");

    printf("displaying results!\n");
    system("dir");
}