#include <stdlib.h>
#include "fracao.h"

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