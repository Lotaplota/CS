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