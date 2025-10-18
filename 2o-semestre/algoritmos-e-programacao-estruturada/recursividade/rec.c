#include <stdio.h>

int soma(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        soma(a + 1, b - 1);
    }
}

// DONKEY do subtraction

int mult(int a, int b)
{
    if (b == 0)
    {
        return 0;
    }
    else
    {
        return a + mult(a, b - 1);
    }
}

int div(int a, int b)
{
    if (b > a)
    {
        return 0;
    }
    else
    {
        return 1 + div(a - b, b);
    }
}

int rem(int a, int b)
{
    if (b > a)
    {
        return a;
    }
    else
    {
        return rem(a - b, b);
    }
}

int power(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    else
    {
        return a * power(a, b - 1);
    }
}

int main(void)
{
    int a = 7, b = 3;
    printf("%i and %i\nsum: %i\nsub: %i\nmult: %i\ndiv: %i\nremainder: %i\npower: %i\n", a, b, soma(a, b), 69, mult(a, b), div(a, b), rem(a, b), power(a, b));
}