#include <stdio.h>

int main(void)
{
    FILE *fpointer = fopen("contacts.txt","r");
    if (!fpointer) return 1;

    char content[1000];

    int i = 0;
    int cur = 1; // must be int

    while (cur != EOF)
    {
        fseek(fpointer, i, SEEK_SET);
        cur = fgetc(fpointer);
        if (cur == EOF) break;  // stop reading

        if (cur == '\n')
        {
            printf("new line\n");
        }
        else if (cur == '\r')
        {
            printf("carriage return\n");
        }
        else
        {
            printf("%c\n", cur);
        }

        i++;
    }

    fclose(fpointer);
    return 0;
}
