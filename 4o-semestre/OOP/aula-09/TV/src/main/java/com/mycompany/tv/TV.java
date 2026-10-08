package com.mycompany.tv;

import com.mycompany.tv.midia.Filme;
import com.mycompany.tv.midia.Multimidia;
import com.mycompany.tv.midia.Serie;
import com.mycompany.tv.telas.Home;
import java.util.ArrayList;

public class TV {

    public static void main(String[] args) {
        ArrayList<Multimidia> lista = new ArrayList<>();

        lista.add(new Filme("A Origem",
                "Um ladrão que rouba segredos corporativos por meio do uso de tecnologia de compartilhamento de sonhos recebe a tarefa inversa de plantar uma ideia na mente de um herdeiro.",
                "Ficção Científica", 148));
        lista.add(new Filme("Forrest Gump: O Contador de Histórias", "As presidências de Kennedy e Johnson, os eventos do Vietnã, de Watergate e outras histórias históricas se desenrolam sob a perspectiva de um homem do Alabama com um QI de 75.",
                "Drama", 142));
        lista.add(new Filme("O Rei Leão", "O príncipe leão Simba e seu pai sofrem com as armadilhas de seu tio cruel, que planeja assumir o trono a qualquer custo.",
                "Animação", 88));
        lista.add(new Filme("Harry Potter e a Pedra Filosofal", "Um garoto órfão descobre que é um bruxo e se matricula em uma escola de magia, onde faz amigos e inimigos poderosos.",
                "Fantasia", 152));
        lista.add(new Filme("O Sexto Sentido", "Um psicólogo infantil tenta ajudar um garoto isolado que afirma ser capaz de ver e conversar com pessoas mortas.",
                "Suspense", 107));
        lista.add(new Serie("Stranger Things",
                "Um grupo de amigos se envolve em uma série de eventos sobrenaturais na pacata cidade de Hawkins.",
                "Ficção Científica", 4, 34));
        lista.add(new Serie("The Office",
                "O cotidiano divertido e quase sempre absurdo dos funcionários de uma empresa de papel em Scranton.",
                "Comédia", 9, 201));
        lista.add(new Serie("Breaking Bad",
                "Um professor de química do ensino médio descobre uma doença grave e recorre ao crime para sustentar sua família.",
                "Drama", 5, 62));
        lista.add(new Filme("De Volta para o Futuro", "Marty McFly, um adolescente de 17 anos, é acidentalmente enviado trinta anos no passado em uma máquina do tempo inventada por seu amigo cientista.",
                "Ficção Científica/Comédia", 116));

        for (Multimidia m : lista) {
            exibir(m);
        }

        Home.run(lista);
    }

    private static void exibir(Multimidia mult) {
        System.out.println(mult);
    }
}
