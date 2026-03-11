#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "fracao.h"

Fracao criarFracao(int N, int D)
{
    Fracao F;
    F.num = N; F.den = D;
    
    return F;
}

void exibirFracao(Fracao F)
{
    printf("%i\n-\n%i\n", F.num, F.den);
}

int MDC(int a, int b)
{
    int resto = a % b;
    while (resto != 0)
    {
        a = b; b = resto;
        resto = a % b;
    }
    
    return b;
}

Fracao simplificarFracao(Fracao F)
{
    int mdc = MDC(F.num, F.den);

    F.num = F.num / mdc;
    F.den = F.den / mdc;

    return F;
}