#include <stdio.h>
#include <stdlib.h>

#define QT_FILHOS 6

typedef struct Noh
{
    int Valor;
    struct Noh * esquerda;
    struct Noh * direita;
} Noh;

Noh * CriarNoh(int);
void GerarGraphviz(Noh * Raiz, FILE *arquivo);
Noh * InserirNoh(Noh * raiz, int v);

int main(void)
{
    system("cls");

    Noh * Raiz = CriarNoh(50);
    InserirNoh(Raiz, 30);
    InserirNoh(Raiz, 70);
    InserirNoh(Raiz, 20);
    InserirNoh(Raiz, 60);
    InserirNoh(Raiz, 40);
    InserirNoh(Raiz, 80);
    InserirNoh(Raiz, 10);
    InserirNoh(Raiz, 12);
    InserirNoh(Raiz, 44);
    InserirNoh(Raiz, 14);
    InserirNoh(Raiz, 23);


    GerarGraphviz(Raiz, NULL);
}

Noh * CriarNoh(int v)
{
    Noh * n = (Noh *) malloc(sizeof(Noh));

    if (!n) {perror("Naum hah memohria para armazenar esse item"); exit(1);}

    n->Valor = v;
    n->esquerda = NULL;
    n->direita = NULL;

    return n;
}

void GerarGraphviz(Noh * Raiz, FILE *arquivo) {
    int raizInicial = 0;

    if (Raiz == NULL) return;

    if (arquivo == NULL) {

        raizInicial = 1;

        arquivo = fopen("arvore.dot", "w");

        if (arquivo == NULL) {
            printf("Erro ao criar arquivo.\n");
            return;
        }

        fprintf(arquivo, "digraph Arvore {\n");
        fprintf(arquivo, "    node [shape=circle];\n\n");
    }

    fprintf(arquivo,
            "    \"%p\" [label=\"%d\"];\n",
            (void *)Raiz,
            Raiz->Valor);

    if (Raiz->esquerda != NULL) {

        fprintf(arquivo,
                "    \"%p\" -> \"%p\";\n",
                (void *)Raiz,
                (void *)Raiz->esquerda);

        GerarGraphviz(Raiz->esquerda, arquivo);
    }

    if (Raiz->direita != NULL) {

        fprintf(arquivo,
                "    \"%p\" -> \"%p\";\n",
                (void *)Raiz,
                (void *)Raiz->direita);

        GerarGraphviz(Raiz->direita, arquivo);
    }

    if (raizInicial) {

        fprintf(arquivo, "}\n");

        fclose(arquivo);
    }
}

Noh * InserirNoh(Noh * raiz, int v)
{
    if (!raiz) return CriarNoh(v);

    if (v < raiz->Valor) raiz->esquerda = InserirNoh(raiz->esquerda, v);
    else raiz->direita = InserirNoh(raiz->direita, v);

    return raiz;
}

// search for the book "projetos de algoritmos nivio ziviani"