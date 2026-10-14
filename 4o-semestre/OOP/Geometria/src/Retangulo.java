public class Retangulo extends FormaGeometrica
{
    double base; double altura;

    public Retangulo(double base, double altura) {
        this.base = base;
        this.altura = altura;
    }

    @Override
    public double getArea() {
        return base * altura;
    }

    @Override
    public double getPerimetro() { return 2 * ( base + altura ); }

    @Override
    public String toString() {
        return "---- " + getClass().getSimpleName() + " ----" +
                "\nBase: " + base + ", altura: " + altura +
                "\nAhrea: " + this.getArea() +
                "\nPerihmetro: " + this.getPerimetro();
    }
}
