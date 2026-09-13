#include <stdio.h>
#include <ctype.h>

typedef enum { Q0,Q1, Q2, Q3, Q4, Q5, Q6, Q7, DEAD } State;

State transition (State s, char c) {
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
    case Q4: // DONKEY CONTINUE
        if ( ) return Q;
        break;
    case Q5:
        if ( ) return Q;
        break;
    case Q6:
        if ( ) return Q;
        break;
    case Q7:
        if ( ) return Q;
        break;
    default:
        break;
    }
}