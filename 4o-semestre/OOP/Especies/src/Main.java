public class Main {
    public static void main(String[] args) {

        // Criando um objeto de cada classe concreta
        Cachorro cachorro = new Cachorro("caramelo", 3, 12.5, "caramelo", "caramelo");
        Gato gato = new Gato("Rato", 2, 4.2, "Preto", true);
        Tartaruga tartaruga = new Tartaruga("Tortuguita", 10, 1.3, true);
        Iguana iguana = new Iguana("Igor Ana", 4, 2.8, true);
        Galinha galinha = new Galinha("Rua", 1, 2.0);
        Calopsita calopsita = new Calopsita("Paroxihtona", 2, 0.1, true);
        Pardal pardal = new Pardal("Detran", 1, 0.03);
        Arara arara = new Arara("A Rara", 5, 1.1, "azul e amarela");

        System.out.println("\n==== olha o rancho ====\n");

        cachorro.buscarObjeto();
        gato.receberCarinho();

        tartaruga.seEsconder();
        iguana.naumFazerSentido();

        galinha.ciscar();
        calopsita.assobiar();
        pardal.construirNinho();
        arara.imitarVoz();

        System.out.println();
        cachorro.amamentar();  // Mamífero
        gato.amamentar();      // Mamífero

        tartaruga.naumFazerSentido(); // Réptil
        iguana.naumFazerSentido();    // Réptil

        galinha.colocarOvos();  // Ave
        arara.voar();           // Ave
        galinha.voar();         // Ave que não voa
    }
}