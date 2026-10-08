package com.mycompany.tv.midia;

import java.time.LocalTime;

public class ProgramaTV extends Multimidia {
    private int duracao;
    private int canal;
    private LocalTime horario;

    public ProgramaTV(String titulo, String sinopse, String genero, int duracao, int canal, LocalTime horario) {
        super(titulo, sinopse, genero);
        this.duracao = duracao;
        this.canal = canal;
        this.horario = horario;
    }

    public int getDuracao() {
        return duracao;
    }

    public void setDuracao(int duracao) {
        this.duracao = duracao;
    }

    public int getCanal() {
        return canal;
    }

    public void setCanal(int canal) {
        this.canal = canal;
    }

    public LocalTime getHorario() {
        return horario;
    }

    public void setHorario(LocalTime horario) {
        this.horario = horario;
    }

    @Override
    public String toString() {
        return super.toString() + 
                "\nDurassaum: " + duracao +
                "\nCanal: " + canal +
                "\nHorario: " + horario.toString();
    }
}
