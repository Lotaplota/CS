#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculadora.h"

int main(void)
{
    Expressao E;
    strcpy(E.posFixa, "3 16 26 + 2 * /");

    getValor(E.posFixa);
}