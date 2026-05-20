#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "caminho.h"

// AUX

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

Posicao * NovaPosicao(int x, int y, Posicao * proxima)
{
    Posicao * pos = (Posicao *) malloc(sizeof(Posicao));
    if (!pos) {perror("Naum hah memohria para alocar nova posissaum."); return NULL;}

    pos->X = x;
    pos->Y = y;
    pos->Proximo = proxima;

    return pos;
}

void ExibirPosissaum(Posicao * p)
{
    printf("(%i, %i), %X\n", p->X, p->Y, p->Proximo);
}

void DestruirPosissoins(Posicao * p)
{
    Posicao * pAtual = p;

    while (pAtual)
    {
        Posicao * proxima = pAtual->Proximo;
        // printf("freeing position (%i, %i)\n", pAtual->X, pAtual->Y); // DONKEY 6
        free(pAtual);
        // printf("now: (%i, %i)\n", pAtual->X, pAtual->Y); // DONKEY 6
        pAtual = proxima;
    }
}

void DestruirInstrussoins(Comando * c)
{
    Comando * cAtual = c;

    while (cAtual)
    {
        Comando * proximo = cAtual->Proximo;
        // printf("freeing command %c\n", cAtual->Direcao); // DONKEY 6
        free(cAtual);
        // printf("now: %c\n", cAtual->Direcao); // DONKEY 6
        cAtual = proximo;
    }
}

// AUX

int main(void)
{
    Caminho * caminho = InicializarCaminho("sssoooo", 0, 0);
    printf("qt de instrussoins: %i\n", caminho->N); // DONKEY

    caminho->Historico = HistoricoPosicoes(caminho);
    // printf("p1. (%i, %i)\n", caminho->Historico->X, caminho->Historico->Y); // DONKEY 3
    // printf("p2. (%i, %i)\n", caminho->Historico->Proximo->X, caminho->Historico->Proximo->Y); // DONKEY 3
    // printf("p3. (%i, %i)\n", caminho->Historico->Proximo->Proximo->X, caminho->Historico->Proximo->Proximo->Y); // DONKEY 3
    // printf("p4. (%i, %i)\n", caminho->Historico->Proximo->Proximo->Proximo->X, caminho->Historico->Proximo->Proximo->Proximo->Y); // DONKEY 3
    // printf("p5. (%i, %i)\n", caminho->Historico->Proximo->Proximo->Proximo->Proximo->X, caminho->Historico->Proximo->Proximo->Proximo->Proximo->Y); // DONKEY 3
    // printf("p6. (%i, %i)\n", caminho->Historico->Proximo->Proximo->Proximo->Proximo->Proximo->X, caminho->Historico->Proximo->Proximo->Proximo->Proximo->Proximo->Y); // DONKEY 3
    caminho->Fim = DeterminarFim(caminho);
    // printf("posicao final: "); // DONKEY 4
    // ExibirPosissaum(caminho->Fim); // DONKEY 4
    caminho->N = CalcularDistanciaTotal(caminho);
    
    int dManhattan = CalcularDistanciaManhattan(caminho);
    // printf("dManhattan = %i\n", dManhattan); // DONKEY 5
    double dGeo = CalcularDistanciaGeometrica(caminho);
    // printf("dGeo = %lf\n", dGeo); // DONKEY 5

    DestruirCaminho(caminho);

    printf("caminho depois da destruissaum: N = %i\n", caminho->N); // DONKEY 8
}

