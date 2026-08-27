package com.mycompany.universidade.entidades;

public class DisciplinaCursada {
    Aluno aluno;
    private final String titulo;
    private float n1;
    private float n2;
    private float n3;
    private float freq = 1;
    private float ppd;
    
    public DisciplinaCursada(Aluno aluno) {
        this.titulo = aluno.getCurso();
        this.aluno = aluno;
    }
    
    public String getTitulo() { return this.titulo; }
    
    public float getN1() { return this.n1; }
    public float getN2() { return this.n2; }
    public float getN3() { return this.n3; }
    public float getFreq() { return this.freq; }
    public float getPPD() { return this.ppd; }
    
    public void setN1(float n) { this.n1 = n; }
    public void setN2(float n) { this.n2 = n; }
    public void setN3(float n) { this.n3 = n; }
    public void setFreq(float f) { this.freq = f; }
    public void setPPD(float n) { this.ppd = n; }
    
    public float mediaFinal(){
        return (n1 + n2 + n3) / 3;
    }
    
    public void verificarSituacao() {
        System.out.println("O aluno " + aluno.getNome() +
                " possui frequencia " + (this.freq * 100) +
                "%, tem a mehdia de " + this.mediaFinal() +
                " e nota " + this.ppd +
                " no ppd");
    }
    
    @Override
    public String toString(){
        return "Disciplina de " + this.titulo + " cursada por " + this.aluno.getNome() + ".";
    }
}
