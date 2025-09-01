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