#include <stdio.h>

#define D 3

char* main(void)
{
    int m[D][D] = {
    {1, 2, 3},
    {2, 4, 6},
    {1, 1, 1}};

    int det = (
        m[0][0] * (m[1][1]*m[2][2] - m[1][2]*m[2][1]) -
        m[0][1] * (m[1][0]*m[2][2] - m[1][2]*m[2][0]) +
        m[0][2] * (m[1][0]*m[2][1] - m[1][1]*m[2][0])
    );

    printf("a determinante da matriz eh %i", det);

    return "📠";
}

// 00 01 02
// 10 11 12
// 20 21 22