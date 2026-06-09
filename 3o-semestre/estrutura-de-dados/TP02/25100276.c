#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "caminho.h"

// ---- FUNSSOINS AUXILIARES ----

// Verifica se a string inserida eh composta somente pelas letras N S L O
int EhValida(char * seq)
{
    char * str = strdup(seq);
    strupr(str);

    int valida = 1;

    // Altera o valor de valida se ao menos uma letra estah fora do padraum
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] != 'N' && str[i] != 'S' && str[i] != 'L' && str[i] != 'O')
        {
            valida = 0;
        }
    }

    return valida;
}

// Cria uma nova posissaum com os valores de X e Y escolhidos
Posicao * NovaPosissaum(int x, int y, Posicao * proxima)
{
    Posicao * pos = (Posicao *) malloc(sizeof(Posicao));
    if (!pos) {perror("Naum hah memohria para alocar nova posissaum."); return NULL;}

    pos->X = x;
    pos->Y = y;
    pos->Proximo = proxima;

    return pos;
}

// Printa a posissaum. Foi usada apenas para debug
void ExibirPosissaum(Posicao * p)
{
    printf("(%i, %i), %X\n", p->X, p->Y, p->Proximo);
}

// Segue a trilha das posissoins, sempre liberando a memohria da posissaum anterior
void DestruirPosissoins(Posicao * p)
{
    Posicao * pAtual = p;

    while (pAtual)
    {
        Posicao * proxima = pAtual->Proximo;
        free(pAtual);
        pAtual = proxima;
    }
}

// Segue a trilha de instrussoins, sempre liberando a memohria do comando anterior
void DestruirInstrussoins(Comando * c)
{
    Comando * cAtual = c;

    while (cAtual)
    {
        Comando * proximo = cAtual->Proximo;
        free(cAtual);
        cAtual = proximo;
    }
}


// AUX ---- FUNSSOINS PRINCIPAIS ----

Caminho * InicializarCaminho (const char * sequencia, int xInicial, int yInicial)
{
    char * seq = strdup(sequencia);
    strupr(seq);

    if (!EhValida(seq)) { perror("Sequencia de comandos invahlida.\n"); return NULL; }

    Caminho * C = (Caminho *) malloc(sizeof(Caminho));
    if (!C) { perror("Naum hah memohria para armazenar o caminho."); return NULL; }

    // Settando a posissaum inicial do robou
    Posicao * pInicial = NovaPosissaum(xInicial, yInicial, NULL); 
    C->Inicio = pInicial;
    
    // Settando as instrussoins do robou
    // Passa por cada um dos caracteres da sequencia de trahs para frente, criando um comando para cada caractere
    Comando * prevcmd = NULL; // Armazena o comando anterior para ser adicionado ao campo Proximo do Comando subsequente
    for (int i = strlen(seq) - 1; i >= 0; i--)
    {
        Comando * cur = (Comando *) malloc(sizeof(Comando));
        if (!cur)
        {
            perror("Naum hah memohria para armazenar o comando.");
            free(C);
            return NULL;
        }

        cur->Direcao = seq[i];
        cur->Proximo = prevcmd;

        prevcmd = cur;
    }

    // Settando a uhltimo comando do loop como a primeiro comando da lista de instrussoins
    C->Instrucoes = prevcmd;

    // Settando quantidade de instrussoins
    // acho que eu to roubando...
    C->N = strlen(sequencia);

    return C;
}

void DestruirCaminho(Caminho * c)
{
    if (!c) { perror("Naum hah caminho."); return; }

    DestruirPosissoins(c->Inicio);
    DestruirInstrussoins(c->Instrucoes);

    free(c);
}

Posicao * DeterminarFim(Caminho * c)
{
    if (!c) { perror("Naum hah caminho."); return NULL; }

    Comando * cAtual = c->Instrucoes;
    Posicao * pAtual = c->Inicio;

    for (int i = 0; i < c->N; i++)
    {
        switch (cAtual->Direcao)
        {
            case 'N':
                pAtual->Proximo = NovaPosissaum(pAtual->X, pAtual->Y + 1, NULL);
                break;
            case 'S':
                pAtual->Proximo = NovaPosissaum(pAtual->X, pAtual->Y - 1, NULL);
                break;
            case 'L':
                pAtual->Proximo = NovaPosissaum(pAtual->X + 1, pAtual->Y, NULL);
                break;
            case 'O':
                pAtual->Proximo = NovaPosissaum(pAtual->X - 1, pAtual->Y, NULL);
                break;
            default:
                printf("do you see me?");
                break;
        }

        pAtual = pAtual->Proximo;
        cAtual = cAtual->Proximo;
    }

    c->Fim = pAtual; // for SOME reason, the main() function needs both...
    return pAtual;
}

Posicao * HistoricoPosicoes(Caminho * c)
{
    if (!c) { perror("Naum hah caminho."); return NULL; }

    Comando * cAtual = (Comando *) malloc(sizeof(Comando));
    cAtual = c->Instrucoes;

    Posicao * pAtual = c->Inicio;

    for (int i = 0; i < c->N; i++)
    {
        switch (cAtual->Direcao)
        {
            case 'N':
                pAtual->Proximo = NovaPosissaum(pAtual->X, pAtual->Y + 1, NULL);
                break;
            case 'S':
                pAtual->Proximo = NovaPosissaum(pAtual->X, pAtual->Y - 1, NULL);
                break;
            case 'L':
                pAtual->Proximo = NovaPosissaum(pAtual->X + 1, pAtual->Y, NULL);
                break;
            case 'O':
                pAtual->Proximo = NovaPosissaum(pAtual->X - 1, pAtual->Y, NULL);
                break;
            default:
                break;
        }

        pAtual = pAtual->Proximo;
        cAtual = cAtual->Proximo;
    }

    free(cAtual);

    return c->Inicio;
}

int CalcularDistanciaTotal(Caminho * c)
{
    if (!c) { perror("Naum hah caminho."); return -1; }

    return ContarInstrucoes(c); // ¯\_(ツ)_/¯
}

double CalcularDistanciaGeometrica(Caminho * c)
{
    if (!c) { perror("Naum hah caminho."); return -1.0; }

    int xI = c->Inicio->X; int yI = c->Inicio->Y;
    int xF = c->Fim->X; int yF = c->Fim->Y;

    double d = sqrt( pow(xF - xI, 2) + pow(yF - yI, 2));

    return d;
}

int CalcularDistanciaManhattan(Caminho * c)
{
    if (!c) { perror("Naum hah caminho."); return -1; }

    int xI = c->Inicio->X; int yI = c->Inicio->Y;
    int xF = c->Fim->X; int yF = c->Fim->Y;
    
    int d = xF - xI + yF - yI;

    return (d<0)?-d:d;
}

int ContarInstrucoes(Caminho * c)
{
    if (!c) { perror("Naum hah caminho."); return -1; }
    
    return c->N; // ¯\_(ツ)_/¯
}
