#include <stdio.h>

void strcpy(char* s, char* t)
{
    int i = 0;
    while (t[i] != '\0')
    {
        s[i] = t[i];
        i++;
    }
}

char* main(void)
{
    char ass[16];
    char tea[] = "Oi professor o/";

    strcpy(ass, tea);

    printf("%s", ass);

    return "🧩";
}