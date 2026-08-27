package com.mycompany.animais;

public class Animais {

    public static void main(String[] args) {
        Cachorro c1 = new Cachorro("verme", "borzoi", "leite vencido", "cachorro");
        System.out.println(c1.toString());
        
        Cachorro c2 = new Cachorro("cha", "co", "rro", "chacorro");
        System.out.println(c1.toString());
        System.out.println(c2.toString());
    }
}
