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