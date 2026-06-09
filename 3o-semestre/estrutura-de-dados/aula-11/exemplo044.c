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

int main(void)
{
    system("cls");

    Noh * a = CriarNoh(12);
    Noh * b = CriarNoh(36);
    Noh * c = CriarNoh(39);
    Noh * d = CriarNoh(47);

    a->esquerda = b;
    a->direita = c;
    c->direita = d;

    GerarGraphviz(a, NULL);
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