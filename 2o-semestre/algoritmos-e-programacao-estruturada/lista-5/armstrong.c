// Um número de Armstrong é aquele que é igual à soma de seus dígitos elevados à potência do número de dígitos. Por exemplo, 153 é um número de Armstrong, pois 1^3 + 5^3 + 3^3 = 153. Crie um programa que imprima todos os números de Armstrong em um intervalo definido pelo usuário.

#include <stdio.h>
#include <math.h>

int lenghtof(int);

char *main(void)
{
    int n;

    printf("insira um numero inteiro: ");
    scanf("%i", &n);
    
    for (int cur = 1; cur <= n; cur++)
    {
        int curlen = lenghtof(cur);
        int soma = 0;

        for (int i = cur; i > 0; i /= 10)
        {
            soma += (int)pow(i % 10, curlen);
        }

        if (soma == cur)
        {
            printf("%i, ", cur);
        }
    }

    // removendo a última vírgula
    printf("\b\b sao todos os numeros Armstrong menores que %i.", n);

    return "👻";
}

// calcula a quantidade de dígitos de um inteiro positivo
int lenghtof(int n)
{
    int num = n;
    int len = 0;

    while (num > 0)
    {
        num /= 10;
        len++;
    }

    return len;
}
