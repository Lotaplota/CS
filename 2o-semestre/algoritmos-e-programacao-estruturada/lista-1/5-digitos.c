// Escreva um aplicativo que insere um número consistindo em cinco dígitos do usuário, separa o número em seus dígitos individuais e imprime os dígitos separados uns dos outros por três espaços cada. Por exemplo, se o usuário digitar o número 42339, o programa deve imprimir:
#include <stdio.h>
#include <math.h>

int main(void)
{
    unsigned int n;
    printf("insira um numero inteiro positivo\n");
    scanf("%u", &n);

    int nlen = 1;

    while (pow(10, nlen) <= n)
    {
        nlen++;
    }

    unsigned int cur;
    unsigned int rem = n;

    for (int i = 0; i < nlen; i++)
    {
        cur = rem / pow(10, nlen - 1 - i);
        rem %= (unsigned int)pow(10, nlen - 1 - i); // idk why I need to cast here but not in the line above
        printf("%i   ", cur);
    }
}