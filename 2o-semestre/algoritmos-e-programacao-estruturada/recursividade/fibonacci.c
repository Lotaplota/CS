#include <stdio.h>

long fibo(int pos)
{
    if (pos <= 2)
    {
        return 1;
    }
    else
    {
        return fibo(pos - 1) + fibo(pos - 2);
    }
}

int main(void)
{
    printf("%ld\n", fibo(35));
}