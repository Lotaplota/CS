package com.mycompany.primeiraaula;

import com.mycompany.primeiraaula.animais.Cachorro;
import com.mycompany.primeiraaula.animais.Gato;

public class PrimeiraAula {

    public static void main(String[] args) {
        int a = 5, b = 2, c = 4, d = 3, e = 1;
        
        System.out.println("a + b + c = " + ((float)a * b) / c );
        System.out.println("a * b %% c + 1" + (a * b % c + 1));
        System.out.println("++a * b - c--" + (++a * b - c--));
        Cachorro verme = new Cachorro("verme", "pupu da lomerania", "malhado", "masculino");
        
        System.out.println("O cachorrinho " + verme.getNome() + " eh " + verme.getCor() + " e nojento, e eh da rassa " + verme.getRaca() + ".");
        verme.latirDuasVezes();
        
        Gato dalit = new Gato("Dalit", "Siamês", "branco com botas pretas", "masculino");
        dalit.dormir(); // sleep well little buddy ♥️
    }
}
