// O enunciado continha alguns períodos não contabilizados (ex: temperaturas entre 20 e 21),
// então eu implementei da maneira mais simples. Espero que não seja um problema :^]

#include <stdio.h>

char *main(void)
{
    float t;
    printf("Insira a temperatura em graus Celsius: ");
    scanf("%f", &t);

    if (t < 10)
        printf("%.1f, muito frio.", t);
    else if (t < 20)
        printf("%.1f, frio.", t);
    else if (t < 30)
        printf("%.1f, agradável.", t);
    else if (t <= 40)
        printf("%.1f, quente.", t);
    else
        printf("%.1f, muito quente.", t);
    
    return "🐊";
}