Caminho * InicializarCaminho (const char * sequencia, int xInicial, int yInicial)
{
    char * uprseq = strdup(sequencia);
    strupr(uprseq);

    if (!EhValida(uprseq)) { perror("Sequencia de comandos invahlida.\n"); return NULL; }

    Caminho * C = (Caminho *) malloc(sizeof(Caminho));
    if (!C) { perror("Naum hah memohria para armazenar o caminho"); return NULL; }

    // Settando a posissaum inicial do robou
    Posicao * pInicial = NovaPosicao(xInicial, yInicial, NULL); 
    C->Inicio = pInicial;
    
    // Settando as instrussoins do robou
    // Passa por cada um dos caracteres da sequencia de trahs para frente, criando um comando para cada caractere
    Comando * prevcmd = NULL; // Armazena o comando anterior para ser adicionado ao campo Proximo do Comando subsequente
    for (int i = strlen(uprseq) - 1; i >= 0; i--)
    {
        Comando * cur = (Comando *) malloc(sizeof(Comando));
        cur->Direcao = uprseq[i];
        cur->Proximo = prevcmd;

        prevcmd = cur;
    }

    C->Instrucoes = prevcmd;

    // Settando quantidade de instrussoins
    // acho que eu to roubando...
    C->N = strlen(sequencia);

    return C;
}

void DestruirCaminho(Caminho * c)
{
    DestruirPosissoins(c->Inicio);
    DestruirInstrussoins(c->Instrucoes);

    free(c);
}

Posicao * DeterminarFim(Caminho * c)
{
    Posicao * atual = c->Historico; // same thing as the starting position, but ok...
    
    while (atual->Proximo)
    {
        // ExibirPosissaum(atual); // DONKEY 4
        atual = atual->Proximo;
    }

    return atual;
}

Posicao * HistoricoPosicoes(Caminho * c)
{
    Comando * cAtual = (Comando *) malloc(sizeof(Comando));
    cAtual = c->Instrucoes;

    Posicao * pAtual = c->Inicio;
    // printf("[%i, %i]\n\n", pAtual->X, pAtual->Y); // DONKEY 2

    for (int i = 0; i < c->N; i++)
    {
        // printf("diressaum do comando: %c\n", cAtual->Direcao); // DONKEY 2
        // printf("(%i, %i) ", pAtual->X, pAtual->Y); // DONKEY 2
        switch (cAtual->Direcao)
        {
            case 'N':
                pAtual->Proximo = NovaPosicao(pAtual->X, pAtual->Y + 1, NULL);
                break;
            case 'S':
                pAtual->Proximo = NovaPosicao(pAtual->X, pAtual->Y - 1, NULL);
                break;
            case 'L':
                pAtual->Proximo = NovaPosicao(pAtual->X + 1, pAtual->Y, NULL);
                break;
            case 'O':
                pAtual->Proximo = NovaPosicao(pAtual->X - 1, pAtual->Y, NULL);
                break;
            default:
                break;
        }
        // printf("vai para (%i, %i)\n", pAtual->Proximo->X, pAtual->Proximo->Y); // DONKEY 2

        pAtual = pAtual->Proximo;
        cAtual = cAtual->Proximo;
    }

    free(cAtual);

    // printf("posissaum final: (%i, %i)\n", pAtual->X, pAtual->Y); // DONKEY 2
    return c->Inicio;
}

int CalcularDistanciaTotal(Caminho * c)
{
    return ContarInstrucoes(c); // ¯\_(ツ)_/¯
}

double CalcularDistanciaGeometrica(Caminho * c)
{
    int xI = c->Inicio->X; int yI = c->Inicio->Y;
    int xF = c->Fim->X; int yF = c->Fim->Y;

    double d = sqrt( pow(xF - xI, 2) + pow(yF - yI, 2));
    // printf("geodistance = %lf\n", d); // DONKEY 5

    return d;
}

int CalcularDistanciaManhattan(Caminho * c)
{
    int xI = c->Inicio->X; int yI = c->Inicio->Y;
    int xF = c->Fim->X; int yF = c->Fim->Y;
    
    int d = xF - xI + yF - yI;
    printf("dManhattan = %i\n", d); // DONKEY 5

    return (d<0)?-d:d;
}

int ContarInstrucoes(Caminho * c)
{
    return c->N; // ¯\_(ツ)_/¯
}
