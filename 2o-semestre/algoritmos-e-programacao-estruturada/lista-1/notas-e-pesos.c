// Faça um programa que receba três notas e seus respectivos pesos, calcule e mostre a média ponderada dessas notas.
#include <stdio.h>

int main(void)
{
    float notas[3] = {};
    printf("Insira tres notas no formato #,#,#\n");
    scanf("%f,%f,%f", &notas[0], &notas[1], &notas[2]);

    int pesos[3] = {};
    printf("Insira os pesos de cada nota no formato #,#,#\n");
    scanf("%i,%i,%i", &pesos[0], &pesos[1], &pesos[2]);

    int somaPesos = pesos[0] + pesos[1] + pesos[2];

    float media = 0;
    for (int i = 0; i < 3; i++)
    {
        media += notas[i] * pesos[i];
    }

    media /= somaPesos;
    printf("Sua media final e: %f\n", media);
}
