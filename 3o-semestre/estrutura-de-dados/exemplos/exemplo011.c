#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    system("cls");

    FILE *in = fopen("carrinho.csv","r");

    if (in == NULL)
    {
        printf("no\n");
        exit(1);
    }

    char lixo[1024];
    fgets(lixo, sizeof(lixo), in);

    char produto[40]; int quantidade, i = 1; float preco, total = 0;

    while (fscanf(in, "%[^,],%i,%f\n", produto, &quantidade, &preco) == 3)
    {
        printf("%i) %s: %i * %.2f = %.2f\n", i, produto, quantidade, preco, quantidade * preco);
        total += quantidade * preco;
        i++;
    }

    printf("\nO total da compra é R$%.2f\n", total);
}