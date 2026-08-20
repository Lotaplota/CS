package com.mycompany.listatel;

import com.mycompany.listatel.entidade.Contato;
import java.util.Scanner;

public class ListaTel {
    private static Scanner sc = new Scanner(System.in);
    
    public static void listar(Contato[] lista) {
        for(int i = 0; i < lista.length; i++) {
            if (lista[i] == null) return;
            lista[i].exibirContato();
        }
        System.out.println("Implemente o que acontece se não houver mais vagas");
    }
    
    public static void adicionar(Contato[] lista) {
        sc.nextLine();
        String nome, telefone, email = null, tem_email;
        System.out.println("Digite o nome: ");
        nome = sc.nextLine();
        System.out.println("Digite o telefone: ");
        telefone = sc.nextLine();
        System.out.println("Tem e-mail? (Sim ou não) ");
        tem_email = sc.nextLine();
        if("sim".equals(tem_email)) {
            System.out.println("Digite o e-mail: ");
            email = sc.nextLine();
        }
        for(int i = 0; i < lista.length; i++) {
            if (lista[i] == null) {
                lista[i] = new Contato(nome, telefone);
                if ("sim".equals(tem_email)){
                    lista[i].setEmail(email);
                }
                break;
            }
        }
    }

    public static void main(String[] args) {
        Contato[] lista = new Contato[20];
        int opcao;
        
        while(true) {
            System.out.println("===== AGENDA DE CONTATOS ======\n\n" +
                            "1 - Adicionar contato\n" +
                            "2 - Listar contatos\n" +
                            "3 - Buscar contato\n" +
                            "4 - Remover contato\n" +
                            "0 - Sair\n\n" +
                            "Escolha a opção: ");
            opcao = sc.nextInt();
            if (opcao == 0) break;
            switch (opcao) {
                case 1: adicionar(lista); break;
                case 2: listar(lista); break;
                case 3: System.out.println("Implementar..."); break;
                case 4: System.out.println("Implementar..."); break;
                default: System.out.println("Opção inválida!");;
            }
        }
    }
}
