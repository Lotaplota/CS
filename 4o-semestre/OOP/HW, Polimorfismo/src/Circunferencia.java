public class Circunferencia extends FormaGeometrica
{
    private final double raio;

    public Circunferencia(double raio) {
        this.raio = raio;
    }

    @Override
    public double getArea() { return PI * raio * raio; }

    @Override
    public double getPerimetro() { return 2 * PI * raio; }

    public double getRaio() { return this.raio; }
    public double getDiametro() { return 2 * raio; }

    @Override
    public String toString() {
        return "---- " + getClass().getSimpleName() + " ----" +
                "\nRaio: " + raio +
                "\nAhrea: " + this.getArea() +
                "\nPerihmetro: " + this.getPerimetro();
    }
}
