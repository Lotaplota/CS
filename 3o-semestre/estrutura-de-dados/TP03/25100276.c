#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "calculadora.h"

typedef struct Item
{
    char Chave[512]; // A chave será sempre uma string, nuhmeros seraum empilhados, enquanto operadores desempilharaum os dois uhltimos nuhmeros
    struct Item * Anterior;
} Item;

typedef struct Pilha
{
    struct Item * Topo;
    int Tamanho;
} Pilha;

Item * CriarItem(char * chave)
{
    Item * it = (Item *) malloc(sizeof(Item));

    if (!it) { perror("Naum hah memohria para um novo item"); return NULL; }
    
    strcpy(it->Chave, chave);
    it->Anterior = NULL;
    
    return it;
}

Pilha * CriarPilha()
{
    Pilha * p = (Pilha *) malloc(sizeof(Pilha));

    if (!p) { perror("Naum hah memohria para uma nova pilha"); return NULL; }

    p->Tamanho = 0;
    p->Topo = NULL;

    return p;
}

void Desempilhar(Pilha * p)
{
    if (p->Tamanho <= 0)
    {
        perror("A pilha jah estah vazia");
        return;
    }

    Item * del = p->Topo;

    p->Topo = p->Topo->Anterior;
    p->Tamanho--;

    free(del);
}

// Opera dois nuhmeros dependendo do operador passado
float Operar(float a, float b, char * operator)
{
    if (!strcmp(operator, "+")) return a + b;
    else if (!strcmp(operator, "-")) return a - b;
    else if (!strcmp(operator, "*")) return a * b;
    else if (!strcmp(operator, "/")) return a / b;
    else if (!strcmp(operator, "^")) return pow(a, b);
    else
    {
        printf("Erro: %s eh um operador desconhecido\n", operator);
        exit(1);
    }
}

// Calcula os dois uhltimos nuhmeros do topo da pilha, desempilha-os, e empilha o novo valor no topo da lista
// o uhltimo eh o b, o penuhltimo eh o a
void Calcular(Pilha * p, char * operador)
{
    float a = strtol(p->Topo->Anterior->Chave, NULL, 10);
    float b = strtol(p->Topo->Chave, NULL, 10);
    float res = Operar(a, b, operador);

    // Transformando o float de resultado em um string para ser armazenado
    int len = snprintf(NULL, 0, "%f", res);
    char * strres = malloc(len + 1);
    snprintf(strres, len + 1, "%f", res);

    // Desempilhando o item do operando b e reescrevendo o resultado na chave do item no topo da fila
    // Evita ter que empilhar um novo item ;^]
    Desempilhar(p);
    strcpy(p->Topo->Chave, strres);

    free(strres);
}

// Empilha um novo item se o a chave puder ser convertida em float, se naum, verifica se eh um operador, se sim, opera os dois uhltimos nuhmeros da pilha
void Empilhar(Pilha * p, Item * I)
{
    if (!p || !I)
    { perror("Naum hah pilha ou item."); return; }

    if (!strtol(I->Chave, NULL, 10))
    {
        Calcular(p, I->Chave);

        return;
    }

    I->Anterior = p->Topo;
    p->Topo = I;
    p->Tamanho++;
}

void ExibirPilha(Pilha * p)
{
    printf("Pilha de tamanho %i\n", p->Tamanho);

    int index = 1;

    for (Item * atual = p->Topo; atual != NULL; atual = atual->Anterior)
    {
        printf("%i.\t%s\n", index, atual->Chave);
        index++;
    }
}

float getValor(char * Str)
{
    Pilha * P = CriarPilha();

    for (char * token = strtok(Str, " "); token != NULL; token = strtok(NULL, " "))
    {
        Item * item = CriarItem(token);
        Empilhar(P, item);
    }

    ExibirPilha(P);
}