#include <stdio.h>
#include <stdlib.h>

int lenOf(char * a)
{
    int i = 0;
    
    while (a[i] != '\0') i++;

    return i;
}

char * reverse(char * string)
{
    char * revstring = (char *) malloc(sizeof(char) * (lenOf(string) + 1));

    for (int i = 0; i < lenOf(string); i++)
    {
        revstring[i] = string[lenOf(string) - i - 1];
    }

    revstring[lenOf(string)] = '\0'; // CONTINUE FIX THIS
}

int main(void)
{
    char * s = "hamstrings";

    printf("\'%s\' is \'%s\' backwards.\n", reverse(s), s);
}