package com.mycompany.primeiraaula.animais;

public class Gato
{
    private String nome;
    private String raca;
    private String cor;
    private String sexo;
    
    public Gato(String nome, String raca, String cor, String sexo)
    {
        this.nome = nome;
        this.raca = raca;
        this.cor = cor;
        this.sexo = sexo;
    }
    
    public void miar()
    {
        System.out.println("Miau.");
    }
    
    public void miarLongo()
    {
        System.out.println("Miaaau.");
    }
    
    public void comer()
    {
        System.out.println("Om nom.");
    }
    
    public void dormir()
    {
        System.out.println("rrrr");
    }
    
    public void arranhar()
    {
        System.out.println("Hisss!");
    }
    
    public String getNome() { return this.nome; }
    public String getRaca() { return this.raca; }
    public String getCor() { return this.cor; }
}
