#include <stdio.h>

#include "lista.h"

int main(void)
{
    Tarefa T1 = {"Entrega do relatório de BD", "Rafael Souza Rossi", FEITO, 1.00, 4};
    Tarefa T2 = {"Revisão do código do sistema", "Carlos Henrique Moura", FEITO, 1.00, 5};
    Tarefa T3 = {"Criação de mockups para o app", "Juliana Ribeiro Silva", EM_ANDAMENTO, 0.40, 3};
    Tarefa T4 = {"Levantamento de requisitos", "Rafael Souza Rossi", A_FAZER, 0.00, 2};
    Tarefa T5 = {"Treinamento da equipe", "Fernanda Lima do Carmo", EM_ANDAMENTO, 0.60, 4};
    Tarefa T6 = {"Testes automatizados", "Lucas Martins Siqueira", A_FAZER, 0.00, 5};
    Tarefa T7 = {"Atualização da documentação técnica", "Mariana Alves Souza", A_FAZER, 0.00, 3};
    Tarefa T8 = {"Integração com API externa", "Pedro Rocha Solto", EM_ANDAMENTO, 0.50, 4};
    Tarefa T9 = {"Apresentação para o cliente", "Bianca Torres Amaral", FEITO, 1.00, 5};
    Tarefa T10 = {"Correção de bugs críticos", "João Victor de Araujo", EM_ANDAMENTO, 0.30, 5};

    Lista * planner = CriarLista(30);

    AdicionarTarefa(planner, T1);
    AdicionarTarefa(planner, T2);
    AdicionarTarefa(planner, T3);
    AdicionarTarefa(planner, T4);
    AdicionarTarefa(planner, T5);
    AdicionarTarefa(planner, T6);
    AdicionarTarefa(planner, T7);
    AdicionarTarefa(planner, T8);
    AdicionarTarefa(planner, T9);
    AdicionarTarefa(planner, T10);

    for (int i = 0; i < 10; i++)
    {
        printf("%i. %s\n", i, planner->dados[i].titulo);
    }
}