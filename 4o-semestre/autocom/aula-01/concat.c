#include <stdio.h>
#include <stdlib.h>

int lenOf(char * a)
{
    int i = 0;
    
    while (a[i] != '\0')
    {
        i++;
    }

    return i;
}

char * concat(char * a, char * b)
{
    int lenA = lenOf(a);
    int lenB = lenOf(b);

    int length = lenA + lenB;

    char * str = malloc(length * sizeof(char) + 1);

    int i = 0;

    for (int j = i; j < lenA; j++)
    {
        str[j] = a[j];
        i++;
    }

    for (int k = i; k < length; k++)
    {
        str[k] = b[k - lenA];
        i++;
    }

    str[length] = '\0';

    printf("concatted: %s\n", str); // DONKEY
}

int main(void)
{
    char * a = "abc ";
    char * b = "def";

    concat(a, b);
}

// TODO: can you store the string in reverse??