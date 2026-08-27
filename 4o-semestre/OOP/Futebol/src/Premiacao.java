import java.time.Year;

public class Premiacao {
    private final String titulo;
    private final int ano;

    Premiacao(String titulo)
    {
        this.titulo = titulo;
        this.ano = Year.now().getValue();
    }

    Premiacao(String titulo, int ano)
    {
        int esteAno = Year.now().getValue();
        this.titulo = titulo;
        if (ano < 1871 || ano > Year.now().getValue())
        {
            this.ano = esteAno;
            System.out.println("Ano invahlido. Ano atual (" + esteAno + ") passado como parâmetro.");
        } else { this.ano = ano; }
    }

    public String GetTitulo() { return this.titulo; }
}
