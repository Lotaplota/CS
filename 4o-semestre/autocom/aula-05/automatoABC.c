#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {S, Q1, Q2, Q3, DEAD} State;

State transissaum(State s, char x)
{
    switch(s) {
        case S:
            if (x == 'a') return S;
            if (x == 'b') return Q1;
        case Q1:
            if (x == 'a') return Q2;
            if (x == 'c') return Q3;
        case Q2:
            break;
        case Q3:
            if (x == 'b') return S;
            break;
        default:
            break;
    }

    return DEAD;
}

int main()
{
    char buf[4096];

    while(fgets(buf, sizeof buf, stdin))
    {
        State s = S;
        int ok = 1;

        for(int i = 0; buf[i] != '\0'; i++)
        {
            char ch = buf[i];

            if (ch == '\n' || ch == '\r' || ch == ' ' /*|| isspace(ch)*/) continue;
            if (ch != 'a' && ch != 'b' && ch != 'c') { ok = 0; break; }

            s = transissaum(s, ch);
            if (s == DEAD) { ok = 0; break; }
        }

        if( ok && s == Q2) puts ("ACEITA");
        else puts("REJEITA");
    }

    return 0;
}