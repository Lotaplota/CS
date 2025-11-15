#include <stdio.h>

int strlen(char* s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }

    return i;
}

char* main(void)
{
    char str[] = "Quantos caracteres?";

    int len = strlen(str);

    printf("a string tem %i caracteres.\n", len);

    return "💫";
}