#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

#include "dmngr.h"
char tmp[256];

// Função que verifica se uma string [nome] termina com outra [extensao]
int terminaCom(char * extensao, char * nome)
{
    int tam_nome = strlen(nome);
    int tam_extensao = strlen(extensao);
    char * finais = nome + tam_nome - tam_extensao;

    if (strcmp(finais, extensao) == 0) return 1;

    return 0;
}

// Armazena o nome dos arquivos da pasta indicada em um vetor
// Estes nomes são utilizados na função ConcatArquivos
int GetNomesArquivos(char * pasta, char vtr[MAX_ARQUIVOS][TAM_NOME_ARQUIVO])
{
    // Abrindo pasta com os arquivos
    DIR * ptrPasta = opendir(pasta);
    if (!ptrPasta) { perror("Pasta invalida"); return -1 ;}

    struct dirent * arqAtual;

    // Pulando os arquivos /./ e /../
    arqAtual = readdir(ptrPasta); arqAtual = readdir(ptrPasta);

    int qt_checados = 0; // Quantidade de arquivos que passam pela checagem
    for (int i = 0; i < MAX_ARQUIVOS; i++)
    {
        arqAtual = readdir(ptrPasta);
        if (!arqAtual) { break; }
        
        // Verificando se o arquivo atual termina com '.csv', se sim, adiciona-o ao vetor de nomes
        if (terminaCom(".csv", arqAtual->d_name))
        {
            strcpy(vtr[qt_checados], arqAtual->d_name);
            qt_checados++;
        }
    }

    return qt_checados;
}

