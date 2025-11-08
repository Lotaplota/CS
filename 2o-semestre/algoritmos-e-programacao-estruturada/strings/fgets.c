#include <stdio.h>

char* main(void)
{
    char text[100];

    printf("escreva: ");
    // scanf("%s", &text);
    fgets(text, sizeof(text), stdin);

    // printf("seu texto foi: %s\n", text);

    int i = 0;
    while (text[i] !='\0')
    {
        printf(" %c ", text[i]);
        i++;
    }
}