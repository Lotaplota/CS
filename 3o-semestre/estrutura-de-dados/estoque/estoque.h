#ifndef PRODUTOS_H
#define PRODUTOS_H

#define MAX_NAME_LENGTH 64
#define MAX_PRODUCTS 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int qt;
    float price;
} Product;

int getFromFile(char *, Product *);
void createFile(Product *, int);
int update(Product *, int, char *, int, float);


#endif