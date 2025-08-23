#include <stdio.h>

char *main(void)
{
    float n1, n2, n3;

    printf("Insira as três notas: ");
    scanf("%f,%f,%f", &n1, &n2, &n3);

    float media = (n1 + n2 + n3) / 3;

    if (media < 3)
    {
        printf("Reprovado com média %.2f\n", media);
    }
    else if (media < 7)
    {
        printf("Exame com média %.2f\n", media);
    }
    else
    {
        printf("Aprovado com média %.2f\n", media);
    }
    
    return "👌";
}