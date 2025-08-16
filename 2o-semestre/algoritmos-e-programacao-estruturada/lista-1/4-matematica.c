// Faça um programa que receba um número positivo e maior que zero, calcule, e mostre:
//   a) O número digitado ao quadrado.
//   b) O número digitado ao cubo.
//   c) A raiz quadrada do número digitado.
//   d) A raiz cúbica do número digitado
#include <stdio.h>
#include <math.h>

int main(void)
{
    unsigned int n;
    printf("insira um numero positivo e maior que zero\n");
    scanf("%u", &n);

    printf("quadrado: %.0f\n", pow(n, 2));
    printf("cubo: %.0f\n", pow(n, 3));
    printf("raiz quadrada: %f\n", sqrt(n));
    printf("raiz cubica: %f\n", cbrt(n));
}
