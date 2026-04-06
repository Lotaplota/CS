#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dmngr.h"

int main(void)
{
    int qt_arquivos = ConcatArquivos("../data");

    GerarResumo(qt_arquivos);
    system("cls");

    // Loop para obter entradas do usuário
    char entradaUsuario[64] = "inicio";
    while (1)
    {
        printf("Gostaria de listar as ocorrências de qual município?\nDigite \x1b[33m[sair]\x1b[0m para encerrar o programa.\n\t");

        scanf("%s", entradaUsuario);
        strcpy(entradaUsuario, strupr(entradaUsuario));

        if (strcmp(entradaUsuario, "SAIR") != 0)
        {
            system("cls");
            printf("%s\n", scratch("Buscando ocorreências do município de %s...", entradaUsuario));

            char * resposta = gerarOcorrencias(entradaUsuario);
            printf("%s\n", resposta);
        }
        else { Bye(); return 0; }
    }

    return 1;
}