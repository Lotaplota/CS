// Definindo o TAD Fração
typedef struct {
    int num;
    int den;
} Fracao;

Fracao criarFracao(int N, int D);
void exibirFracao(Fracao F);
int MDC(int a, int b);
Fracao simplificarFracao(Fracao F);