#include <stdio.h>

char *main(void)
{
    int s = 5, w[9];
    w[3] = 0; w[2];
    printf("%i\n", w[8]);

    w[0] = 17;
    w[s/2] = 9;
    w[2*s - 2] = 95;
    w[s-1] = w[8]/2;
    w[s] = w[2];
    w[s + 1] = w[s] + w[s-1];
    w[w[2]-2] = 78;
    w[w[s]-1] = w[1]*w[s];

    for (int i = 0; i < 9; i++)
    {
        printf("w[%i]: %i\n", i, w[i]);
    }

    printf("%i\n", w[w[2]-2]);
}