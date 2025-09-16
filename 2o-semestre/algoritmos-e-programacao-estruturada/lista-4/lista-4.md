# Lista 4
## 1. Contagem
```
#include <stdio.h>

char *main(void)
{
    printf("hello\n");
    for (int i = 100; i > 0; i--)
    {
        printf("%i ", i);
    }

    return "😩";
}
```

## 2. Soma
```
// Faça um programa que calcule a soma dos N números digitados pelo usuário e apresente esse resultado.

#include <stdio.h>

char *main(void)
{
    int n, soma = 0;

    printf("insira a quantidade de números a serem somados: ");
    scanf("%i", &n);

    for (int i = 0; i < n; i++)
    {
        int valor;

        printf("insira o %io valor: ", i + 1);
        scanf("%i", &valor);

        soma += valor;
    }

    printf("%i", soma);

    return "🎶";
}
```

## 3. Pesos
```
char *main(void)
{
    int n;

    printf("insira a quantidade de notas: ");
    scanf("%i", &n);

    float somatorio = 0;
    int somaPesos = 0;

    for (int i = 0; i < n; i++)
    {
        float nota;
        int peso;

        printf("insira a %ia nota e seu peso no formato #,#: ", i + 1);
        scanf("%f,%i", &nota, &peso);

        somatorio += nota * peso;
        somaPesos += peso;
    }

    printf("nota final: %.2f\n", somatorio / somaPesos);

    return "🦮";
}
```

## 4. Digitos
```
#include <stdio.h>

char *main(void)
{
    int n;

    printf("insira um numero: ");
    scanf("%i", &n);

    if (n < 0)
    {
        n *= -1;
    }
    
    int qDigitos = 0;

    for (int i = n; i > 1; i /= 10)
    {
        qDigitos++;
    }
    
    printf("seu numero tem %i algarismos\n", qDigitos);

    return "🤪";
}
```