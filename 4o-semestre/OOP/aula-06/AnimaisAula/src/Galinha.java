import interfaces.Oviparo;

public class Galinha extends Ave implements Oviparo {

    public Galinha(String nome, String sexo, int idade, boolean podeVoar) {
        super(nome, sexo, idade, podeVoar);
    }

    @Override
    public void emitirSom() {

    }

    @Override
    public void botarOvos(int quantidade) {

    }
}
