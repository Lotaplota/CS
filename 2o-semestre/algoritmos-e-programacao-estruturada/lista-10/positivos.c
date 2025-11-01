#include <stdio.h>

char *main(void)
{
    int v[10];

    v[0] = 5; v[1] =-3; v[2] = 8; v[3] = -7; v[4] = 10; v[5] = -8; v[6] = 50; v[7] = -1; v[8] = 1; v[9] =-9;

    for (int i = 0; i< 10; i++)
    {
        if (v[i] < 0)
            v[i] = 0;
        
        printf("v[%i]: %i\n", i, v[i]);
    }

    return "⛽";
}