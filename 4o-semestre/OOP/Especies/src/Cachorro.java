public class Cachorro extends Mamifero {
    private String raca;

    public Cachorro(String nome, int idade, double peso, String corPelo, String raca)
    {
        super(nome, idade, peso, corPelo);
        this.raca = raca;
    }

    @Override
    public void fazerBarulho() {
        System.out.println(this.getNome() + " faz: Au au!");
    }
    @Override
    public void mover() {
        System.out.println(this.getNome() + " correu pra lah.");
    }

    public void buscarObjeto() {
        System.out.println(this.getNome() + " foi buscar a bolinha.");
    }
}
