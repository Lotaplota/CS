#ifndef FRACAO_H
#define FRACAO_H

// Definindo o TAD Fração
typedef struct {
    int num;
    int den;
} Fracao;

Fracao criarFracao(int N, int D);
void exibirFracao(Fracao F);
int MDC(int a, int b);
Fracao simplificarFracao(Fracao F);
Fracao somarFracao(Fracao f, Fracao g);
Fracao subtrairFracao(Fracao f, Fracao g);
Fracao multiplicarFracao(Fracao f, Fracao g);
Fracao dividirFracao(Fracao f, Fracao g);

#endif