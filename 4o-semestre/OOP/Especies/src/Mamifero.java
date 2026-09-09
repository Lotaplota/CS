public abstract class Mamifero extends Animal {
    protected String corPelo;

    public Mamifero(String nome, int idade, double peso, String corPelo) {
        super(nome, idade, peso);
        this.corPelo = corPelo;
    }

    public void amamentar() {
        System.out.println(this.getNome() + " estah amamentando seus filhotes.");
    }

    public String getCorPelo() {
        return corPelo;
    }

    public void setCorPelo(String corPelo) {
        this.corPelo = corPelo;
    }
}
