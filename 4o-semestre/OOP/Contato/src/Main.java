void main() {
    Scanner sc = new Scanner(System.in);

    Contato c1 = new Contato("fulano",   "61912345678");
    Contato c2 = new Contato("ciclano",  "61924681012");
    Contato c3 = new Contato("beltrano", "61903691215");

    c1.SetNome("Listhian Krucas"); c1.SetNumero("61912345678");
    c2.SetNome("Banny Eatriz"); c2.SetNumero("61924681012");
    c3.SetNome("Mayo Quendes"); c3.SetNumero("61903691215");

    IO.println(c1.toString());
    IO.println(c2.toString());
    IO.println(c3.toString());

    String entrada;
    while(true) {
        String nome; String numero;

        IO.println("""
                ---- Adicionando contato (digite 'q' para sair)
                
                Nome:\s""");
        nome = sc.nextLine();
        if (nome.equals("q") || nome.equals("Q")) break;

        IO.println("Nuhmero: ");
        numero = sc.nextLine();
        if (numero.equals("q") || numero.equals("Q")) break;

        Contato c = new Contato(nome, numero);

        IO.println(c.toString());
    }
}
