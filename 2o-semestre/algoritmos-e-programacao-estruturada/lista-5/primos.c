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