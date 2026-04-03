#include <stdio.h>
#include <dirent.h>
#include <string.h>

#include "dmngr.h"

int terminaCom(char * extensao, char * nome)
{
    int tam_nome = strlen(nome);
    int tam_extensao = strlen(extensao);
    char * finais = nome + tam_nome - tam_extensao;

    if (strcmp(finais, extensao) == 0) return 1;

    return 0;
}

int concatArquivos(char * pasta)
{
    // Vetor que guardará os nomes dos arquivos a serem processados
    char arquivos[MAX_ARQUIVOS][TAM_NOME_ARQUIVO];
    // DONKEY CONTINUE maybe with int qt_arquivos = popularArquivos(pasta);

    // Abrindo pasta com os arquivos
    DIR * ptrPasta = opendir(pasta);
    if (!ptrPasta) { perror("Pasta invalida"); return -1 ;}

    struct dirent * arqAtual;

    // Pulando os arquivos /./ e /../
    arqAtual = readdir(ptrPasta); arqAtual = readdir(ptrPasta);

    int count = 0;
    for (int i = 0; i < MAX_ARQUIVOS; i++)
    {
        arqAtual = readdir(ptrPasta);
        if (!arqAtual) break;
        
        if (terminaCom(".csv", arqAtual->d_name))
        {
            strcpy(arquivos[count], arqAtual->d_name);
            count++;
        }
    }

    for (int i = 0; i < MAX_ARQUIVOS; i++) // DONKEY
    { // DONKEY
        printf("%i. %s\n", i, arquivos[i]); // DONKEY
    } // DONKEY

    printf("count: %i\n", count);

    return count;
}