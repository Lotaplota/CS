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