#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lexico.h"

// Transforma TokenTipo em string, dependendo da enum
char * nome_token(TipoToken t) {
    switch(t) {
        case TOKEN_INTEIRO:    return "INTEIRO";
        case TOKEN_MAIS:       return "MAIS";
        case TOKEN_MENOS:      return "MENOS";
        case TOKEN_MULT:       return "MULTIPLICACAO";
        case TOKEN_DIV:        return "DIVISAO";
        case TOKEN_POT:        return "POTENCIA";
        case TOKEN_ABRE_PAR:   return "ABRE_PAR";
        case TOKEN_FECHA_PAR:  return "FECHA_PAR";
        case TOKEN_ERRO:       return "ERRO";
        case TOKEN_FIM:        return "FIM";
        default:               return "?";
    }
}

// Retorna ponteiro para uma string
// Normalmente, `fonte` será `sc->src + cursorInicial` e `qtBytes` será `sc->i - cursorInicial`
char * str_ndup (char * fonte, int qtBytes) {
    printf("\033[0;33m    str_ndup(%s, %i)\033[0m\n", fonte, qtBytes); // DONKEY
    // Aloca espaço para a string a ser devolvida
    char * p = (char *) malloc(qtBytes+1);
    if(!p){
        fprintf(stderr,"Memória insuficiente\n"); 
        exit(1);
    }

    // Copia a quantidade de bytes de s para p e fecha a string com um '\0'
    memcpy(p, fonte, qtBytes);
    p[qtBytes] = '\0';
    return p;
}

// Inicia as variáveis de um Scanner, que funciona como um cursor de fopen()
void iniciar(Scanner * sc, char * texto) {
    printf("\033[0;33mIniciando scanner (Scanner scanner) com o paranmetro \"%s\".\033[0m\n", texto); // DONKEY
    sc->src = texto ? texto : ""; 
    sc->i = 0;
    sc->linha = 1; 
    sc->coluna = 1;
    sc->c = sc->src[0];
}

// Avança o cursor do scanner em uma linha ou uma coluna, dependendo do caractere atual
void avancar (Scanner * sc) {
    // Se for o fim da string geradora, retorna
    if(sc->c == '\0') {
        printf("\033[0;36mFim da string geradora encontrado\033[0m\n"); // DONKEY
        return;
    }

    // Se o caractere é um '\n', incrementa a linha e reseta a coluna para 1
    if(sc->c == '\n'){
        printf("\033[0;33m\'\\n\' encontrado\033[0m\n"); // DONKEY
        sc->linha++; 
        sc->coluna = 1;
    }
    // Se for qualquer outra coisa, incrementa a coluna
    else {
        sc->coluna++;
    }

    // Incrementa o número de caracteres lidos e muda o caractere atual para o novo
    sc->i++;
    sc->c = sc->src[sc->i];
}

// Verifica se o caractere atual do scanner é um espaço, se for apenas chama `avancar(sc)`
void pular_espacos(Scanner * sc) {
    printf("\033[0;33m  pular_espacos(Scanner *)\033[0m\n"); // DONKEY function-call
    while (isspace((unsigned char)sc->c)) avancar(sc);
}

Token token_erro_msg (Scanner * sc, char * msg) {
    return popular_token(
        TOKEN_ERRO, 
        msg, 
        strlen(msg), 
        sc->linha, 
        sc->coluna
    );
}
// Retorna um token de lexema tamanho 1
Token token_simples(Scanner * sc, TipoToken tipo){
    printf("\033[0;33m  token_simples(Scanner, TipoToken(%i))\033[0m\n", tipo); // DONKEY function-call
    int lin = sc->linha;
    int col = sc->coluna;
    char ch = sc->c;
    avancar(sc);
    return popular_token(tipo, &ch, 1, lin, col);
}

// Busca o próximo token começando pelo caractere alvejado cursor do scanner
// Pode retornar um token de inteiro, um token simples, ou um token de erro, após verificação do caractere ou da string no cursor
Token proximo_token(Scanner * sc) {
    printf("\033[0;33mproximo_token(Scanner *)\033[0m\n"); // DONKEY function-call
    pular_espacos(sc);

    // Se o caractere atual é um '\0', chama `popular_token()`
    if (sc->c == '\0') return popular_token(TOKEN_FIM, "", 0, sc->linha, sc->coluna);
    // Se o caractere atual é um dígito, chama `coletar_inteiro()`
    printf("\033[0;35mChecking %c\033[0m\n", sc->c); // DONKEY
    if (isdigit((unsigned char)sc->c)) return coletar_inteiro(sc);
    
    switch (sc->c) {
        case '+' : return token_simples(sc, TOKEN_MAIS);
        case '-' : return token_simples(sc, TOKEN_MENOS);
        case '*' : return token_simples(sc, TOKEN_MULT);
        case '/' : return token_simples(sc, TOKEN_DIV);
        case '^' : return token_simples(sc, TOKEN_POT);
        case '(' : return token_simples(sc, TOKEN_ABRE_PAR);
        case ')' : return token_simples(sc, TOKEN_FECHA_PAR);
        default: {
            char msg[64];
            snprintf(msg, sizeof(msg), "Caractere invalido: '%c'", sc->c);
            Token erro = token_erro_msg(sc, msg);
            avancar(sc);
            return erro;
        }
    }
}

// Retorna o token com suas variáveis populadas
Token popular_token(TipoToken tipo, char *offsetString, int qtCaracteres, int lin, int col){
    printf("\033[0;33m  popular_token(TipoToken(%i), %s, %i, %i, %i)\033[0m\n", tipo, offsetString, qtCaracteres, lin, col); // DONKEY
    Token t;
    
    t.tipo=tipo; 
    t.lexema=str_ndup(offsetString,qtCaracteres);
    t.linha=lin; 
    t.coluna=col; 
    return t;
}

// Retorna um token de inteiro, registrando todos os caracteres que são considerados dígitos
// Caminha com o cursor do scanner até parar de identificar dígitos
// Assim que isso acontece, retorna um token de inteiro (bem formado) ou um token de erro
Token coletar_inteiro(Scanner *sc){
    printf("\033[0;33mcoletar_inteiro(Scanner)\033[0m\n"); // DONKEY function-call
    // Guarda a linha, coluna, e posição atuais do scanner no momento de chamada
    int lin=sc->linha, col=sc->coluna;
    size_t cursorInicial = sc->i;

    // Se o caractere não for um dígito, retorna uma mensagem de erro
    // OBS: Não sei nem por que checar isso, porque a função que me trouxe aqui já fazia a mesma checagem como condição de chamada
    if(!isdigit((unsigned char)sc->c)) return token_erro_msg(sc, "Inteiro malformado");

    // Avança o cursor enquanto o caractere atual for um dígito
    while(isdigit((unsigned char)sc->c)) avancar(sc);
    return popular_token(TOKEN_INTEIRO, sc->src+cursorInicial, sc->i-cursorInicial, lin, col);
}
