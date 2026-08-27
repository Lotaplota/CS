package com.mycompany.universidade.entidades;

public class Aluno {
    private final String nome;
    private final int matricula;
    private String curso;
    
    public Aluno(String nome, int matricula, String curso) {
        this.nome = nome;
        this.matricula = matricula;
        this.curso = curso;
    }
    
    public String getNome() { return this.nome; }
    
    public int getMatricula() { return this.matricula; }
    
    public String getCurso() { return this.curso; }
    
    public void setCurso(String curso) { this.curso = curso; }
    
    @Override
    public String toString(){
        return "Aluno: " + this.nome +
               "\nMatricula: " + this.matricula +
               "\nCurso: " + this.curso + ".";
    }
}

