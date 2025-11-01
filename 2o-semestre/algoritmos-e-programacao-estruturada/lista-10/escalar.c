#include <stdio.h>

char* main(void)
{
    int c;
    printf("insira o tamanho do vetor: ");
    scanf("%i", &c);

    int scalar = 0, v[c], w[c];

    for (int i = 0; i < c; i++)
    {
        printf("insira o %io valor do 1o vetor: ", i + 1);
        scanf("%i", &v[i]);

        printf("insira o %io valor do 2o vetor: ", i + 1);
        scanf("%i", &w[i]);
    }

    for (int i = 0; i < c; i++)
    {
        scalar += v[i]*w[i];
    }

    printf("o produto escalar eh %i", scalar);

    return "🐼";
}