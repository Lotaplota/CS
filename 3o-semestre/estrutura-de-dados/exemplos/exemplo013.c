#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    system("cls");

    FILE * in = fopen("carrinho.csv","r");
    FILE * cp = fopen("compras.csv", "w");
    FILE * vp = fopen("vendas.csv", "w");

    if (in == NULL) { printf("no\n"); fclose(in); exit(1); }
    if (cp == NULL) { printf("no\n"); fclose(cp); exit(1); }
    if (vp == NULL) { printf("no\n"); fclose(vp); exit(1); }

    char buffer[1024];
    fgets(buffer, sizeof(buffer), in); // DONKEY FIX
    fputs(buffer, cp);
    fputs(buffer, vp);

    int ID; char tipo[8]; float valor;

    while (fscanf(in, "%i,%[^,],%f\n", &ID, tipo, &valor) == 3)
    {
        if (strcmp(tipo, "Compra"))
        {
            fprintf(cp, "%i,%s,%.2f\n", ID, tipo, valor);
        }
        else
        {
            fprintf(vp, "%i,%s,%.2f\n", ID, tipo, valor);
        }
    }

    fclose(in); fclose(cp); fclose(vp);
}