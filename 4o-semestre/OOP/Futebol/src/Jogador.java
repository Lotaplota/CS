public class Jogador {
    private final String nome;
    private final String cpf;
    private String time;

    public Jogador(String nome, String cpf)
    {
        this.nome = nome;
        this.cpf = cpf;
    }

    public String GetNome() { return this.nome; }
    public String GetCPF() { return this.cpf; }
    public String GetTime() { return this.time; }

    public void SetTime(String nomeTime) { this.time = nomeTime; }
}
