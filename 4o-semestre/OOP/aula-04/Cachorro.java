package com.mycompany.animais;

public class Cachorro {
    private final String nome;
    private final String raca;
    private String cor;
    private static String especie;
    
    public Cachorro(String nome, String raca, String cor, String especie){
        this.nome = nome;
        this.raca = raca;
        this.cor = cor;
        Cachorro.especie = especie;
    }
    
    public String getNome(){
        return this.nome;
    }
    
    public String getRaca(){
        return this.raca;
    }
    
    public String getCor(){
        return this.cor;
    }
    
    public void setCor(String cor){
        this.cor = cor;
    }
    
    public void setEspecie(String especie){
        Cachorro.especie = especie;
    }
    
    @Override
    public String toString(){
        return "O " + especie +
                " da rassa " + this.raca +
                ", se chama " + this.nome +
                " e tem a cor " + this.cor + ".";
    }
}
