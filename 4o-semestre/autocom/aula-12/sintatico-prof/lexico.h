#ifndef LEXICO_H
#define LEXICO_H

typedef enum {
    TOKEN_INTEIRO,
    TOKEN_MAIS,
    TOKEN_MENOS,
    TOKEN_MULT,
    TOKEN_DIV,
    TOKEN_POT,
    TOKEN_ABRE_PAR,
    TOKEN_FECHA_PAR,
    TOKEN_ERRO,
    TOKEN_FIM
} TipoToken;

typedef struct {
    TipoToken tipo;
    char * lexema;
    int linha;
    int coluna;
} Token;

typedef struct {
    char * src; // String geradora (a ser lexicada e sintaticada)
    int linha;  // Linha atual do scanner
    int coluna; // Coluna atual do scanner
    int i;      // Quantidade de caracteres lidos
    char c;     // Caractere atual
} Scanner;


char * nome_token(TipoToken t);
char * str_ndup (char * s, int n);

void iniciar(Scanner * sc, char * texto);
void avancar (Scanner * sc);
void pular_espacos(Scanner * sc);

Token popular_token (TipoToken tipo, char *ini, int n, int lin, int col);
Token token_simples(Scanner * sc, TipoToken tipo);
Token token_erro_msg (Scanner * sc, char * msg);
Token coletar_inteiro (Scanner * sc);
Token proximo_token(Scanner * sc);


#endif
