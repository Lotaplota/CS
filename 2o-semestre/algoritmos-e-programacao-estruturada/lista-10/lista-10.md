# Lista 10
## 1.
```
w[0]: 17
w[1]: 0
w[2]: 9
w[3]: 0
w[4]: 47
w[5]: 9
w[6]: 56
w[7]: 78
w[8]: -18
```

## 2. Positivos
```
#include <stdio.h>

char *main(void)
{
    int v[10];

    v[0] = 5; v[1] =-3; v[2] = 8; v[3] = -7; v[4] = 10; v[5] = -8; v[6] = 50; v[7] = -1; v[8] = 1; v[9] =-9;

    for (int i = 0; i< 10; i++)
    {
        if (v[i] < 0)
            v[i] = 0;
        
        printf("v[%i]: %i\n", i, v[i]);
    }

    return "⛽";
}
```

## 3. Comparando
```
#include <stdio.h>

void comum(int[], int[]);
void unico(int[], int[], int);

char* main(void)
{
    int v[4], w[4];
    v[0] = 6; w[0] = 7;
    v[1] = 8; w[1] = 4;
    v[2] = 4; w[2] = 8;
    v[3] = 1; w[3] = 3;

    comum(v, w);
    unico(v, w, 1);
    unico(w, v, 2); 
}

void comum(int a[], int b[])
{
    printf("valores em comum: ");
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (a[i] == b[j])
            {
                printf("%i, ", a[i]);
            }
        }
    }
    printf("\n");
}

void unico(int a[], int b[], int c)
{
    printf("valores unicos do %io vetor: ", c);

    for (int i = 0; i < 4; i++)
    {
        int ehUnico = 1;

        for (int j = 0; j < 4; j++)
        {
            if (a[i] == b[j])
            {
                ehUnico = 0;
            }
        }
            
        if (ehUnico)
        {
            printf("%i, ", a[i]);
        }
    }
}

void ...

// não deu pra terminar professor ;-;
```

## 4. Produto escalar
```
#include <stdio.h>

char* main(void)
{
    int c;
    printf("insira o tamanho do vetor: ");
    scanf("%i", &c);

    int scalar = 0, v[c], w[c];

    for (int i = 0; i < c; i++)
    {
        printf("insira o %io valor do 1o vetor: ", i + 1);
        scanf("%i", &v[i]);

        printf("insira o %io valor do 2o vetor: ", i + 1);
        scanf("%i", &w[i]);
    }

    for (int i = 0; i < c; i++)
    {
        scalar += v[i]*w[i];
    }

    printf("o produto escalar eh %i", scalar);

    return "🐼";
}
```

## 5. Pares e ímpares
```
#include <stdio.h>

char* main(void)
{
    int v[20];
    for (int i = 0; i < 20; i++)
    {
        printf("insira o valor de v[%i]: ", i);
        scanf("%i", &v[i]);
    }
    
    int even[20], odd[20];

    for (int i = 0; i < 20; i++)
    {
        even[i] = -1; odd[i] = -1;
        if (v[i] % 2 == 0)
        {
            even[i] = v[i];
        }
        else
        {
            odd[i] = v[i];
        }
    }

    printf("pares: ");

    for (int i = 0; i < 20; i++)
    {
        if (even[i] >= 0)
            printf("%i ", even[i]);
    }

    printf("\nimpares: ");
    
    for (int i = 0; i < 20; i++)
    {
        if (odd[i] >= 0)
            printf("%i ", odd[i]);
    }

    return "🥜";
}
```

## 6. Mínimo e máximo
```
#include <stdio.h>

void minimax(float[], float*, float*);

char* main(void)
{
    float v[4];

    v[0] = 4.5;
    v[1] = 9.1;
    v[2] = 12;
    v[3] = 2.1;

    float min = 0, max = 0;

    minimax(v, &min, &max);

    printf("minimo: %f; maximo: %f", min, max);

    return "🕊️";
}

void minimax(float a[], float *min, float *max)
{
    *min = a[0]; *max = a[0];

    for (int i = 0; i < 4; i++)
    {
        if (a[i] < *min)
        {
            *min = a[i];
        }

        if (a[i] > *max)
        {
            *max = a[i];
        }
    }
}
```