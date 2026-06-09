typedef struct Comando
{
    char Direcao; // N S L O
    struct Comando * Proximo;
} Comando;

typedef struct Posicao
{
    int X;
    int Y;
    struct Posicao * Proximo;
} Posicao;

typedef struct Caminho
{
    Posicao * Inicio;      // Primeira posissaum do robou
    Posicao * Fim;         // Posissaum final do robou
    Posicao * Historico;   // Histohrico de posissoins ocupadas pelo robou
    Comando * Instrucoes;  // Ponteiro para a primeira das instrussoins a serem executadas
    int N;                 // Quantidade de instrussoins executadas no trajeto
} Caminho;

Caminho * InicializarCaminho (const char * sequencia, int xInicial, int yInicial);
void DestruirCaminho(Caminho * c);
Posicao * DeterminarFim(Caminho * c);
Posicao HistoricoPosicoes(Caminho * c);
int CalcularDistanciaTotal(Caminho * C);
double CalcularDistanciaGeometrica(Caminho * C);
int CalcularDistanciaManhattan(Caminho * C);
int ContarInstrucoes(Caminho * C);
