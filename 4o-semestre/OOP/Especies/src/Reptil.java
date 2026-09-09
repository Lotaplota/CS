public abstract class Reptil extends Animal {
    protected boolean peconhento;

    public Reptil(String nome, int idade, double peso, boolean peconhento) {
        super(nome, idade, peso);
        this.peconhento = peconhento;
    }

    // concretas
    public void naumFazerSentido() {
        System.out.println(this.getNome() + " naum faz sentido.");
    }
    public boolean ehPeconhento() {
        return peconhento;
    }
}
