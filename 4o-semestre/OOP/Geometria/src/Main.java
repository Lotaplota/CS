void main() {
    ArrayList<FormaGeometrica> formas = new ArrayList<>();

    formas.add(new Circunferencia(3));
    formas.add(Triangulo.deBaseAlturaELado(4, 2, 7));
    formas.add(Triangulo.deTresLados(3, 4, 5));
    formas.add(new Circunferencia(5));
    formas.add(new Retangulo(2, 4));
    formas.add(new Pentagono(5));

    formas.forEach(forma -> {
        System.out.println(forma);
        System.out.println("Ahrea (cm): " + forma.getArea("cm") +
                "\nPerihmetro (cm): " + forma.getPerimetro("cm")
        );
    });

    mostrarDiametros(formas);
}

public static void mostrarDiametros(ArrayList<FormaGeometrica> formas) {
    int index = 0;

    for (FormaGeometrica forma : formas) {
        if (forma instanceof Circunferencia) {
            Circunferencia c = (Circunferencia)forma;
            System.out.println("---- Forma " + index + " ----" +
                    "\nO perihmetro de uma circunferenncia de raio " +
                    c.getRaio() + " eh " + c.getDiametro() + "."
            );
        }
        index++;
    }
}
