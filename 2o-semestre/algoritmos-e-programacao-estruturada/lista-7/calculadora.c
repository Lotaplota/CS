#include <stdio.h>

float soma(float, float);

float sub(float, float);

float mult(float, float);

float div(float, float);

char *main(void)
{
    float a, b;
    char o;

    printf("insira dois valores e uma operação no formato #*#: ");
    scanf("%f%c%f", &a, &o, &b);

    float res;

    switch (o)
    {
    case '+':
        res = soma(a, b);
        break;
    case '-':
        res = sub(a, b);
        break;
    case '*':
        res = mult(a, b);
        break;
    case '/':
        res = div(a, b);
        break;
    default:
        break;
    }

    printf("resultado: %f", res);

    return "🪂";
}

float soma(float a, float b)
{
    return a + b;
}

float sub(float a, float b)
{
    return a - b;
}

float mult(float a, float b)
{
    return a * b;
}

float div(float a, float b)
{
    return a / b;
}