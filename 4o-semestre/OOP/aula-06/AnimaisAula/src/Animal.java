public abstract class Animal {
    protected final String nome;
    protected final String sexo;
    protected int idade;

    public Animal(String nome, String sexo, int idade) {
        this.nome = nome;
        this.sexo = sexo;
        this.idade = idade;
    }

    public abstract void emitirSom();
}
