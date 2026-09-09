public class Gato extends Mamifero {
    private boolean ehManso;

    public Gato(String nome, int idade, double peso, String corPelo, boolean ehManso) {
        super(nome, idade, peso, corPelo);
        this.ehManso = ehManso;
    }

    @Override
    public void fazerBarulho() {
        System.out.println(this.getNome() + " (Gato) faz: Miau!");
    }
    @Override
    public void mover() {
        System.out.println(this.getNome() + " está andando silenciosamente.");
    }

    public void receberCarinho() {
        if (ehManso) { System.out.println(this.getNome() + " ronronou."); }
        else {System.out.println(this.getNome() + " te zunhou"); }
    }
}
