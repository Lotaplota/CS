public abstract class Animal {
    private String nome;
    private int idade;
    private double peso;

    public Animal(String nome, int idade, double peso) {
        this.nome = nome;
        this.idade = idade;
        this.peso = peso;
    }

    // abstratos
    public abstract void fazerBarulho();
    public abstract void mover();

    // concretos
    public void comer() {
        System.out.println(nome + " está comendo.");
    }
    public void morrer() {
        System.out.println(nome + " morreu :^[");
    }

    public String getNome() {
        return nome;
    }
    public int getIdade() { return idade; }
    public double getPeso() { return peso; }

    public void setNome(String nome) { this.nome = nome; }
    public void setPeso(double peso) { this.peso = peso; }
}
