#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculadora.h"

int main(void)
{
    Expressao E;
    strcpy(E.posFixa, "2 3 + log 5 /");

    E.Valor = getValor(E.posFixa);
    strcpy(E.inFixa, getInFixa(E.posFixa));
    printf("resultado: %f\n", E.Valor); // DONKEY
}