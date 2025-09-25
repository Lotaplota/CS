#include <math.h>
#include <stdio.h>

char *main(void)
{
    float π = 0; // Que pecado...
    int n = 148482;

    for (int i = 0; i < n; i++)
    {
        float den = pow(-1, i) * (2 * i + 1);
        π += 4 / den;
    }

    printf("%f", π);

    return "⭕";
}