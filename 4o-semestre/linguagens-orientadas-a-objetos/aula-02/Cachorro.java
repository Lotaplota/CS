package com.mycompany.primeiraaula.animais;

public class Cachorro
{
    private String nome;
    private String raca;
    private String cor;
    private String sexo;
    
    public Cachorro(String nome, String raca, String cor, String sexo)
    {
        this.nome = nome;
        this.raca = raca;
        this.cor = cor;
        this.sexo = sexo;
    }
    
    public void latir()
    {
        System.out.println("Au!");
    }
    
    public void latirDuasVezes()
    {
        System.out.println("Au au!");
    }
    
    public void comer()
    {
        System.out.println("Om nom.");
    }
    
    public void morder()
    {
        System.out.println("Grr!");
    }
    
    public String getNome() { return this.nome; }
    public String getRaca() { return this.raca; }
    public String getCor() { return this.cor; }
}