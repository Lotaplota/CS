public abstract class Ave extends Animal {
    public final boolean podeVoar;

    public Ave(String nome, String sexo, int idade, boolean podeVoar) {
        super(nome, sexo, idade);
        this.podeVoar = podeVoar;
    }
}
