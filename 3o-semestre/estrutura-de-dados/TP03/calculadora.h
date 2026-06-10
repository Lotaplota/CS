#ifndef EXPRESSAO_H
#define EXPRESSAO_H

typedef struct {
    char posFixa[512]; // Expressão na forma pos-fixa, como 3 12 4 + *
    char inFixa[512]; // Expressão na forma infixa, como 3*(12+4)
    float Valor; // Valor numérico da expressão
} Expressao;

char * getInFixa(char *Str); // Retorna a forma inFixa de Str (posFixa)
float getValor (char *Str); // Calcula o valor de Str (na forma posFixa)

#endif