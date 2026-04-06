#include <stdio.h>
#include <stdlib.h>

#include "dmngr.h"

int main(void)
{
    int qt_arquivos = ConcatArquivos("../database", "dados.csv");

    GerarResumo("dados.csv", qt_arquivos);
}