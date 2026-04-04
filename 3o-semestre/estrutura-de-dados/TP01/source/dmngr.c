#include <stdio.h>
#include <dirent.h>
#include <string.h>

#include "dmngr.h"

// Função que verifica se uma string [nome] termina com outra [extensao]
int terminaCom(char * extensao, char * nome)
{
    int tam_nome = strlen(nome);
    int tam_extensao = strlen(extensao);
    char * finais = nome + tam_nome - tam_extensao;

    if (strcmp(finais, extensao) == 0) return 1;

    return 0;
}

int getNomesArquivos(char * pasta, char vtr[MAX_ARQUIVOS][TAM_NOME_ARQUIVO])
{
    // Abrindo pasta com os arquivos
    DIR * ptrPasta = opendir(pasta);
    if (!ptrPasta) { perror("Pasta invalida"); return -1 ;}

    struct dirent * arqAtual;

    // Pulando os arquivos /./ e /../
    arqAtual = readdir(ptrPasta); arqAtual = readdir(ptrPasta);

    int count = 0; // Quantidade de arquivos que passam pela checagem
    for (int i = 0; i < MAX_ARQUIVOS; i++)
    {
        arqAtual = readdir(ptrPasta);
        if (!arqAtual) break;
        
        // Verificando se o arquivo atual termina com '.csv', se sim, adiciona-o ao vetor de nomes
        if (terminaCom(".csv", arqAtual->d_name))
        {
            strcpy(vtr[count], arqAtual->d_name);
            count++;
        }
    }

    printf("count: %i\n", count);

    return count;
}

int concatArquivos(char * pasta)
{
    FILE * fw = fopen("dados.csv", "w");

    // Vetor que guardará os nomes dos arquivos a serem processados
    char arquivos[MAX_ARQUIVOS][TAM_NOME_ARQUIVO];
    int qt_arquivos = getNomesArquivos(pasta, arquivos);

    char buffer[1024];

    int arquivosConcatenados = 0;
    int lineCount = 0; // DONKEY
    for (int i = 0; i < qt_arquivos; i++)
    {
        // Montando a localização do arquivo em referência à pasta /source/
        char localDoArquivo[64] = "../database/";
        strcat(localDoArquivo, arquivos[i]);

        // Abrindo arquivo e descartando a primeira linha
        FILE * fr = fopen(localDoArquivo, "r");
        if (!fr) { perror("Erro ao abrir arquivo para leitura"); return -1; }
        fgets(buffer, sizeof(buffer), fr);
        
        int i = 0; // DONKEY
        // Transcrevendo a linha para o arquivo final
        while (fgets(buffer, sizeof(buffer), fr))
        {
            fprintf(fw, "%s", buffer);
            i++; // DONKEY
        }
        printf("Current lines: %i + %i\n", lineCount, i); // DONKEY
        lineCount += i; // DONKEY
        printf("lines read: %i\n", lineCount); // DONKEY

        // Fechando arquivo e contabilizando a concatenação
        fclose(fr);
        arquivosConcatenados++;
    }

    return arquivosConcatenados;
}