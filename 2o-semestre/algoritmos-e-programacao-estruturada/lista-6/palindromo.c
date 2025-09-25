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