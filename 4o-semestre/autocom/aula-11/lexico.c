#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

typedef enum {
    TOKEN_INTEIRO,
    TOKEN_MAIS,      // +
    TOKEN_MENOS,     // -
    TOKEN_MULT,      // *
    TOKEN_DIV,       // /
    TOKEN_ABRE_PAR,  // (
    TOKEN_FECHA_PAR, // )
    TOKEN_FIM,
    TOKEN_ERRO
} TipoToken;

typedef struct {
    TipoToken tipo;
    char * lexema;
    int linha;
    int coluna;
} Token;

typedef struct {
    char * src;
    int i;
    char c;
    int linha;
    int coluna;
} Scanner;

void AnaliseLexica(char Entrada[1024]);
char *nome_token(TipoToken t);
char * str_ndup (char * s, int n);
void iniciar(Scanner * sc, char * texto);
void avancar(Scanner * sc);
void pular_espacos(Scanner * sc);

Token criar_token_texto(Scanner *sc, TipoToken tipo, char *ini, size_t n, int lin, int col);
Token token_simples(Scanner *sc, TipoToken tipo);
Token token_erro_msg(Scanner *sc, char *msg);
Token coletar_inteiro(Scanner *sc);
Token proximo_token(Scanner *sc);

int main(void) {
    char Entrada[1024];
    scanf("%[^\n]", Entrada);

    AnaliseLexica(Entrada);
}

void AnaliseLexica(char Entrada[1024])
{
    Scanner S;
    iniciar(&S, Entrada);

    for (;;)
    {
        Token t = proximo_token(&S);
        printf("%d\t%d\t%s\t%s\n", t.linha, t.coluna, t.lexema, nome_token(t.tipo));
        free(t.lexema);
        if (t.tipo == TOKEN_FIM || t.tipo == TOKEN_ERRO)
            break;
    }
}

char * nome_token(TipoToken t) {
    switch (t) {
        case TOKEN_INTEIRO:   return "INTEIRO";
        case TOKEN_MAIS:      return "MAIS";
        case TOKEN_MENOS:     return "MENOS";
        case TOKEN_MULT:      return "MULT";
        case TOKEN_DIV:       return "DIV";
        case TOKEN_ABRE_PAR:  return "ABRE_PAR";
        case TOKEN_FECHA_PAR: return "FECHA_PAR";
        case TOKEN_FIM:       return "FIM";
        case TOKEN_ERRO:      return "ERRO";
        default:              return "?";
    }
}

char * str_ndup(char * s, int n) {
    char * p = (char *) malloc (n + 1);
    if(!p) {
        fprintf(stderr,"Memória insuficiente\n");
        exit(1);
    }
    
    memcpy(p, s, n);
    p[n] = '\0';
    return p;
}

void iniciar(Scanner *sc, char *texto){
    sc->src = texto ? texto : "";
    sc->i = 0;
    sc->linha = 1; sc->coluna = 1;
    sc->c = sc->src[0];
}

void avancar(Scanner *sc){
    if(sc->c=='\0') return;
    if(sc->c=='\n') { sc->linha++; sc->coluna=1; }
    else { sc->coluna++; }
    sc->i++;
    sc->c = sc->src[sc->i];
}

void pular_espacos(Scanner *sc) {
    while(isspace((unsigned char)sc->c)) avancar(sc);
}

Token token_erro_msg(Scanner *sc, char *msg){
    return criar_token_texto(
        sc,
        TOKEN_ERRO,
        msg,
        strlen(msg),
        sc->linha,
        sc->coluna
    );
}

Token token_simples(Scanner *sc, TipoToken tipo) {
    int lin = sc->linha, col = sc->coluna;
    char ch = sc->c;
    avancar(sc);
    return criar_token_texto(sc, tipo, &ch, 1, lin, col);
}

Token proximo_token(Scanner *sc){
    pular_espacos(sc);
    if(sc->c=='\0') return criar_token_texto(sc, TOKEN_FIM, "", 0, sc->linha, sc->coluna);
    if(isdigit((unsigned char)sc->c)) return coletar_inteiro(sc);
    switch(sc->c){
        case '+': return token_simples(sc, TOKEN_MAIS);
        case '-': return token_simples(sc, TOKEN_MENOS);
        case '*': return token_simples(sc, TOKEN_MULT);
        case '/': return token_simples(sc, TOKEN_DIV);
        case '(': return token_simples(sc, TOKEN_ABRE_PAR);
        case ')': return token_simples(sc, TOKEN_FECHA_PAR);
        default: {
            char msg[64];
            snprintf(msg, sizeof(msg), "Caractere inválido: '%c'", sc->c);
            avancar(sc);
            return token_erro_msg(sc, msg);
        }
    }
}

Token criar_token_texto(Scanner *sc, TipoToken tipo, char *ini, size_t n, int lin, int col){
(void)sc;
Token t; t.tipo=tipo; t.lexema=str_ndup(ini,n); t.linha=lin; t.coluna=col; return t;
}

Token coletar_inteiro(Scanner *sc){
int lin=sc->linha, col=sc->coluna;
size_t ini = sc->i;
if(!isdigit((unsigned char)sc->c)) return token_erro_msg(sc, "Inteiro malformado");
while(isdigit((unsigned char)sc->c)) avancar(sc);
return criar_token_texto(sc, TOKEN_INTEIRO, sc->src+ini, sc->i-ini, lin, col);
}