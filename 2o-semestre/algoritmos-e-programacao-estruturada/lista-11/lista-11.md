# Lista 11
## 1. Diagonal
```
#include <stdio.h>

#define D 3

char* main(void)
{
    char m[D][D] = {
    {'b', 'o', 'm'},
    {'d', 'i', 'a'},
    {'c', 'i', 'a'}};

    for (int i = 0; i < D; i++)
    {
        for (int j = 0; j < D; j++)
        {
            if (i == j)
                printf("%c ", m[i][j]);
            else
                printf("  ");
        }

        printf("\n");
    }

    return "🪆";
}
```

## 2. Determinante
```
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
```

## 3. strcpy()
```
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
```

## 4. strlen()
```
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
```

## 5. strcat()
```
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
```

## 6. strpos()
```
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
```

## 7. strdel()
```
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
```