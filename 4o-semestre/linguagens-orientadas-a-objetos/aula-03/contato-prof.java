package com.mycompany.listatel.entidade;

public class Contato {
    private String nome;
    private String telefone;
    private String email;
    
    public Contato(String nome, String telefone) {
        this.nome = nome;
        this.telefone = telefone;
    }
    
    public String getNome() {
        return this.nome;
    }
    
    public String getTelefone() {
        return this.telefone;
    }
    
    public String getEmail() {
        return this.email;
    }
    
    public void setNome(String nome) {
        if(!nome.isBlank()) {
            this.nome = nome;
        }
    }
    
    public void setTelefone(String telefone) {
        this.telefone = telefone;
    }
    
    public void setEmail(String email) {
        this.email = email;
    }
    
    public void exibirContato() {
        System.out.println(this);
    }

    @Override
    public String toString() {
        if (email == null){
            return "Nome: " + nome +
                    "\nTelefone: " + telefone;
        }
        return "Nome: " + nome +
                "\nTelefone: " + telefone +
                "\nE-mail: " + email;
    }
    
}
