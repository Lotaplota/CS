package com.mycompany.listacontatos.entidade;

public class Contato {
    private String nome;
    private String telefone;
    private String email;

    public Contato(String nome, String telefone, String email)
    {
        this.nome = nome;
        this.telefone = telefone;
        this.email = email;
    }
    
    public String GetNome() { return this.nome; }
    public String GetTelefone() { return this.telefone; }
    public String GetEmail() { return this.email; }
    
    public void SetNome(String nome)
    {
        if (!nome.isBlank()) { this.nome = nome; }
    }
    
    public void SetTelefone(String telefone)
    {
        if (!telefone.isBlank()) { this.telefone = telefone; }
    }
    
    public void SetEmail(String email)
    {
        if (!email.isBlank()) { this.email = email; }
    }
    
    public void ExibirContato()
    {
        String emailLine = this.email.isBlank() ? "\nEmail: " + this.email : "";

        System.out.println("Nome: " + this.nome +
               "\nTelefone: " + this.telefone +
               emailLine);
    }
    
    @Override
    public String toString()
    {
        String emailLine = this.email.isBlank() ? "\nEmail: " + this.email : "";
        
        return "Nome: " + this.nome +
               "\nTelefone: " + this.telefone +
               emailLine;
    }
}
