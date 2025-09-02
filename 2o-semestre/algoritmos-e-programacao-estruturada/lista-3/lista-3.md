# Lista 3
## 1. Caminhão
```
#include <stdio.h>

char *main(void)
{
    // mantém o loop caso a entrada não seja válida
    int codigo = 0;
    float taxa = 0;

    while (!codigo)
    {
        printf("código do estado de origem: \n");
        scanf("%i", &codigo);

        switch (codigo)
        {
            case 1:
                taxa = .35;
                break;
            case 2:
                taxa = .25;
                break;
            case 3:
                taxa = .15;
                break;
            case 4:
                taxa = .05;
                break;
            case 5:
                taxa = 0;
                break;
            default:
                printf("Código inválido.\n");
                codigo = 0;
                break;
        }
    }

    float pesoToneladas;

    printf("insira o peso da carga em toneladas: ");
    scanf("%f", &pesoToneladas);

    int codigoCarga = 0;
    int precoQuilo;

    while (1)
    {
        int valido;

        printf("Insira o código da carga: ");
        valido = scanf("%i", &codigoCarga);

        if (valido)
        {
            if (codigoCarga >= 10 && codigoCarga <= 20)
            {
                precoQuilo = 100;
                break;
            }
            else if (codigoCarga >= 21 && codigoCarga <= 30)
            {
                precoQuilo = 250;
                break;
            }
            else if (codigoCarga >= 31 && codigoCarga <= 40)
            {
                precoQuilo = 340;
                break;
            }
            else
            {
                printf("Código inválido.\n");
            }
        }
    }

    int pesoQuilos = pesoToneladas * 1000;
    int valorCarga = pesoQuilos * precoQuilo;
    float imposto = valorCarga * taxa;
    float valorTotal = valorCarga + imposto;

    printf("O peso da carga é de %i kg.\n", pesoQuilos);
    printf("O valor da carga é de R$%i.\n", valorCarga);
    printf("O valor do imposto é de R$%.2f.\n", imposto);
    printf("O valor total é de R$%.2f", valorTotal);

    return "🚚";
}
```

## 2. Avaliação salarial
```
#include <stdio.h>

char *main(void)
{
    int input;
    float salario;

    printf("Menu de opções:\n1. Imposto\n2. Novo salário\n3. Classificação\nDigite aopção desejada: ");
    scanf("%i", &input);

    switch (input)
    {
        case 1:
            printf("Insira o salário para calcular a porcentagem de imposto\n");
            scanf("%f", &salario);

            float imposto;
            if (salario < 500)
                imposto = salario * .05;
            else if (salario < 850)
                imposto = salario * .1;
            else 
                imposto = salario * .15;
            
            printf("Você pagará um imposto de %.2f", imposto);

            break;
        case 2:
            printf("Insira o salário para calcular o seu aumento\n");
            scanf("%f", &salario);

            int aumento;
            if (salario < 450)
                aumento = 100;
            else if (salario <= 750)
                aumento = 75;
            else if (salario <= 1500)
                aumento = 50;
            else 
                aumento = 25;
            
            printf("Você receberá um aumento de R$%.2i. Seu novo salário é de R$%.2f.\n", aumento, salario + aumento);

            break;
        case 3:
            printf("Insira o salário para classificá-lo\n");
            scanf("%f", &salario);

            if (salario <= 700)
                printf("Mal remunerado.\n");
            else
                printf("Bem remunerado.");

            break;
    }

    return "🤓";
}
```

## 3. i
```
#include <stdio.h>

char *main(void)
{
    int i;
    float a, b, c;
    int valid = 0;

    while (!valid)
    {
        printf("insira os valores de i, A, B e C no formato #,#,#,#\n");
        valid = scanf("%i,%f,%f,%f", &i, &a, &b, &c);

        if (!valid || i < 0 || i > 4)
        {
            printf("Valores inválidos\n");
            valid = 0;
        }
    }

    float smallest, middlest, biggest;

    if (a > b)
    {
        if (a > c)
        {
            biggest = a;

            if (b > c)
            {
                middlest = b;
                smallest = c;
            }
            else
            {
                middlest = c;
                smallest = b;
            }
        }
        else
        {
            smallest = b;
            middlest = a;
            biggest = c;
        }
    }
    else if (a > c)
    {
        biggest = b;
        middlest = a;
        smallest = c;
    }
    else
    {
        smallest = a;

        if (b > c)
        {
            biggest = b;
            middlest = c;
        }
        else
        {
            biggest = c;
            middlest = b;
        }
    } // Véi... kkkk

    switch (i)
    {
    case 1:
        printf("%.0f < %.0f < %.0f", smallest, middlest, biggest);
        break;
    
    case 2:
        printf("%.0f > %.0f > %.0f", biggest, middlest, smallest);
        break;

    case 3:
        printf("%.0f < %.0f > %.0f", middlest, biggest, smallest);
        break;

    default:
        break;
    }

    return "🥴";
}
```