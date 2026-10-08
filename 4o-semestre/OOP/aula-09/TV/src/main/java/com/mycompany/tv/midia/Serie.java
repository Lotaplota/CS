package com.mycompany.tv.midia;

public class Serie extends Multimidia {
    private int qtTemporadas;
    private int qtEpisodios;

    public Serie(String titulo, String sinopse, String genero,
            int temporadas, int capitulos) {
        super(titulo, sinopse, genero);
        this.qtTemporadas = temporadas;
        this.qtEpisodios = capitulos;
    }

    public int getQtTemporadas() {
        return qtTemporadas;
    }

    public void setQtTemporadas(int temporadas) {
        this.qtTemporadas = temporadas;
    }

    public int getQtEpisodios() {
        return qtEpisodios;
    }

    public void setQtEpisodios(int qtEpisodios) {
        this.qtEpisodios = qtEpisodios;
    }

    @Override
    public String toString() {
        return super.toString() + 
                "\nTemporadas: " + qtTemporadas +
                "\nEpisódios: " + qtEpisodios;
    }
}
