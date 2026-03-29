#include <stdio.h>

#include "estoque.h"

int main(void)
{
    Product stock[MAX_PRODUCTS];
    int product_qt = getFromFile("estoque.csv", stock);

    if (product_qt < 1) { perror("error getting from file"); return -1; }

    update(stock, product_qt,"Mouse", 35, 32.50);
}