public class Arara extends Ave {
    private String cor;

    public Arara(String nome, int idade, double peso, String cor) {
        super(nome, idade, peso, true);
        this.cor = cor;
    }

    @Override
    public void fazerBarulho() {
        System.out.println(this.getNome() + " disse: Craaa craaa!");
    }

    @Override
    public void mover() {
        System.out.println(this.getNome() + " voou para lah.");
    }
    public void imitarVoz() {
        System.out.println(this.getNome() + " repetiu o que vosse falou!");
    }

    public String getCor() {
        return cor;
    }
}
