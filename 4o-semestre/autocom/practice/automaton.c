#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef enum { Q0,Q1, Q2, Q3, Q4, Q5, Q6, Q7, DEAD } State;

State transition (State s, char c)
{
    switch (s)
    {
        case Q0:
            if (c == '+' || c == '-') return Q1;
            if (c == '.') return Q2;
            if (isdigit(c)) return Q3;
            break;
        case Q1:
            if (c == '.') return Q2;
            if (isdigit(c)) return Q3;
            break;
        case Q2:
            if (isdigit(c)) return Q4;
            break;
        case Q3:
            if (isdigit(c)) return Q3;
            if (c == 'E' || c == 'e') return Q5;
            if (c == '.') return Q4;
            break;
        case Q4:
            if (isdigit(c)) return Q4;
            if (c == 'E' || c == 'e') return Q5;
            break;
        case Q5:
            if ( c == '+' || c == '-') return Q6;
            if (isdigit(c)) return Q7;
            break;
        case Q6:
            if (isdigit(c)) return Q7;
            break;
        case Q7:
            if (isdigit(c)) return Q7;
            break;
        default: break;
    }
    return DEAD;
}

int main(void)
{
    char buffer[256];
    char resultado[8];
    
    while (fgets(buffer, sizeof(buffer), stdin))
    {
        State state = Q0;

        for (int i = 0; i < strlen(buffer) - 1; i++)
        {
            printf("Q%i + %c -> Q", state, buffer[i]); // DONKEY
            state = transition(state, buffer[i]);
            printf("%i\n", state, buffer[i]); // DONKEY
            
            if (state == DEAD)
            {
                strcpy(resultado, "REJEITA");
                break;
            }
            char * final = (state == Q3 || state == Q4 || state == Q7) ? "ACEITA" : "REJEITA";
            strcpy(resultado, final);
        }
        printf("%s\n", resultado);
    }
    
}