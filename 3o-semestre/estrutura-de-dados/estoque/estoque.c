#include <stdio.h>
#include <stdlib.h>

#include "estoque.h"

int update(char * filename, char * name, int qt, float price)
{
    FILE * fr = fopen(filename, "r");
    if (!fr) { perror("error on fopen function"); return -1; }

    // DONKEY CONTINUE
}