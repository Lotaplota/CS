# Lista 1
## 1. Notas e Pesos
```
// Faça um programa que receba três notas e seus respectivos pesos, calcule e mostre a média ponderada dessas notas.
#include <stdio.h>

int main(void)
{
    float notas[3] = {};
    printf("Insira tres notas no formato #,#,#\n");
    scanf("%f,%f,%f", &notas[0], &notas[1], &notas[2]);

    int pesos[3] = {};
    printf("Insira os pesos de cada nota no formato #,#,#\n");
    scanf("%i,%i,%i", &pesos[0], &pesos[1], &pesos[2]);

    int somaPesos = pesos[0] + pesos[1] + pesos[2];

    float media = 0;
    for (int i = 0; i < 3; i++)
    {
        media += notas[i] * pesos[i];
    }

    media /= somaPesos;
    printf("Sua media final e: %f\n", media);
}
```

## 2. Distância Cartesiana
```
// Faça um programa que calcule a distância entre dois pontos no plano cartesiano.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} Ponto;

int main(void)
{
    Ponto a, b;

    printf("insira as coordenadas do primeiro ponto no formato #,#\n");
    scanf("%f,%f", &a.x, &a.y);
    printf("agora as do segundo ponto no formato #,#\n");
    scanf("%f,%f", &b.x, &b.y);
    printf("ax: %f, ay: %f, bx: %f, by: %f\n", a.x, a.y, b.x, b.y); // DONKEY

    float d = sqrt(pow(abs(a.x - b.x), 2) + pow(abs(a.y - b.y), 2));

    printf("A distancia destes pontos e %f", d);
}
```

## 3. Juros
```
// Faça um programa que receba o valor de um depósito (c) e o valor da taxa de juros em porcentagem (i), calcule e mostre o valor do rendimento em juros simples (j) e o valor total depois do rendimento
#include <stdio.h>

int main(void)
{
    float c, i; // Não precisa especificar o tempo?

    printf("insira o valor do deposito e o valor da taxa de juros no formato #,#%%\n");
    scanf("%f,%f%%", &c, &i);

    i /= 100;

    printf("o valor retornado sera de R$%.2f, com um rendimento de R$%.2f\n", c * (1 + i), c * i);
}
```

## 4. Matemática
```
// Faça um programa que receba um número positivo e maior que zero, calcule, e mostre:
//   a) O número digitado ao quadrado.
//   b) O número digitado ao cubo.
//   c) A raiz quadrada do número digitado.
//   d) A raiz cúbica do número digitado
#include <stdio.h>
#include <math.h>

int main(void)
{
    unsigned int n;
    printf("insira um numero positivo e maior que zero\n");
    scanf("%u", &n);

    printf("quadrado: %.0f\n", pow(n, 2));
    printf("cubo: %.0f\n", pow(n, 3));
    printf("raiz quadrada: %f\n", sqrt(n));
    printf("raiz cubica: %f\n", cbrt(n));
}
```

## 5. Dígitos
```
// Escreva um aplicativo que insere um número consistindo em cinco dígitos do usuário, separa o número em seus dígitos individuais e imprime os dígitos separados uns dos outros por três espaços cada. Por exemplo, se o usuário digitar o número 42339, o programa deve imprimir:
#include <stdio.h>
#include <math.h>

int main(void)
{
    unsigned int n;
    printf("insira um numero inteiro positivo\n");
    scanf("%u", &n);

    int nlen = 1;

    while (pow(10, nlen) <= n)
    {
        nlen++;
    }

    unsigned int cur;
    unsigned int rem = n;

    for (int i = 0; i < nlen; i++)
    {
        cur = rem / pow(10, nlen - 1 - i);
        rem %= (unsigned int)pow(10, nlen - 1 - i); // idk why I need to cast here but not in the line above
        printf("%i   ", cur);
    }
}
```