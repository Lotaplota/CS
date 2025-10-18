#include <stdio.h>

int len(n)
{
    if (n % 10 == n)
        return 1;
    else
        return 1 + len(n / 10);
}

char *main(void)
{
    int a;

    printf("insira um numero natural: ");
    scanf("%i", &a);

    printf("%i tem %i digitos.\n", a, len(a));

    return "🍇";
}