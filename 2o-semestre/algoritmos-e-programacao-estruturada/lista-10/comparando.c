#include <stdio.h>

void comum(int[], int[]);
void unico(int[], int[], int);

char* main(void)
{
    int v[4], w[4];
    v[0] = 6; w[0] = 7;
    v[1] = 8; w[1] = 4;
    v[2] = 4; w[2] = 8;
    v[3] = 1; w[3] = 3;

    comum(v, w);
    unico(v, w, 1);
    unico(w, v, 2); 
}

void comum(int a[], int b[])
{
    printf("valores em comum: ");
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (a[i] == b[j])
            {
                printf("%i, ", a[i]);
            }
        }
    }
    printf("\n");
}

void unico(int a[], int b[], int c)
{
    printf("valores unicos do %io vetor: ", c);

    for (int i = 0; i < 4; i++)
    {
        int ehUnico = 1;

        for (int j = 0; j < 4; j++)
        {
            if (a[i] == b[j])
            {
                ehUnico = 0;
            }
        }
            
        if (ehUnico)
        {
            printf("%i, ", a[i]);
        }
    }
}

void 