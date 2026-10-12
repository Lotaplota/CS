public class Circunferencia extends FormaGeometrica
{
    private final double raio;

    public Circunferencia(double raio) {
        this.raio = raio;
    }

    @Override
    public double getArea() {
        return PI * raio * raio;
    }

    @Override
    public double getPerimetro() {
        return 2 * PI * raio;
    }
}