// Concatena os dados encontrados na pasta indicada em um só arquivo titulado dados.csv
// Todos os processamentos e cálculos posteriores são feitos no arquivo criado
int ConcatArquivos(char * pasta)
{
    FILE * fw = fopen("dados.csv", "w");

    // Vetor que guardará os nomes dos arquivos a serem processados
    char arquivos[MAX_ARQUIVOS][TAM_NOME_ARQUIVO];
    int qt_arquivos = GetNomesArquivos(pasta, arquivos);

    // Adicionando cabeçalho no arquivo final
    fprintf(fw, "%s", CABECALHO);
    
    // Para cada arquivo, este loop lerá o seu conteúdo e transcreverá para o arquivo final
    int arquivosConcatenados = 0;
    for (int i = 0; i < qt_arquivos; i++)
    {
        FILE * fr = fopen(scratch("%s%s", "../data/", arquivos[i]), "r");
        if (!fr) { perror("Erro ao abrir arquivo para leitura"); return -1; }
        
        // Saltando a primeira linha
        char buffer[1024];
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
    
    // Retornando a quantidade de arquivos concatenados com sucesso
    fclose(fw);
    return arquivosConcatenados;
}

// Efetua os cálculos para cada uma das variáveis e monta a linha a ser adicionada ao arquivo resumo.csv
// É chamada sempre que uma nova sigla é detectada durante a leitura do arquivo dados.csv
void montarLinhaResumo(LinhaResumo * lr, char * sigla, Somas sms)
{
    // Atribuindo a sigla à linha
    strcpy(lr->sigla_tribunal, sigla);

    // Efetuando os cálculos de cada variável
    lr->julgados_2026 = sms.s_julgados_2026;
    lr->Meta1 = ((float) sms.s_julgados_2026 / (sms.s_casos_novos_2026 + sms.s_dessobrestados_2026 - sms.s_suspensos_2026)) * 100;
    lr->Meta2A = ((float) sms.s_julgm2_a / (sms.s_distm2_a - sms.s_suspm2_a)) * (100 / 7);
    lr->Meta2Ant = ((float) sms.s_julgm2_ant / (sms.s_distm2_ant - sms.s_suspm2_ant-sms.s_desom2_ant)) * 100;
    lr->Meta4A = ((float) sms.s_julgm4_a / (sms.s_distm4_a - sms.s_suspm4_a)) * 100;
    lr->Meta4B = ((float) sms.s_julgm4_b / (sms.s_distm4_b - sms.s_suspm4_b)) * 100;
}

// Incrementa os somatórios com a passagem de cada linha durante a montagem do arquivo resumo
void IncrementarSomatorios(Somas * sms, LinhaDados Dds)
{
    sms->s_julgados_2026 += Dds.julgados_2026;
    sms->s_casos_novos_2026 += Dds.casos_novos_2026;
    sms->s_dessobrestados_2026 += Dds.dessobrestados_2026;
    sms->s_suspensos_2026 += Dds.suspensos_2026;
    sms->s_julgm2_a += Dds.julgm2_a;
    sms->s_distm2_a += Dds.distm2_a;
    sms->s_suspm2_a += Dds.suspm2_a;
    sms->s_julgm2_ant += Dds.julgm2_ant;
    sms->s_distm2_ant += Dds.distm2_ant;
    sms->s_suspm2_ant += Dds.suspm2_ant;
    sms->s_desom2_ant += Dds.desom2_ant;
    sms->s_julgm4_a += Dds.julgm4_a;
    sms->s_distm4_a += Dds.distm4_a;
    sms->s_suspm4_a += Dds.suspm4_a;
    sms->s_julgm4_b += Dds.julgm4_b;
    sms->s_distm4_b += Dds.distm4_b;
    sms->s_suspm4_b += Dds.suspm4_b;
}

// Gera um resumo, titulado resumo.csv, sobre os dados dos TREs dos diversos estados do Brasil
// Baseia-se no arquivo dados.csv gerado pela função ConcatArquivos()
void GerarResumo(int qt_arquivos)
{
    // Abrindo o arquivo que contém os dados a serem lidos para montar o resumo
    FILE * dados = fopen("dados.csv", "r");
    if (!dados) { perror("Arquivo de dados inexistente"); return ;}

    // Abrindo o arquivo onde o resumo será montado
    FILE * resumo = fopen("resumo.csv", "w");
    char * cabecalho_resumo = "\"sigla_tribunal\",\"total_julgados_2026\",\"Meta1\",\"Meta2A\",\"Meta2Ant\",\"Meta4A\",\"Meta4B\"";
    fprintf(resumo, "%s\n", cabecalho_resumo);
    
    // Settando a variável como "TRE-AC" para evitar a primeira checagem de mudança de sigla
    char ultima_sigla[9] = "\"TRE-AC\"";
    
    // Variáveis a serem utilizadas para a montagem do arquivo resumo
    Somas S = {0}; // Struct onde serão armazenados todos os somatórios utilizados nos cálculos
    LinhaDados lD; // Linha do arquivo que contém os dados a serem adicionados ao somatório
    LinhaResumo lRes; // Linha a ser adicionada ao arquivo resumo. Ela contém todos os cálculos do resumo
    
    // Criando buffer e saltando a leitura do cabeçado
    char buffer[1024];
    fgets(buffer, sizeof(buffer), dados);
    
    // Lê a linha atual, processa os dados, e escreve-os no arquivo resumo quando uma nova sigla é detectada
    while(fgets(buffer, sizeof(buffer), dados))
    {
        sscanf(buffer, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%i,%[^,],%[^,],%[^,],%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i", lD.sigla_tribunal, lD.procedimento, lD.ramo_justica, lD.sigla_grau, lD.uf_oj, lD.municipio_oj, &lD.id_ultimo_oj, lD.nome, lD.mesano_cnm1, lD.mesano_sent, &lD.casos_novos_2026, &lD.julgados_2026, &lD.prim_sent2026, &lD.suspensos_2026, &lD.dessobrestados_2026, &lD.cumprimento_meta1, &lD.distm2_a, &lD.julgm2_a, &lD.suspm2_a, &lD.cumprimento_meta2a, &lD.distm2_ant, &lD.julgm2_ant, &lD.suspm2_ant, &lD.desom2_ant, &lD.cumprimento_meta2ant, &lD.distm4_a, &lD.julgm4_a, &lD.suspm4_a, &lD.cumprimento_meta4a, &lD.distm4_b, &lD.julgm4_b, &lD.suspm4_b, &lD.cumprimento_meta4b);

        // Se a sigla da linha atual for diferente da sigla da linha anterior, o programa executa o processo de montar a linha resumo e adicioná-la ao arquivo do resumo
        if (strcmp(ultima_sigla, lD.sigla_tribunal) != 0)
        {
            montarLinhaResumo(&lRes, ultima_sigla, S);

            // Transcrevendo a linha resumo para o arquivo do resumo
            fprintf(resumo, "%s,%i,%f,%f,%f,%f,%f\n", lRes.sigla_tribunal, lRes.julgados_2026, lRes.Meta1, lRes.Meta2A, lRes.Meta2Ant, lRes.Meta4A, lRes.Meta4B);

            // Resetando somatórios e atualizando a sigla para a da nova linha
            Somas s = {0};
            S = s;
            strcpy(ultima_sigla, lD.sigla_tribunal);
        }
        
        IncrementarSomatorios(&S, lD);
    }

    // O procedimento do loop deve acontecer mais uma vez para adicionar a linha resumo do último arquivo lido, mas o procedimento é exatamente o mesmo
    // TODO: abstract to a function like writetofile()
    montarLinhaResumo(&lRes, ultima_sigla, S);

    fprintf(resumo, "%s,%i,%f,%f,%f,%f,%f\n", lRes.sigla_tribunal, lRes.julgados_2026, lRes.Meta1, lRes.Meta2A, lRes.Meta2Ant, lRes.Meta4A, lRes.Meta4B);

    fclose(dados); fclose(resumo);
}

// Gera arquivo de ocorrências titulado MUNICIPIO.csv de acordo com o município escolhido
// Baseia-se no arquivo dados.csv gerado pela função ConcatArquivos()
char * gerarOcorrencias(char * municipio)
{
    FILE * fr = fopen("dados.csv", "r");
    if (!fr) { perror("Arquivo de leitura não encontrado"); return NULL; }

    // Abrindo o arquivo de ocorrências do município e escrevendo o cabeçalho
    FILE * fw = fopen(scratch("%s.csv", municipio), "w");
    fprintf(fw, "%s", CABECALHO);

    // Criando buffer e ignorando primeira linha
    char buffer[1024];
    fgets(buffer, sizeof(buffer), fr);

    int qt_ocorrencias = 0;

    // Registra a linha caso a entrada do usuário coincida com o nome armazenado do municipio
    while (fgets(buffer, sizeof(buffer), fr))
    {
        // Obtendo o nome do município na linha atual
        LinhaDados lD;
        sscanf(buffer, "%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%[^,],", lD.municipio_oj);
        
        // Verifica se os nomes coincidem
        if (strcasecmp(scratch("\"%s\"", municipio), lD.municipio_oj) == 0)
        {
            fprintf(fw, "%s", buffer);
            qt_ocorrencias++;
        }
    }

    fclose(fr); fclose(fw);
    
    // Feedback ao usuário de acordo com sua entrada
    if(qt_ocorrencias == 0)
    {
        remove(scratch("%s.csv", municipio));
        return scratch("\x1b[31mNenhuma ocorrência encontrada para o municipio de %s.\x1b[0m\n", municipio);
    }
    else
    {
        return scratch("%i ocorrências registradas em \x1b[32m%s.csv\x1b[0m.\n", qt_ocorrencias, municipio);
    }
}

void Bye(){system("cls");char*s="🐍+🐢=🐊";while(*s){int bytes=(*s&0x80)?4:1;for(int i=0;i<bytes;i++)putchar(*s++);fflush(stdout);sleep(1);}system("cls");}