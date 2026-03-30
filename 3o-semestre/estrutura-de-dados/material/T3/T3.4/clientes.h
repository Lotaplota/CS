#ifndef CLIENTES_H
#define CLIENTES_H

#define MAX_CLIENTES 10

typedef struct
{
    int ID;
    char nome[32];
    char email[32];
} Cliente;

void gerarDeArquivo(char * filename, Cliente * arr);
void delete(char * filename, int id);




#endif