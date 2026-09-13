#include <stdio.h>
#include <ctype.h>

typedef enum {S, Q1, Q2, Q3, DEAD} State;

/* Função de transição δ */
static State step(State s, char x) {
    switch (s) {
        case S:
            if (x == 'a') return S; // S --a--> S
            if (x == 'b') return Q1; // S --b--> q1
            break; // qualquer outro símbolo → DEAD
        case Q1:
            if (x == 'a') return Q2; // q1 --a--> q2
            if (x == 'c') return Q3; // q1 --c--> q3 (ver observação acima)
            break;
        case Q3:
            if (x == 'b') return Q1; // q3 --b--> q1 (ver observação acima)
            break;
        case Q2:
            /* No diagrama q2 (final) não tem saídas. Qualquer símbolo após aceitar rejeita. */
            break;
        default: break;
    }
    return DEAD; // transição não definida → rejeita
}

int main(void) {
    char buf[1024];

    // Lê linhas da entrada padrão; cada linha é uma palavra.
    while (fgets(buf, sizeof buf, stdin)) {
        State s = S;
        int ok = 1;

        for (size_t i = 0; buf[i]; i++) {
            unsigned char ch = (unsigned char) buf[i];
            if (ch == '\n' || ch == '\r' || isspace(ch)) continue;
            if (ch != 'a' && ch != 'b' && ch != 'c') {ok = 0; break; }
            s = step(s, (char)ch);
            if (s == DEAD) {ok = 0; break; }
        }

        if (ok && s == Q2) puts("ACEITA");
        else puts("REJEITA");
    }
    return 0;
}