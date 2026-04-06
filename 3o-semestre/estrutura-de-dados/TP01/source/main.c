#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dmngr.h"

int main(void)
{
    int qt_arquivos = ConcatArquivos("../database", "dados.csv");

    GerarResumo("dados.csv", qt_arquivos);

    // Loop para conseguir entrada do usuário
    char entradaUsuario[64] = "inicio";
    while (1)
    {
        printf("Gostaria de observar as ocorrencias de qual municipio?\nDigite [sair] para encerrar o programa\n");

        scanf("%s", entradaUsuario);
        strcpy(entradaUsuario, strupr(entradaUsuario));

        if (strcmp(entradaUsuario, "SAIR") != 0)
        {
            char * resposta = gerarOcorrencias(entradaUsuario);
            printf("%s\n", resposta);
        }
        else { break; }
    }
}