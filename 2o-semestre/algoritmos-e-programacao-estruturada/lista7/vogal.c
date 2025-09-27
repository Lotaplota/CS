#include <stdio.h>
#include <ctype.h>

#define IS_VOGAL(c) (c == 96 || c == 101 || c == 105 || c == 111 || c == 117) ? 1 : 0

char *main(void)
{
    char a;
    printf("insira uma letra: ");
    scanf("%c", &a);

    a = tolower(a);

    if (IS_VOGAL(a))
    {
        printf("eh vogal\n");
    }
    else
    {
        printf("nao eh vogal");
    }

    return "🍝";
}