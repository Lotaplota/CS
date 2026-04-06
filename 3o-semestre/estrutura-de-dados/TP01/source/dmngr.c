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

    return count;
}

int ConcatArquivos(char * pasta, char * arqDestino)
{
    FILE * fw = fopen(arqDestino, "w");

    // Vetor que guardará os nomes dos arquivos a serem processados
    char arquivos[MAX_ARQUIVOS][TAM_NOME_ARQUIVO];
    int qt_arquivos = getNomesArquivos(pasta, arquivos);

    char buffer[1024];
    // Adicionando cabeçalho no arquivo final
    fprintf(fw, "%s", "\"sigla_tribunal\",\"procedimento\",\"ramo_justica\",\"sigla_grau\",\"uf_oj\",\"municipio_oj\",\"id_ultimo_oj\",\"nome\",\"mesano_cnm1\",\"mesano_sent\",\"casos_novos_2026\",\"julgados_2026\",\"prim_sent2026\",\"suspensos_2026\",\"dessobrestados_2026\",\"cumprimento_meta1\",\"distm2_a\",\"julgm2_a\",\"suspm2_a\",\"cumprimento_meta2a\",\"distm2_ant\",\"julgm2_ant\",\"suspm2_ant\",\"desom2_ant\",\"cumprimento_meta2ant\",\"distm4_a\",\"julgm4_a\",\"suspm4_a\",\"cumprimento_meta4a\",\"distm4_b\",\"julgm4_b\",\"suspm4_b\",\"cumprimento_meta4b\"\n");

    int arquivosConcatenados = 0;
    for (int i = 0; i < qt_arquivos; i++)
    {
        // Montando a localização do arquivo em referência à pasta /source/
        char localDoArquivo[64] = "../database/";
        strcat(localDoArquivo, arquivos[i]);

        // Abrindo arquivo e descartando a primeira linha
        FILE * fr = fopen(localDoArquivo, "r");
        if (!fr) { perror("Erro ao abrir arquivo para leitura"); return -1; }
        
        // Saltando a primeira linha
        fgets(buffer, sizeof(buffer), fr);

        // Transcrevendo a linha para o arquivo final
        while (fgets(buffer, sizeof(buffer), fr))
        {
            fprintf(fw, "%s", buffer);
        }

        // Fechando arquivo e contabilizando a concatenação
        fclose(fr);
        arquivosConcatenados++;
    }
    
    fclose(fw);
    return arquivosConcatenados;
}

