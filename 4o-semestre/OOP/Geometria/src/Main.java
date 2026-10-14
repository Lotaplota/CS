void main() {
    ArrayList<FormaGeometrica> formas = new ArrayList<>();

    formas.add(new Circunferencia(3));
    formas.add(Triangulo.deBaseAlturaELado(4, 2, 7));
    formas.add(Triangulo.deTresLados(3, 3, 5));
    formas.add(new Triangulo(5));
    formas.add(new Circunferencia(5));
    formas.add(new Retangulo(2, 4));
    formas.add(new Retangulo(4, 4));
    formas.add(new Pentagono(5));

    formas.forEach(forma -> {
        System.out.println(forma);
        System.out.println("Ahrea (cm²): " + forma.getArea("cm²") +
                "\nPerihmetro (cm): " + forma.getPerimetro("cm") + "\n"
        );
    });

    mostrarDiametros(formas);
    mostrarDiagonais(formas);
}

public static void mostrarDiametros(ArrayList<FormaGeometrica> formas) {
    int index = 0;

    for (FormaGeometrica forma : formas) {
        if (forma instanceof Circunferencia c) {
            System.out.println("---- Forma " + index + " ----" +
                "\nO dianmetro de uma circunferenncia de raio " +
                c.getRaio() + " eh " + c.getDiametro() + "\n"
            );
        }
        index++;
    }
}

public static void mostrarDiagonais(ArrayList<FormaGeometrica> formas) {
    int index = 0;

    for (FormaGeometrica forma : formas) {
        if (forma instanceof Diagonalizavel d) {
            String nome = d instanceof Retangulo ? ((Retangulo) d).isQuadrado() ? "quadrado" : "retanngulo" : "pentahgono regular";
            String medidas = d instanceof Retangulo
                ?
                    ((Retangulo) d).isQuadrado()
                        ?
                            " de lado " + ((Retangulo) d).altura
                        :
                            " de base " + ((Retangulo) forma).base + " e altura " + ((Retangulo) forma).altura
                :
                    " de lado " + ((Pentagono)forma).lado;
            System.out.println("---- Forma " + index + " ----" +
                "\nAs diagonais de um " + nome + medidas + " medem " + d.getDiagonais() + "\n");
        }
        index++;
    }
}
