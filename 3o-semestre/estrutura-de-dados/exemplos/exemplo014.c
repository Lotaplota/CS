#include <stdio.h>
#include <stdlib.h>

void ehPrimo(int N)
{
    if (N <= 1)
    {
        printf("n eh primo\n");
    }

    for(int i = 2; i < N; i++)
    {
        printf("i = %i\n", i); // DONKEY
        if (N % i == 0)
        {
            printf("n eh primo\n");
            return;
        }
    }

    printf("eh primo\n");
    return;
}

int main(void)
{
    int n = 0;
    printf("insira um numero: ");
    scanf("%i", &n);
    // printf("numero eh: " );

    ehPrimo(n);
}
