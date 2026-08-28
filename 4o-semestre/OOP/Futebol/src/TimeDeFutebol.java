public class TimeDeFutebol
{
    private final String nome;
    private Jogador[] jogadores;
    private Premiacao[] titulos;
    private int qtJogadores;
    private int qtTitulos;

    public TimeDeFutebol(String nome, int lmtJogadores)
    {
        this.nome = nome;
        this.jogadores = new Jogador[lmtJogadores];
        this.qtJogadores = 0;
        this.titulos = new Premiacao[99];
        qtTitulos = 0;
    }

    public String getNome() { return this.nome; }

    public void AdicionarJogador(Jogador jogador)
    {
        for (int i = 0; i < jogadores.length; i++)
        {
            if (jogadores[i] == null)
            {
                jogadores[i] = jogador;
                jogador.SetTime(this.nome);
                qtJogadores++;
                System.out.printf("Jogador %s inserido.\n", jogador.GetNome());
                return;
            }
        }

        System.out.println("Naum hah mais espasso para jogadores.");
    }

    public void RemoverJogador(String nomeJogador)
    {
        for (int i = 0; i < jogadores.length; i++)
        {
            if (jogadores[i].GetNome().equals(nomeJogador))
            {
                jogadores[i].SetTime("");
                jogadores[i] = null;
                qtJogadores--;
                System.out.printf("Jogador %s removido.\n", nomeJogador);
                return;
            }
        }
        System.out.printf("Nenhum jogador com o nome %s foi encontrado.\n", nomeJogador);
    }

    public void ExibirJogadores()
    {
        if (jogadores.length < 1)
        {
            System.out.println("Este time ainda não possui jogadores.");
        }

        for (int i = 0; i < this.qtJogadores; i++)
        {
            System.out.printf("%d. %s\n", i, jogadores[i].GetNome());
        }
        System.out.println();
    }

    public void AdicionarTitulo(Premiacao titulo)
    {
        if (qtTitulos == titulos.length)
        {
            System.out.printf("n eh o %s q eu conhesso\n", this.nome);
        }
        else
        {
            titulos[qtTitulos] = titulo;
            qtTitulos++;

            System.out.printf("%s ganhou o título %s %d!\n", this.nome, titulo.GetTitulo(), titulo.GetAno());
        }
    }
}
