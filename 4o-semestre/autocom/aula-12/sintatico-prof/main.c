#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexico.h"
#include "sintatico.h"

int main(void) {
    char entrada[1024];
    puts("Digite uma expressao (ate 1023 caracteres):");
    if (!fgets(entrada, sizeof(entrada), stdin)) {
        fprintf(stderr, "Nao foi possivel ler a expressao.\n");
        return EXIT_FAILURE;
    }
    if (!strchr(entrada, '\n')) {
        int c = getchar();
        if (c != '\n' && c != EOF) {
            fprintf(stderr, "Expressao excede 1023 caracteres.\n");
            return EXIT_FAILURE;
        }
    }

    /* Primeira passagem: exibe os tokens, como no lexico original. */
    Scanner scanner;
    iniciar(&scanner, entrada);
    puts("Linha\tColuna\tLexema\tToken");
    for (;;) {
        Token t = proximo_token(&scanner);
        TipoToken tipo = t.tipo;
        printf("%d\t%d\t%s\t%s\n", t.linha, t.coluna, t.lexema, nome_token(tipo));
        free(t.lexema);
        if (tipo == TOKEN_ERRO) return EXIT_FAILURE;
        if (tipo == TOKEN_FIM) break;
    }

    /* Reinicia o Scanner: o parser solicita os tokens sob demanda. */
    iniciar(&scanner, entrada);
    AST *raiz = parse_ast(&scanner);
    if (!raiz) return EXIT_FAILURE;
    puts("Expressao sintaticamente valida.\nArvore sintatica abstrata:");
    ast_print(raiz, 0);
    int salvo = ast_to_dot(raiz, "arvore.dot");
    ast_free(raiz);
    if (!salvo) return EXIT_FAILURE;
    puts("Arvore salva em arvore.dot.");
    return EXIT_SUCCESS;
}
