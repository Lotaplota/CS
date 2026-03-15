// This code has a deconstructed version in ./fracao/

#include <stdio.h>
#include <stdlib.h>

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
    if (F.num >= 0)
        printf("%i\n-\n%i\n", F.num, F.den);
    else
        printf("  %i\n- -\n  %i\n", F.num * -1, F.den);
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

Fracao somarFracao(Fracao f, Fracao g)
{
    Fracao r = {f.num * g.den + g.num * f.den, f.den * g.den};

    return simplificarFracao(r);
}

Fracao subtrairFracao(Fracao f, Fracao g)
{
    g.num *= -1;

    return somarFracao(f, g);
}

Fracao multiplicarFracao(Fracao f, Fracao g)
{
    Fracao r = {f.num * g.num, f.den * g.den};

    return simplificarFracao(r);
}

Fracao dividirFracao(Fracao f, Fracao g)
{
    int temp = g.num;

    g.num = g.den;
    g.den = temp;

    return multiplicarFracao(f, g);
}

int main(void)
{
    system("cls");

    Fracao F1 = criarFracao(3, 4);
    Fracao F2 = criarFracao(27, 30);
    Fracao F3 = criarFracao(5, 9);
    Fracao F4 = criarFracao(1, 2);
    Fracao F5 = criarFracao(1, 3);

    exibirFracao(F1);
    exibirFracao(simplificarFracao(F2));
    exibirFracao(multiplicarFracao(F1, F3));
    exibirFracao(somarFracao(F4, F5));
    exibirFracao(subtrairFracao(F3, F1));
    exibirFracao(dividirFracao(F1, F4));
}