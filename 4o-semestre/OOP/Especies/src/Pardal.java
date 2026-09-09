public class Pardal extends Ave {
    public Pardal(String nome, int idade, double peso) {
        super(nome, idade, peso, true);
    }

    @Override
    public void fazerBarulho() { System.out.println(this.getNome() + " faz: Piu piu!"); }
    @Override
    public void mover() {
        System.out.println(this.getNome() + " saiu voando.");
    }

    public void construirNinho() {
        System.out.println(this.getNome() + " estah construindo um ninho.");
    }
    public void cacarMinhocas() { System.out.println(this.getNome() + " estah cassando minhocas."); }
}
