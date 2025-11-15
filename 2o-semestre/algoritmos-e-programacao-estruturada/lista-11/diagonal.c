#include <stdio.h>

#define D 3

char* main(void)
{
    char m[D][D] = {
    {'b', 'o', 'm'},
    {'d', 'i', 'a'},
    {'c', 'i', 'a'}};

    for (int i = 0; i < D; i++)
    {
        for (int j = 0; j < D; j++)
        {
            if (i == j)
                printf("%c ", m[i][j]);
            else
                printf("  ");
        }

        printf("\n");
    }

    return "🪆";
}