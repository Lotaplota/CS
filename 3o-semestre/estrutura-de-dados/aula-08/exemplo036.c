#include <stdio.h>
#include <stdlib.h>

#define MAX 3

typedef struct {
    int Chave;
} Item;

Item CriarItem(int);

// Implementação de uma fila usando ARRAY (os elementos da fila serão dispostos em um vetor)
int main(void)
{
    Item V[MAX]; // Vetor estático é um vetor definido em tempo de compilação

    V[0] = CriarItem(137);
    V[1] = CriarItem(241);
    V[2] = CriarItem(339);

    for (int i = 0; i < MAX; i++) printf("%i\n", V[i].Chave);
}

Item CriarItem(int chave) {
    Item I;
    I.Chave = chave;
    return I;
}