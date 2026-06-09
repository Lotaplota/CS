#ifndef CAMINHO_H 
#define CAMINHO_H 

typedef struct Comando { 
char Direcao; // Que pode ser ‘N’, ‘S’, ‘L’ ou ‘O’ 
struct Comando * Proximo; 
} Comando; 

typedef struct Posicao { 
int X; // Para armazenar a abscissa de um ponto 
int Y; // Para armazenar a ordenada de um ponto 
struct Posicao * Proximo; 
} Posicao;

typedef struct Caminho { 
    Posicao * Inicio; // Ponteiro para a primeira posição ocupada pelo robô
    Posicao * Fim; // Ponteiro para a última posição ocupada pelo robô 
    Posicao * Historico; // Ponteiro para o histórico de posições ocupadas pelo robô 
    Comando * Instrucoes; // Ponteiro para a 1ª das instruções a serem executadas 
    int N; // Quantidade de instruções executadas no trajeto 
} Caminho;
 
Caminho * InicializarCaminho(const char *Sequencia, int xInicial, int yInicial); // DONE
void DestruirCaminho(Caminho * C); // DONE
Posicao * DeterminarFim(Caminho * C); // DONE
Posicao * HistoricoPosicoes(Caminho * C); // DONE
int CalcularDistanciaTotal(Caminho * C); // DONE
double CalcularDistanciaGeometrica(Caminho * C); // DONE
int CalcularDistanciaManhattan(Caminho * C); // DONE
int ContarInstrucoes(Caminho * C);  // DONE
 
#endif