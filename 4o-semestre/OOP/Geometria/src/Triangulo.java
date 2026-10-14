import static java.lang.Math.sqrt;

public class Triangulo extends FormaGeometrica
{
    private final double base;
    private final double altura;
    private final double lado1;
    private final double lado2;

    public Triangulo (double base, double altura, double lado1, double lado2) {
        this.base = base;
        this.altura = altura;
        this.lado1 = lado1;
        this.lado2 = lado2;
    }

    public static Triangulo deBaseAlturaELado(double base, double altura, double lado) {
        double lado2 = calcular3oLado(base, altura, lado);
        return new Triangulo(base, altura, lado, lado2);
    }

    public static Triangulo deTresLados(double lado1, double lado2, double lado3) {
        double altura = calcularAltura(lado1, lado2, lado3);
        return new Triangulo(lado3, altura, lado1, lado2);
    }

    private static double calcular3oLado(double b, double h, double l) {
        double kbs = sqrt( (l * l) - (h * h) );
        double ubs = b - kbs;
        if (kbs > b) { ubs *= -1; }

        return sqrt(h * h + ubs * ubs);
    }

    private static double calcularAltura(double lado1, double lado2, double base) {
        double p = (lado1 + lado2 + base) / 2;
        double a = sqrt(p * (p - lado1) * (p - lado2) * (p - base));

        return ( 2 * a ) / base;
    }

    @Override
    public double getArea() { return base * altura / 2; }

    @Override
    public double getPerimetro() { return base + lado1 + lado2; }
}
