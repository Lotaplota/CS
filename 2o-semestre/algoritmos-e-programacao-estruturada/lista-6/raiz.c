#include <stdio.h>

char *main(void)
{
    float k = 1;
    int n;

    printf("insira um numero para descobrir sua raiz e a quantidade de passos: ");
    scanf("%i", &n);

    for (int i = 0; i < 12; i++)
    {
        k = (k + n / k) / 2;
        printf("k[%i] = %f\n", i + 1, k);
    }

    return "➕";
}