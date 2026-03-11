#include "fracao.c"

int main(void)
{
    system("cls");

    Fracao F1 = criarFracao(3, 4);
    Fracao F2 = criarFracao(27, 30);

    exibirFracao(F1);
    exibirFracao(F2);
    exibirFracao(simplificarFracao(F2));
} // TEST THIS