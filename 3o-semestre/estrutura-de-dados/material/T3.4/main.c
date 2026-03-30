#include <stdio.h>

#include "clientes.h"

int main(void)
{
    Cliente clientes[MAX_CLIENTES]; // i guess this won't be needed for this exercise
    gerarDeArquivo("clientes.csv", clientes);

    delete("clientes.csv", 5);
}