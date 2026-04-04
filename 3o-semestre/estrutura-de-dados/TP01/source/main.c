#include <stdio.h>
#include <stdlib.h>

#include "dmngr.h"

int main(void)
{
    int qt_arquivos = concatArquivos("../database");
    printf("quantidade de arquivos concatenados: %i\n", qt_arquivos); // DONKEY
}