void GerarResumo(char * ptrDados, int qt_arquivos)
{
    FILE * dados = fopen(ptrDados, "r");
    if (!dados) { perror("Arquivo de dados inexistente"); return ;}

    FILE * resumo = fopen("resumo.csv", "w");
    char * cabecalho_resumo = "sigla_tribunal,total_julgados_2026,Meta1,Meta2A,Meta2Ant,Meta4A,Meta4B";
    fprintf(resumo, "%s\n", cabecalho_resumo);
    
    char buffer[1024];
    fgets(buffer, sizeof(buffer), dados);

    // Settando a variável como "TRE-AC" para evitar a primeira checagem de mudança de sigla
    char ultima_sigla[9] = "\"TRE-AC\"";

    Somas S = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    LinhaResumo lRes;
    LinhaDados lDad;

    while(fgets(buffer, sizeof(buffer), dados))
    {
        sscanf(buffer, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%i,%[^,],%[^,],%[^,],%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i", lDad.sigla_tribunal, lDad.procedimento, lDad.ramo_justica, lDad.sigla_grau, lDad.uf_oj, lDad.municipio_oj, &lDad.id_ultimo_oj, lDad.nome, lDad.mesano_cnm1, lDad.mesano_sent, &lDad.casos_novos_2026, &lDad.julgados_2026, &lDad.prim_sent2026, &lDad.suspensos_2026, &lDad.dessobrestados_2026, &lDad.cumprimento_meta1, &lDad.distm2_a, &lDad.julgm2_a, &lDad.suspm2_a, &lDad.cumprimento_meta2a, &lDad.distm2_ant, &lDad.julgm2_ant, &lDad.suspm2_ant, &lDad.desom2_ant, &lDad.cumprimento_meta2ant, &lDad.distm4_a, &lDad.julgm4_a, &lDad.suspm4_a, &lDad.cumprimento_meta4a, &lDad.distm4_b, &lDad.julgm4_b, &lDad.suspm4_b, &lDad.cumprimento_meta4b);

        if (strcmp(ultima_sigla, lDad.sigla_tribunal) != 0)
        {
            strcpy(lRes.sigla_tribunal, ultima_sigla);
            lRes.julgados_2026 = S.s_julgados_2026;
            lRes.Meta1 = ((float) S.s_julgados_2026 / (S.s_casos_novos_2026 + S.s_dessobrestados_2026 - S.s_suspensos_2026)) * 100;
            lRes.Meta2A = ((float) S.s_julgm2_a / (S.s_distm2_a - S.s_suspm2_a)) * (100 / 7);
            lRes.Meta2Ant = ((float) S.s_julgm2_ant / (S.s_distm2_ant - S.s_suspm2_ant-S.s_desom2_ant)) * 100;
            lRes.Meta4A = ((float) S.s_julgm4_a / (S.s_distm4_a - S.s_suspm4_a)) * 100;
            lRes.Meta4B = ((float) S.s_julgm4_b / (S.s_distm4_b - S.s_suspm4_b)) * 100;

            fprintf(resumo, "%s,%i,%f,%f,%f,%f,%f\n", lRes.sigla_tribunal, lRes.julgados_2026, lRes.Meta1, lRes.Meta2A, lRes.Meta2Ant, lRes.Meta4A, lRes.Meta4B);

            S.s_julgados_2026 = 0;
            S.s_casos_novos_2026 = 0;
            S.s_dessobrestados_2026 = 0;
            S.s_suspensos_2026 = 0;
            S.s_julgm2_a = 0;
            S.s_distm2_a = 0;
            S.s_suspm2_a = 0;
            S.s_julgm2_ant = 0;
            S.s_distm2_ant = 0;
            S.s_suspm2_ant = 0;
            S.s_desom2_ant = 0;
            S.s_julgm4_a = 0;
            S.s_distm4_a = 0;
            S.s_suspm4_a = 0;
            S.s_julgm4_b = 0;
            S.s_distm4_b = 0;
            S.s_suspm4_b = 0;
            
            strcpy(ultima_sigla, lDad.sigla_tribunal);
        }
        
        S.s_julgados_2026 = S.s_julgados_2026 + lDad.julgados_2026;
        S.s_casos_novos_2026 = S.s_casos_novos_2026 + lDad.casos_novos_2026;
        S.s_dessobrestados_2026 = S.s_dessobrestados_2026 + lDad.dessobrestados_2026;
        S.s_suspensos_2026 = S.s_suspensos_2026 + lDad.suspensos_2026;
        S.s_julgm2_a = S.s_julgm2_a + lDad.julgm2_a;
        S.s_distm2_a = S.s_distm2_a + lDad.distm2_a;
        S.s_suspm2_a = S.s_suspm2_a + lDad.suspm2_a;
        S.s_julgm2_ant = S.s_julgm2_ant + lDad.julgm2_ant;
        S.s_distm2_ant = S.s_distm2_ant + lDad.distm2_ant;
        S.s_suspm2_ant = S.s_suspm2_ant + lDad.suspm2_ant;
        S.s_desom2_ant = S.s_desom2_ant + lDad.desom2_ant;
        S.s_julgm4_a = S.s_julgm4_a + lDad.julgm4_a;
        S.s_distm4_a = S.s_distm4_a + lDad.distm4_a;
        S.s_suspm4_a = S.s_suspm4_a + lDad.suspm4_a;
        S.s_julgm4_b = S.s_julgm4_b + lDad.julgm4_b;
        S.s_distm4_b = S.s_distm4_b + lDad.distm4_b;
        S.s_suspm4_b = S.s_suspm4_b + lDad.suspm4_b;
    }

    strcpy(lRes.sigla_tribunal, ultima_sigla);
    lRes.julgados_2026 = S.s_julgados_2026;
    lRes.Meta1 = ((float) S.s_julgados_2026 / (S.s_casos_novos_2026 + S.s_dessobrestados_2026 - S.s_suspensos_2026)) * 100;
    lRes.Meta2A = ((float) S.s_julgm2_a / (S.s_distm2_a - S.s_suspm2_a)) * (100 / 7);
    lRes.Meta2Ant = ((float) S.s_julgm2_ant / (S.s_distm2_ant - S.s_suspm2_ant-S.s_desom2_ant)) * 100;
    lRes.Meta4A = ((float) S.s_julgm4_a / (S.s_distm4_a - S.s_suspm4_a)) * 100;
    lRes.Meta4B = ((float) S.s_julgm4_b / (S.s_distm4_b - S.s_suspm4_b)) * 100;

    fprintf(resumo, "%s,%i,%f,%f,%f,%f,%f\n", lRes.sigla_tribunal, lRes.julgados_2026, lRes.Meta1, lRes.Meta2A, lRes.Meta2Ant, lRes.Meta4A, lRes.Meta4B);

    fclose(dados); fclose(resumo);
}