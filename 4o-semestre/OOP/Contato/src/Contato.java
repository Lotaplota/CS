public class Contato {
    private String nome;
    private String numero;

    public Contato(String nome, String numero)
    {
        this.nome = nome;
        this.numero = numero;
    }

    public void SetNome(String nome)
    {
        IO.println("Alterado o nome de " + this.nome + " para " + nome + ".");
        this.nome = nome;
    }
    public void SetNumero(String numero)
    {
        IO.println("Alterado o nuhmero de " + this.nome + " para " + numero + ".");
        this.numero = numero;
    }

    public String GetNome() { return this.nome; }
    public String GetNumero() { return this.numero; }

    @Override
    public String toString()
    {
        return "DADOS:\n\tNome: " + this.nome + "\tNuhmero: " + this.numero + "\n";
    }
}