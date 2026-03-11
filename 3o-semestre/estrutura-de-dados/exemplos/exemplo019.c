// This code has a deconstructed version in ./fracao/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Definindo o TAD Fração
typedef struct {
    int num;
    int den;
} Fracao;

// Definindo as OPERAÇÕES do TAD Fração
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

int main(void)
{
    system("cls");

    Fracao F1 = criarFracao(3, 4);
    Fracao F2 = criarFracao(27, 30);

    exibirFracao(F1);
    exibirFracao(F2);
    exibirFracao(simplificarFracao(F2));
}