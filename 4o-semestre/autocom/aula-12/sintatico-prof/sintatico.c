#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sintatico.h"

/* E -> T { ('+' | '-') T }
 * T -> U { ('*' | '/') U }
 * U -> ('+' | '-') U | P
 * P -> F [ '^' U ]
 * F -> INTEIRO | '(' E ')'
 * Potencia associa a direita e precede sinais unarios.
 */
typedef struct {
    Scanner *scanner;
    Token atual;
    int erro;
    unsigned nivel;
} Parser;

static AST *expressao(Parser *p);
static AST *unario(Parser *p);

void ast_free(AST *t) {
    if (!t) return;
    ast_free(t->left);
    ast_free(t->right);
    free(t->lexema);
    free(t);
}

static void erro(Parser *p, const char *mensagem) {
    if (p->erro) return;
    fprintf(stderr, "Erro sintatico na linha %d, coluna %d: %s; encontrado %s ('%s').\n",
            p->atual.linha, p->atual.coluna, mensagem,
            nome_token(p->atual.tipo), p->atual.lexema);
    p->erro = 1;
}

static void consumir(Parser *p) {
    if (p->erro) return;
    free(p->atual.lexema);
    p->atual = proximo_token(p->scanner);
    if (p->atual.tipo == TOKEN_ERRO) {
        fprintf(stderr, "Erro lexico na linha %d, coluna %d: %s.\n",
                p->atual.linha, p->atual.coluna, p->atual.lexema);
        p->erro = 1;
    }
}

/* Assume propriedade dos filhos, inclusive em caso de falha. */
static AST *novo(Parser *p, TipoToken tipo, const char *lexema, AST *l, AST *r) {
    AST *t = calloc(1, sizeof(*t));
    char *copia = t ? malloc(strlen(lexema) + 1) : NULL;
    if (!t || !copia) {
        free(t);
        ast_free(l);
        ast_free(r);
        fprintf(stderr, "Memoria insuficiente para a arvore.\n");
        p->erro = 1;
        return NULL;
    }
    strcpy(copia, lexema);
    t->tipo = tipo;
    t->lexema = copia;
    t->left = l;
    t->right = r;
    return t;
}

static AST *primario(Parser *p) {
    if (p->erro) return NULL;
    if (p->atual.tipo == TOKEN_INTEIRO) {
        AST *t = novo(p, TOKEN_INTEIRO, p->atual.lexema, NULL, NULL);
        consumir(p);
        return t;
    }
    if (p->atual.tipo == TOKEN_ABRE_PAR) {
        consumir(p);
        AST *t = expressao(p);
        if (!p->erro && p->atual.tipo != TOKEN_FECHA_PAR)
            erro(p, "esperado ')'");
        if (p->erro) { ast_free(t); return NULL; }
        consumir(p);
        return t;
    }
    erro(p, "esperado inteiro ou '('");
    return NULL;
}

static AST *potencia(Parser *p) {
    AST *l = primario(p);
    if (!p->erro && p->atual.tipo == TOKEN_POT) {
        consumir(p);
        AST *r = unario(p);
        if (p->erro) { ast_free(l); ast_free(r); return NULL; }
        l = novo(p, TOKEN_POT, "^", l, r);
    }
    return l;
}

static AST *unario(Parser *p) {
    if (p->erro) return NULL;
    if (p->nivel >= 256) {
        erro(p, "limite de aninhamento excedido");
        return NULL;
    }
    p->nivel++;
    AST *t;
    if (p->atual.tipo == TOKEN_MAIS || p->atual.tipo == TOKEN_MENOS) {
        TipoToken tipo = p->atual.tipo;
        consumir(p);
        AST *r = unario(p);
        if (p->erro) { ast_free(r); t = NULL; }
        else t = novo(p, tipo, tipo == TOKEN_MAIS ? "+" : "-", NULL, r);
    } else t = potencia(p);
    p->nivel--;
    return t;
}

static AST *termo(Parser *p) {
    AST *l = unario(p);
    while (!p->erro && (p->atual.tipo == TOKEN_MULT || p->atual.tipo == TOKEN_DIV)) {
        TipoToken tipo = p->atual.tipo;
        consumir(p);
        AST *r = unario(p);
        if (p->erro) { ast_free(l); ast_free(r); return NULL; }
        l = novo(p, tipo, tipo == TOKEN_MULT ? "*" : "/", l, r);
    }
    return l;
}

static AST *expressao(Parser *p) {
    AST *l = termo(p);
    while (!p->erro && (p->atual.tipo == TOKEN_MAIS || p->atual.tipo == TOKEN_MENOS)) {
        TipoToken tipo = p->atual.tipo;
        consumir(p);
        AST *r = termo(p);
        if (p->erro) { ast_free(l); ast_free(r); return NULL; }
        l = novo(p, tipo, tipo == TOKEN_MAIS ? "+" : "-", l, r);
    }
    return l;
}

AST *parse_ast(Scanner *scanner) {
    Parser p = {0};
    p.scanner = scanner;
    consumir(&p);
    AST *raiz = expressao(&p);
    if (!p.erro && p.atual.tipo != TOKEN_FIM)
        erro(&p, "esperado operador ou fim da expressao");
    free(p.atual.lexema);
    if (p.erro) { ast_free(raiz); return NULL; }
    return raiz;
}

void ast_print(const AST *t, int profundidade) {
    if (!t) return;
    for (int i = 0; i < profundidade; i++) fputs("  ", stdout);
    if (t->tipo == TOKEN_INTEIRO) printf("INTEIRO(%s)\n", t->lexema);
    else printf("%s%s\n", t->lexema, t->left ? "" : " (unario)");
    ast_print(t->left, profundidade + 1);
    ast_print(t->right, profundidade + 1);
}

static int dot_rec(const AST *t, FILE *f, int *id) {
    int atual = (*id)++;
    /* Lexemas sao apenas digitos ou operadores, sem caracteres de escape DOT. */
    fprintf(f, "  n%d [label=\"%s%s\"];\n", atual, t->lexema,
            t->tipo != TOKEN_INTEIRO && !t->left ? " (unario)" : "");
    if (t->left) {
        int filho = dot_rec(t->left, f, id);
        fprintf(f, "  n%d -> n%d;\n", atual, filho);
    }
    if (t->right) {
        int filho = dot_rec(t->right, f, id);
        fprintf(f, "  n%d -> n%d;\n", atual, filho);
    }
    return atual;
}

int ast_to_dot(const AST *t, const char *caminho) {
    FILE *f = fopen(caminho, "w");
    if (!f) { perror(caminho); return 0; }
    fputs("digraph AST {\n  node [fontname=\"Consolas\"];\n", f);
    int id = 0;
    if (t) dot_rec(t, f, &id);
    fputs("}\n", f);
    int ok = !ferror(f);
    if (fclose(f) != 0) ok = 0;
    if (!ok) fprintf(stderr, "Falha ao salvar a arvore.\n");
    return ok;
}
