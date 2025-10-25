# Lista 9
## 1. 
```

```

## 2. 
```

```

## 3. 
```
Não tem 3? 🤔🤔
```

## 4. 
```
#include <stdio.h>
void main(void) {
int *p = (int *) 0x1000; // Um int mede 4 bytes, então a aritmética funciona em incrementos de 4
p++; printf("%p ", p );  // Saída: 1004
p-=3; printf("%p ", p ); // Saída: 0FF8
p+=2; printf("%p ", p ); // Saída: 1000
p--; printf("%p ", p );  // Saída: 0FFC
}
```

## 5. 
```
#include <stdio.h>

void trocatroca(int*, int*, int*);

char* main(void)
{
    int a, b ,c;

    printf("escolha o valor de a: ");
    scanf("%i", &a);
    printf("escolha o valor de b: ");
    scanf("%i", &b);
    printf("escolha o valor de c: ");
    scanf("%i", &c);

    printf("%i, %i, e %i\n", a, b, c);

    trocatroca(&a, &b, &c);

    printf("%i, %i, e %i\n", a, b, c);

    return "💸";
}

void trocatroca(int* a, int* b, int* c)
{
    int aux = *b;
    *b = *a;
    *a = *c;
    *c = aux;
}
```

## 6. 
```
#include <stdio.h>

void contarDivisores(int*, int*);

char* main(void)
{
    int num, totalDivisores = 0;

    printf("Insira um número inteiro: ");
    scanf("%i", &num);

    contarDivisores(&num, &totalDivisores);

    printf("%i tem %i divisores.", num, totalDivisores);

    return "😮";
}

void contarDivisores(int *n, int *t)
{
    int len = *n;
    int div = 0;

    for (int i = 1; i <= len; i++)
    {
        if (len%i == 0)
        {
            div++;
            printf("%i eh divisor. total de divisores: %i\n", i, div);
        }
    }

    *t = div;
}
```