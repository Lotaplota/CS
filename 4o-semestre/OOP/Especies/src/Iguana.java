public class Iguana extends Reptil {
    private boolean peleVelha;

    public Iguana(String nome, int idade, double peso, boolean peleVelha) {
        super(nome, idade, peso, false);
        this.peleVelha = peleVelha;
    }

    @Override
    public void fazerBarulho() {
        System.out.println(this.getNome() + " naum fez barulho.");
    }
    @Override
    public void mover() {
        System.out.println(this.getNome() + " naum se moveu.");
    }

    public void trocarDePele()
    {
        if (peleVelha) { System.out.println(this.getNome() + " trocou de pele."); }
        else { System.out.println(this.getNome() + "naum precisa trocar de pele ainda."); }
    }
}
