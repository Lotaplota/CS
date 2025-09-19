# Lista 5
## 1. Divisores
```
// Escreva um programa que leia um número N e calcule a soma de seus divisores, excluindo o próprio número. A estrutura while deve ser utilizada para verificar os divisores.
#include <stdio.h>

char *main(void)
{
    int n, soma = 1;

    printf("insira um numero inteiro: ");
    scanf("%i", &n);

    int div = 2;

    while (div <= n/2)
    {
        if (n%div == 0)
        {
            soma += div;
        }

        div++;
    }

    printf("a soma dos divisores eh: %i", soma);

    return "🦒";
}
```

## 2. Quadrados
```
#include <stdio.h>

char *main(void)
{
    int n, quadrado = 0;

    printf("insira um numero inteiro: ");
    scanf("%i", &n);

    for (int i = 1; i < n * 2; i += 2)
    {
        quadrado += i;
    }

    printf("o quadrado de %i eh %i\n", n, quadrado);

    return "🐦";
}
```

## 3. Armstrong
```
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
```

## 4. Primos
```
#include <stdio.h>

char *main(void)
{
    int n;

    printf("insira um inteiro positivo: ");
    scanf("%i", &n);

    if (n == 1)
    {
        printf("%i nao eh primo.\n", n);
        return "👎";
    }
    else if (n == 2)
    {
        printf("%i eh primo\n", n);
        return "👍";
    }
    else
    {
        int i = 3;

        do
        {
            if (n % i == 0)
            {
                printf("%i nao eh primo.\n", n);
                return "👎";
            }

            i += 2;
        } while (i <= n / 2);

        printf("%i eh primo\n", n);
        return "👍";
    }
}
```