// Implemente uma função chamada calcular_idade() que calcule a idade de uma pessoa em anos, meses e dias, dado a data de nascimento e a data atual.
#include <stdio.h>

void calcular_idade(int, int, int, int, int, int);

char *main(void)
{
    int db, mb, yb;

    printf("insira sua data de nascimento no formato ##/##/####: ");
    scanf("%i/%i/%i", &db, &mb, &yb);

    int d, m, y;

    printf("insira a data de hoje no formato ##/##/####: ");
    scanf("%i/%i/%i", &d, &m, &y);

    calcular_idade(db, mb, yb, d, m, y);
}

void calcular_idade(int db, int mb, int yb, int d, int m, int y)
{
    int ad, am, ay;

    printf("%i,%i,%i,%i,%i,%i,\n", db, mb, yb, d, m, y); // DONKEY
    ay = y - yb;
    printf("%i\n", ay); // DONKEY CONTINUE

    if (m < mb) { ay--; }
    else if(m == mb)
    {
        if (d < db)
        {
            ay--;
        }
        else if (d == db)
        {
            printf("Hoje eh seu aniversario!! Você fez %i anos.", ay);
            return;
        }
    }

    printf("Voce tem %i anos.", ay);
}