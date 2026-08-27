public class TimeDeFutebol
{
    private final String nome;
    Jogador[] jogadores;
    Premiacao[] titulos;

    public TimeDeFutebol(String nome)
    {
        this.nome = nome;
    }

    public String getNome() { return this.nome; }

    public void AdicionarJogador(Jogador jogador)
    {
        for (int i = 0; i < jogadores.length; i++)
        {
            if (jogadores[i] == null)
            {
                jogadores[i] = jogador;
                System.out.println("jogador inserido");
                return;
            }
        }

        System.out.println("Naum hah mais espasso para jogadores.");
    }

    public void RemoverJogador(String nomeJogador)
    {
        for (int i = 0; i < jogadores.length; i++)
        {
            if (jogadores[i].GetNome() == nomeJogador)
            {
                jogadores[i] = jogador;
                System.out.println("jogador inserido");
                return;
            }
        }
    }
}
