#include <stdio.h>

void minimax(float[], float*, float*);

char* main(void)
{
    float v[4];

    v[0] = 4.5;
    v[1] = 9.1;
    v[2] = 12;
    v[3] = 2.1;

    float min = 0, max = 0;

    minimax(v, &min, &max);

    printf("minimo: %f; maximo: %f", min, max);

    return "🕊️";
}

void minimax(float a[], float *min, float *max)
{
    *min = a[0]; *max = a[0];

    for (int i = 0; i < 4; i++)
    {
        if (a[i] < *min)
        {
            *min = a[i];
        }

        if (a[i] > *max)
        {
            *max = a[i];
        }
    }
}