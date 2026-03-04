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

    FILE * out = fopen("resultado.html", "w");
    if (out == NULL)
    {
        printf("no\n");
        exit(1);
    }

    fprintf(out, "<!DOCTYPE html>\n<html lang=\"pt-BR\">\n<head>\n"
    "<meta charset=\"UTF-8\">\n<title>Lista de Compras</title>\n"
    "<style>"
    "body{font-family:Arial,Helvetica,sans-serif;margin:24px}"
    "table{border-collapse:collapse;width:720px;max-width:100%%}"
    "th,td{border:1px solid #ccc;padding:8px;text-align:left}"
    "th{background:#f2f2f2}"
    "tfoot td{font-weight:bold}"
    "tbody tr:nth-child(even){background:#fafafa}"
    "</style>\n</head>\n<body>\n"
    "<h2>Relatório de Compras</h2>\n"
    "<table>\n"
    "<thead><tr>"
    "<th>#</th><th>Produto</th><th>Quantidade</th>"
    "<th>Preço unitário (R$)</th><th>Total do item (R$)</th>"
    "</tr></thead>\n<tbody>\n");
    // DONKEY CONTINUE

    char lixo[1024];
    fscanf(in,"%[^\n]\n", lixo);

    char produto[40]; int quantidade, i = 1; float preco, total = 0;

    while (fscanf(in, "%[^,],%i,%f\n", produto, &quantidade, &preco) == 3)
    {
        printf("%i) %s: %i * %.2f = %.2f\n", i, produto, quantidade, preco, quantidade * preco);
        total += quantidade * preco;
        i++;
    }

    printf("\nO total da compra é R$%.2f\n", total);
    fclose(in); fclose(out);
}