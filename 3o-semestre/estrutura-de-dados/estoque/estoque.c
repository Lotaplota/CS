#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estoque.h"

int getFromFile(char * filename, Product * arr)
{
    FILE * fr = fopen(filename, "r");
    if (!fr) { perror("error reading from file"); return -1; }

    char buffer[1024];
    fgets(buffer, sizeof(buffer), fr);

    int i = 0;
    while (fgets(buffer, sizeof(buffer), fr))
    {
        Product aux;
        sscanf(buffer, "%[^,],%i,%f", aux.name, &aux.qt, &aux.price);

        arr[i] = aux;
        i++;
    }

    fclose(fr);

    return i; // Returning the quantity of lines read by the while argument
}

void createFile(Product * stock, int p_qt)
{
    FILE * fw = fopen("estoque.csv", "w");

    fprintf(fw, "Produto,Quantidade,Preço\n");

    for (int i = 0; i < p_qt; i++)
    {
        fprintf(fw, "%s,%i,%.2f\n", stock[i].name, stock[i].qt, stock[i].price);
    }

    fclose(fw);
}

int update(Product * stock, int p_qt, char * name, int new_qt, float new_price)
{
    for (int i = 0; i < p_qt; i++)
    {
        if (strcmp(stock[i].name, name) == 0)
        {
            stock->qt = new_qt;
            stock->price = new_price;

            createFile(stock, p_qt);

            return p_qt;
        }

        perror("The specified name was not found.\n");
        return -1;
    }
}