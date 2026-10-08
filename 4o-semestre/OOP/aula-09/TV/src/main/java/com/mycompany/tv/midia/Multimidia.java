package com.mycompany.tv.midia;

public abstract class Multimidia {
    protected String titulo;
    protected String sinopse;
    protected String genero;
    
    public Multimidia(String titulo, String genero) {
        this.titulo = titulo;
        this.genero = genero;
        this.sinopse = "lorem ipsum";
    }
    
    public Multimidia(String titulo, String sinopse, String genero) {
        this.titulo = titulo;
        this.sinopse = sinopse;
        this.genero = genero;
    }

    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public String getSinopse() {
        return sinopse;
    }

    public void setSinopse(String sinopse) {
        this.sinopse = sinopse;
    }

    public String getGenero() {
        return genero;
    }

    public void setGenero(String genero) {
        this.genero = genero;
    }

    @Override
    public String toString() {
        return "Título: " + this.titulo + 
                "\nGênero: " + this.genero + 
                "\nSinopse: " + this.sinopse;
    }
    
}
