#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

// AUX

int main(void)
{
    Caminho * caminho = InicializarCaminho("nNslLO", 0, 0);
    printf("qt de instrussoins: %i\n", caminho->N); // DONKEY

    caminho->Historico = HistoricoPosicoes(caminho);
    // printf("p1. (%i, %i)\n", caminho->Historico->X, caminho->Historico->Y); // DONKEY 3
    // printf("p2. (%i, %i)\n", caminho->Historico->Proximo->X, caminho->Historico->Proximo->Y); // DONKEY 3
    // printf("p3. (%i, %i)\n", caminho->Historico->Proximo->Proximo->X, caminho->Historico->Proximo->Proximo->Y); // DONKEY 3
    // printf("p4. (%i, %i)\n", caminho->Historico->Proximo->Proximo->Proximo->X, caminho->Historico->Proximo->Proximo->Proximo->Y); // DONKEY 3
    // printf("p5. (%i, %i)\n", caminho->Historico->Proximo->Proximo->Proximo->Proximo->X, caminho->Historico->Proximo->Proximo->Proximo->Proximo->Y); // DONKEY 3
    // printf("p6. (%i, %i)\n", caminho->Historico->Proximo->Proximo->Proximo->Proximo->Proximo->X, caminho->Historico->Proximo->Proximo->Proximo->Proximo->Proximo->Y); // DONKEY 3
    caminho->Fim = DeterminarFim(caminho);
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
    // TODO
}

Posicao * DeterminarFim(Caminho * c)
{
    // Comando * atual = (Comando *) malloc(sizeof(Comando));
    // Posicao * final = NovaPosicao(c->Inicio->X, c->Inicio->Y, NULL);

    // for (int i = 0; i < c->N; i++)
    // {
    //     printf("diressaum do comando: %c\n", atual->Direcao); // DONKEY
    //     switch (atual->Direcao)
    //     {
    //     case 'N':
    //         final->Y++;
    //         break;
    //     case 'S':
    //         final->Y--;
    //         break;
    //     case 'L':
    //         final->X++;
    //         break;
    //     case 'O':
    //         final->X++;
    //         break;
    //     default:
    //         break;
    //     }
    // }
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
    // TODO
}

double CalcularDistanciaGeometrica(Caminho * c)
{
    // TODO
}

int CalcularDistanciaManhattan(Caminho * c)
{
    // TODO
}

int ContarInstrucoes(Caminho * c)
{
    // TODO
}
