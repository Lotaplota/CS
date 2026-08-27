package com.mycompany.universidade;
import com.mycompany.universidade.entidades.*;

public class Universidade {

    public static void main(String[] args) {
        Aluno a = new Aluno("fulano", 25100276, "Ciencia da Computassaum");
        System.out.println(a.toString());
        
        DisciplinaCursada d = new DisciplinaCursada(a);
        System.out.println(d.toString());
        
        d.setN1(3);
        d.setN2(7);
        d.setN3(9);
        
        System.out.println("Frequencia: "+ d.getFreq()
            + "\nN1: " + d.getN1()
            + "\nN2: " + d.getN2()
            + "\nN3: " + d.getN3()
            + "\nMehdia final:" + d.mediaFinal());
        
        d.verificarSituacao();
    }
}
