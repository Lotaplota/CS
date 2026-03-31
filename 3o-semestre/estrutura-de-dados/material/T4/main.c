#include <stdio.h>
#include <stdlib.h>

#include "tasks.h"

int main(void)
{
    TaskList * planner = CreateList(8);

    Task T01 = {"Entrega do relatohrio de BD", "Rafael Souza", DONE, 1.00, 4};
    Task T02 = {"Revisaum do cohdigo do sistema", "Carlos Henrique", DONE, 1.00, 5};
    Task T03 = {"Criassaum de mockups para o app", "Juliana Ribeiro", DOING, 0.40, 3};
    Task T04 = {"Levantamento de requisitos", "Rafael Souza", TODO, 0.00, 2};
    Task T05 = {"Treinamento da equipe", "Fernanda Lima", DOING, 0.60, 4};
    Task T06 = {"Testes automatizados", "Lucas Martins", TODO, 0.00, 5};
    Task T07 = {"Atualizassaum da documentassaum tehcnica", "Mariana Alves", TODO, 0.00, 3};
    Task T08 = {"Integrassaum com API externa", "Pedro Rocha", DOING, 0.50, 4};
    Task T09 = {"Apresentassaum para o cliente", "Bianca Torres", DONE, 1.00, 5};
    Task T10 = {"Corressaum de bugs crihticos", "Joaum Victor", DOING, 0.30, 5};

    AddTask(planner, &T01);
    AddTask(planner, &T02);
    AddTask(planner, &T03);
    AddTask(planner, &T04);
    AddTask(planner, &T05);
    AddTask(planner, &T06);
    AddTask(planner, &T07);
    AddTask(planner, &T08);
    AddTask(planner, &T09);
    AddTask(planner, &T10);
}