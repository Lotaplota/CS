// Faça um programa que receba o valor de um depósito (c) e o valor da taxa de juros em porcentagem (i), calcule e mostre o valor do rendimento em juros simples (j) e o valor total depois do rendimento
#include <stdio.h>

int main(void)
{
    float c, i; // Não precisa especificar o tempo?

    printf("insira o valor do deposito e o valor da taxa de juros no formato #,#%%\n");
    scanf("%f,%f%%", &c, &i);

    i /= 100;

    printf("o valor retornado sera de R$%.2f, com um rendimento de R$%.2f\n", c * (1 + i), c * i);
}