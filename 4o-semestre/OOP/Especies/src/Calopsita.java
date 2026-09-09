public class Calopsita extends Ave {
    private boolean sabeAssobiar;

    public Calopsita(String nome, int idade, double peso, boolean sabeAssobiar) {
        super(nome, idade, peso, true);
        this.sabeAssobiar = sabeAssobiar;
    }

    @Override
    public void fazerBarulho() { System.out.println(this.getNome() + " faz: Piu piu!"); }
    @Override
    public void mover() {
        System.out.println(this.getNome() + " pulou pra lah.");
    }

    public void assobiar() {
        if (sabeAssobiar) {
            System.out.println(this.getNome() + ": pi piri pipiiii!");
        } else {
            System.out.println(this.getNome() + " ainda naum aprendeu a assobiar.");
        }
    }
}
