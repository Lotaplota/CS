package com.mycompany.tv.midia;

public class Filme extends Multimidia {

    private int duracao;

    public Filme(String titulo, String sinopse, String genero,
            int duracao) {
        super(titulo, sinopse, genero);
        this.duracao = duracao;
    }

    public int getDuracao() {
        return duracao;
    }

    public void setDuracao(int duracao) {
        this.duracao = duracao;
    }

    @Override
    public String toString() {
        return super.toString()
                + "\nDuração: " + this.duracao + " minutos.";
    }

}
