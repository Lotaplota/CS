#include <stdio.h>

char *main(void)
{
    float n1, n2, n3;
    printf("Insira as três notas: ");
    scanf("%f,%f,%f", &n1, &n2, &n3);

    float media = (2*n1 + 3*n2 + 5*n3) / 10;

    if (media < 5)
        printf("%.2f: E", media);
    else if (media < 6)
        printf("%.2f: D", media);
    else if (media < 7)
        printf("%.2f: C", media);
    else if (media < 8)
        printf("%.2f: B", media);
    else
        printf("%.2f: A", media);
    
    return "💯";
}