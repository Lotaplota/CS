#include <stdio.h>

void strcat(char* s, char* t, char* u)
{
    int i = 0;
    while (s[i] != '\0')
    {
        u[i] = s[i];
        i++;
    }

    int j = 0;
    while (t[j] != '\0')
    {
        u[i] = t[j];
        i++; j++;
    }

    u[i] = '\0';
}

char* main(void)
{
    char ass[] = "one";
    char tea[] = "two";
    char you[7];

    strcat(ass, tea, you);

    printf("string 1: %s\nstring 2: %s\nstring 1 e 2: %s\n", ass, tea, you);

    return "🥏";
}