// Faça um programa que calcule a distância entre dois pontos no plano cartesiano.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} Ponto;

int main(void)
{
    Ponto a, b;

    printf("insira as coordenadas do primeiro ponto no formato #,#\n");
    scanf("%f,%f", &a.x, &a.y);
    printf("agora as do segundo ponto no formato #,#\n");
    scanf("%f,%f", &b.x, &b.y);
    printf("ax: %f, ay: %f, bx: %f, by: %f\n", a.x, a.y, b.x, b.y); // DONKEY

    float d = sqrt(pow(abs(a.x - b.x), 2) + pow(abs(a.y - b.y), 2));

    printf("A distancia destes pontos e %f", d);
}