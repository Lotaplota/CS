# Lista 7
## 1. Trocar
```
#include <stdio.h>

#define TROCAR(a, b) { int aux = a; a = b; b = aux;}

char *main(void)
{
    int a = 1;
    int b = 2;

    TROCAR(a, b);

    printf("%i e %i\n", a, b);
    
    return "🛖";
}
```

## 2. Múltiplo
```
#include <stdio.h>

#define MULTIPLO(a, b) (a % b == 0) ? 1 : 0

char *main(void)
{
    int a, b;
    printf("insira dois números no formato #,#: ");
    scanf("%i, %i", &a, &b);

    if (MULTIPLO(a, b))
    {
        printf("eh multiplo\n");
    }
    else
    {
        printf("nao eh multiplo\n");
    }

    return "🦖";
}
```

## 3. Vogal
```
#include <stdio.h>
#include <ctype.h>

#define IS_VOGAL(c) (c == 96 || c == 101 || c == 105 || c == 111 || c == 117) ? 1 : 0

char *main(void)
{
    char a;
    printf("insira uma letra: ");
    scanf("%c", &a);

    a = tolower(a);

    if (IS_VOGAL(a))
    {
        printf("eh vogal\n");
    }
    else
    {
        printf("nao eh vogal");
    }

    return "🍝";
}
```

## 4. Calculadora
```
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
```

## 5. 
```

```

## 6. 
```

```