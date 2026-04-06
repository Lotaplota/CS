#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dmngr.h"

void printPlus(char * word)
{
    char * final = strcat(word, " more");
    printf(final);
}

int main(void)
{
    char * entrada;
    scanf("%s", entrada);

    printPlus(entrada);
}