#include <stdio.h>
#include <windows.h>

void bomb(int time)
{
    if (time == 0)
    {
        printf("Boom.");
    }
    else
    {
        printf("\a%i\n", time);
        Sleep(1000);
        system("cls");
        bomb(time - 1);
    }
}

int main(void)
{
    bomb(4);
}