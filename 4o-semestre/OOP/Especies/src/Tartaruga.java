public class Tartaruga extends Reptil {
    private boolean ehAquatica;

    public Tartaruga(String nome, int idade, double peso, boolean aquatica) {
        super(nome, idade, peso, false); // tartarugas não são peçonhentas
        this.ehAquatica = aquatica;
    }

    @Override
    public void fazerBarulho() {
        System.out.println(this.getNome() + " naum fez barulho.");
    }
    @Override
    public void mover() { System.out.println(this.getNome() + " fooooi... paaaara... laaah..."); }

    public void seEsconder() {
        System.out.println(this.getNome() + " se escondeu em seu casco");
    }
}
