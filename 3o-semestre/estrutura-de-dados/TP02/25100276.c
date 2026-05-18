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

// AUX

int main(void)
{
    Caminho * caminho = InicializarCaminho("nslO", 2, 0);
}

Caminho * InicializarCaminho (const char * sequencia, int xInicial, int yInicial)
{
    char * uprseq = strdup(sequencia);
    strupr(uprseq);

    if (!EhValida(uprseq)) { perror("Sequencia de comandos invahlida.\n"); return NULL; }

    Caminho * C = (Caminho *) malloc(sizeof(Caminho));
    if (!C) { perror("Naum hah memohria para armazenar o caminho"); return NULL; }

    // Settando a posissaum inicial do robou
    Posicao pInicial = { xInicial, yInicial };
    C->Inicio = &pInicial;
    
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
    printf("%c!\n", C->Instrucoes->Direcao); // DONKEY
}

void DestruirCaminho(Caminho * c)
{
    // TODO
}

Posicao * DeterminarFim(Caminho * c)
{
    // TODO
}

Posicao HistoricoPosicoes(Caminho * c)
{
    // TODO
}

int CalcularDistanciaTotal(Caminho * C)
{
    // TODO
}

double CalcularDistanciaGeometrica(Caminho * C)
{
    // TODO
}

int CalcularDistanciaManhattan(Caminho * C)
{
    // TODO
}

int ContarInstrucoes(Caminho * C)
{
    // TODO
}
