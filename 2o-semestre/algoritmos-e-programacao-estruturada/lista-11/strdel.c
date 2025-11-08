// Codifique a função strdel(s,p) , que remove o caracter existente na posição p da string s . Se a posição p não existe em s, nada é feito.
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

void strdel(char* s, char* d, int pos)
{
    if (pos - 1 > strlen(s))
    {
        return;
    }

    int i = 0; int j = 0;
    while (s[i] != '\0')
    {
        if (i != pos)
        {
            d[i] = s[j];
            j++;
        }

        i++;
    }

    d[j + 1] = '\0';
}

char* main(void)
{
    char abc[] = "the quick brown fox jumped over the lazy dog";
    char newabc[100];
    
    strdel(abc, newabc, 13);

    printf("%s", newabc);

    return "👓";
}