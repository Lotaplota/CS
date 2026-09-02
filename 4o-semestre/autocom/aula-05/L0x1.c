#include <stdio.h>
#include <stdlib.h>

int reconhece_L(char * s);

int main(int argc, char ** argv)
{
    if (argc < 2) { perror("Entrada invahlida."); return 1; }

    for (int i = 1; i < argc; i++)
    {
        printf("%s\t%s\n", argv[i], reconhece_L(argv[i + 1]) ? "ACEITA" : "REJEITA");
    }
}

int reconhece_L (char * s)
{
    int i = 0, n0 = 0, n1 = 0;

    if (s == NULL || s[0] == '\0') return 1;

    while (s[i] == '0') { n0++; i++; }
    while (s[i] == '1') { n1++; i++; }

    if (s[i] != '\0') return 0; // I gotta fix this part...

    if (n0 == n1) return 1;
}