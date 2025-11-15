#include <stdio.h>

int strpos(char* s, char l)
{
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == l)
        {
            return i;
        }

        i++;
    }

    return -1;
}

char* main(void)
{
    char abc[] = "abcdefghijklmnopqrstuvwxyz";
    char letra = 'd';

    printf("a letra %c eh a %ia letra do alfabeto.\n", letra, strpos(abc, letra) + 1);

    return "🦚";
}