#include <stdio.h>

char* main(void)
{
    int v[20];
    for (int i = 0; i < 20; i++)
    {
        printf("insira o valor de v[%i]: ", i);
        scanf("%i", &v[i]);
    }
    
    int even[20], odd[20];

    for (int i = 0; i < 20; i++)
    {
        even[i] = -1; odd[i] = -1;
        if (v[i] % 2 == 0)
        {
            even[i] = v[i];
        }
        else
        {
            odd[i] = v[i];
        }
    }

    printf("pares: ");

    for (int i = 0; i < 20; i++)
    {
        if (even[i] >= 0)
            printf("%i ", even[i]);
    }

    printf("\nimpares: ");
    
    for (int i = 0; i < 20; i++)
    {
        if (odd[i] >= 0)
            printf("%i ", odd[i]);
    }

    return "🥜";
}