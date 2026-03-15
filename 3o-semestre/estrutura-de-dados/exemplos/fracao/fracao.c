#include <stdio.h>

#include "fracao.h"

Fracao criarFracao(int N, int D)
{
    Fracao F;
    F.num = N; F.den = D;
    
    return F;
}

void exibirFracao(Fracao f)
{
    if (f.num >= 0)
        printf("%i\n-\n%i\n", f.num, f.den);
    else
        printf("  %i\n- -\n  %i\n", f.num * -1, f.den);
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

Fracao simplificarFracao(Fracao f)
{
    int mdc = MDC(f.num, f.den);

    f.num = f.num / mdc;
    f.den = f.den / mdc;

    return f;
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