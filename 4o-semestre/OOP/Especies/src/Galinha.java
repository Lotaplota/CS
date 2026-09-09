public class Galinha extends Ave {
    public Galinha(String nome, int idade, double peso) {
        super(nome, idade, peso, false);
    }

    @Override
    public void fazerBarulho() {
        System.out.println(this.getNome() + " faz: Cocoricoh!");
    }
    @Override
    public void mover() {
        System.out.println(this.getNome() + " estah ciscando.");
    }

    public void ciscar() {
        System.out.println(this.getNome() + " estah ciscando o chaum.");
    }
}
