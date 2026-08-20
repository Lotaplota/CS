package com.mycompany.listacontatos;
import com.mycompany.listacontatos.entidade.Contato;
import java.util.Scanner;

public class ListaTel {
    private static Scanner sc = new Scanner(System.in);
    
    public static void Listar(Contato[] lista)
    {
        for (int i = 0; i < lista.length; i++)
        {
            if (lista[i] == null) break;
            lista[i].ExibirContato();
        }
    }
    
    public static void adicionar(Contato[] lista)
    {
        String nome, telefone, tem_email, email = null;
        
        System.out.println("Digite o nome: ");
        nome = sc.nextLine();
        System.out.println("Digite o telefone: ");
        telefone = sc.nextLine();
        System.out.println("Tem e-mail? ");
        tem_email = sc.nextLine();
        if (tem_email == "sim")
        {
            System.out.println("Digite o email: ");
            email = sc.nextLine();
        }
        
        for (int i = 0; i < lista.length; i++)
        {
            if (lista[i] == null)
            {
                lista[i].SetNome(nome);
                lista[i].SetTelefone(telefone);
                if (!email.isBlank()) lista[i].SetEmail(email);
            }
        }
    }
    
    public static void main(String[] args) {
        
    }
}
