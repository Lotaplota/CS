# Lista 8
## 1. Contagem
```
#include <stdio.h>

int cont(int n)
{
    if (n % 10 == n)
        return 1;
    else
        return 1 + cont(n / 10);
}

char *main(void)
{
    int a;

    printf("insira um numero natural: ");
    scanf("%i", &a);

    printf("%i tem %i digitos.\n", a, cont(a));

    return "🍇";
}
```

## 2. Soma
```
#include <stdio.h>

int soma(int n)
{
    if (n % 10 == n)
    {
        return n;
    }
    else
    {
        return n % 10 + soma(n / 10);
    }
}

char *main(void)
{
    int a;

    printf("insira um numero natural: ");
    scanf("%i", &a);

    printf("a soma dos algarismos de %i eh %i.\n", a, soma(a));

    return "🦮";
}
```

## 3. Paridade
```
#include <stdio.h>

int ehImpar(int n)
{
    if (n < 2)
        return n;
    else
        return ehImpar(n - 2);
}

char *main(void)
{
    int n;

    printf("insira um numero natural: ");
    scanf("%i", &n);

    if (ehImpar(n))
        printf("%i eh impar\n", n);
    else
        printf("%i eh par.\n", n);

    return "🐀";
}
```

## 4. Binário
```
#include <stdio.h>

void bin(int n)
{
    if (n < 2)
        printf("%i", n);
    else
    {
        bin(n / 2);
        printf("%i", n % 2);
    }
}

char *main(void)
{
    int n;

    printf("insira um numero natural: ");
    scanf("%i", &n);

    printf("%i em binario eh ", n);
    bin(n);

    return "🦜";
}
```

## 5. MDC
```
#include <stdio.h>

int MDC(int a, int b)
{
    if (b == 0)
        return a;
    else
        return MDC(b, a % b);
}

char *main(void)
{
    int a, b;

    printf("insira dois numeros inteiros: ");
    scanf("%i,%i", &a, &b);

    printf("o MDC de %i e %i eh %i", a, b, MDC(a,b));

    return "👨‍🎓";
}
```