public abstract class Ave extends Animal {
    private boolean voa;

    public Ave(String nome, int idade, double peso, boolean sabeVoar) {
        super(nome, idade, peso);
        this.voa = sabeVoar;
    }

    public void colocarOvos() {
        System.out.println(this.getNome() + " colocou ovos.");
    }
    public void voar() {
        if (voa) {
            System.out.println(this.getNome() + " estah voando.");
        } else {
            System.out.println(this.getNome() + " naum consegue voar.");
        }
    }

    public boolean sabeVoar() {
        return voa;
    }
}
