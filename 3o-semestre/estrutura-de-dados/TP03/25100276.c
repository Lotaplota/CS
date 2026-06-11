#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "calculadora.h"

#define PI 3.14159265358979323846

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
    printf("\t\toperando %f %s %f", a, operator, b); // DONKEY
    if (!strcmp(operator, "+")) return a + b;
    else if (!strcmp(operator, "-")) return a - b;
    else if (!strcmp(operator, "*")) return a * b;
    else if (!strcmp(operator, "/")) return a / b;
    else if (!strcmp(operator, "^")) return pow(a, b);
    else if (!strcmp(operator, "sqrt")) return sqrt(b);
    else if (!strcmp(operator, "log")) return log10(b);
    else if (!strcmp(operator, "sen")) return sin(b * PI / 180);
    else if (!strcmp(operator, "cos")) return cos(b * PI / 180);
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
    printf("\tcalculando a operassaum %s\n", operador); // DONKEY
    float a = strtof(p->Topo->Anterior->Chave, NULL);
    float b = strtof(p->Topo->Chave, NULL);
    float res = Operar(a, b, operador);
    printf("\t\tresultado: %f\n", res); // DONKEY

    // Transformando o float de resultado em um string para ser armazenado
    int len = snprintf(NULL, 0, "%f", res);
    char * strres = malloc(len + 1);
    snprintf(strres, len + 1, "%f", res);

    // Desempilhando o uhltimo item da fila apenas se for uma operassaum bahsica
    if (strcmp("sqrt", operador) && strcmp("log", operador) && strcmp("sen", operador) && strcmp("cos", operador))
    {
        Desempilhar(p);
    }
    
    // Reescrevendo o resultado na chave do item no topo da fila
    // Evita ter que empilhar um novo item ;^]
    strcpy(p->Topo->Chave, strres);
    ExibirPilha(p); // DONKEY

    free(strres);
}

// Empilha um novo item se o a chave puder ser convertida em float, se naum, verifica se eh um operador, se sim, opera os dois uhltimos nuhmeros da pilha
void Empilhar(Pilha * p, Item * I)
{
    printf("empilhando %s\n", I->Chave); // donkey
    if (!p || !I)
    { perror("Naum hah pilha ou item."); return; }

    // Verifica se a chave atual eh um nuhmero, se naum for, calcula os dois uhltimos nuhmeros
    char * endptr;
    strtod(I->Chave, &endptr);
    if (endptr == I->Chave) // nada foi parseado → é um operador
    {
        Calcular(p, I->Chave);
        return;
    }

    I->Anterior = p->Topo;
    p->Topo = I;
    p->Tamanho++;
}

float getValor(char * str)
{
    Pilha * P = CriarPilha();

    for (char * token = strtok(str, " "); token != NULL; token = strtok(NULL, " "))
    {
        Item * item = CriarItem(token);
        Empilhar(P, item);
    }

    float valor = strtof(P->Topo->Chave, NULL);

    free(P->Topo);
    free(P);

    return valor;
}

char * getInFixa(char * str)
{
    // Professor... sei nem onde começar.
}