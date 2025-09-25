# Lista 6
## 1. Caixa eletrônico
```
#include <stdio.h>

char *main(void)
{
    int n;

    while (1)
    {
        printf("insira um valor inteiro em reais: R$");
        scanf("%i", &n);
    
        if (n == 0)
            return "🐸";
    
        printf("tome essas notas: ");
    
        while (n > 0)
        {
            if (n >= 100)
            {
                printf("[100] ");
                n -= 100;
            }
            else if (n >= 50)
            {
                printf("[ 50] ");
                n -= 50;
            }
            else if (n >= 20)
            {
                printf("[ 20] ");
                n -= 20;
            }
            else if (n >= 10)
            {
                printf("[ 10] ");
                n -= 10;
            }
            else if (n >= 5)
            {
                printf("[ 5 ] ");
                n -= 5;
            }
            else{
                printf("[ 1 ] ");
                n -= 1;
            }
        }

        printf("\n");
    }
}
```

## 2. π
```
#include <math.h>
#include <stdio.h>

char *main(void)
{
    float π = 0; // Que pecado...
    int n = 148482;

    for (int i = 0; i < n; i++)
    {
        float den = pow(-1, i) * (2 * i + 1);
        π += 4 / den;
    }

    printf("%f", π);

    return "⭕";
}
```

## 3. Raíz quadrada
```
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
```

## 4. Palíndromo
```
#include <stdio.h>
#include <math.h>

int getNthDigit (int, int);

char *main(void)
{
    int n;

    while (1)
    {
        printf("insira um numero inteiro de 5 digitos: ");
        scanf("%i", &n);

        if (n < 10000 || n > 99999)
        {
            printf("o numero deve conter 5 digitos!\n");
        } else 
        {
            break;
        }
    }

    if (getNthDigit(n, 1) == getNthDigit(n, 5) &&
        getNthDigit(n, 2) == getNthDigit(n, 4))
    {
        printf ("%i eh palindromo\n", n);
    }
    else
    {
        printf("%i nao eh palindromo\n", n);
    }
    
    return "🦋";
}

int getNthDigit (int number, int n)
{
    return (int)(number / pow(10, 5 - n)) % 10;
}
```