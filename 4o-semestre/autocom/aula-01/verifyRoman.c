#include <stdio.h>
#include "./helpers.c"

void verify(char * n)
{
    for (int i = 0; i < lenOf(n); i++)
    {
        char c = lowerize(n[i]);

        if (c != 'i' && c != 'v' && c != 'x' && c != 'l' && c != 'c' && c != 'd' && c != 'm')
        {
            printf("\'%s\' is not a valid roman number.\n", n);
            return;
        }
    }

    printf("\'%s\' is a valid roman number.\n", n);
}

int main(void)
{
    char * roman = "CIxXV";

    verify(roman);
}