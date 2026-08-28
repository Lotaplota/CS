void main() {
    TimeDeFutebol curintia = new TimeDeFutebol("Corinthians", 11);
    Jogador ugo = new Jogador("Hugo Souza", "123.456.789-10");
    Jogador bidu = new Jogador("Matheus Bidu", "987.654.321-00");
    Jogador menfs = new Jogador("Memphis Depay", "gringo");

    curintia.AdicionarJogador(ugo);
    curintia.AdicionarJogador(bidu);
    curintia.AdicionarJogador(menfs);
    curintia.ExibirJogadores();

    Premiacao copinha = new Premiacao("Copa do Brasil", 2025);
    curintia.AdicionarTitulo(copinha);

    curintia.RemoverJogador("Memphis Depay"); // Muito caro
    curintia.ExibirJogadores();

    Premiacao liberta2026 = new Premiacao("Libertadores");
    curintia.AdicionarJogador(menfs); // eita cancela
}
