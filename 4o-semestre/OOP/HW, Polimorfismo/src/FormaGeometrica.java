import static java.lang.Math.pow;

public abstract class FormaGeometrica {
    public final double PI = 3.14;

    public abstract double getArea();
    public abstract double getPerimetro();

    public double getArea(int casasDecimais) {
        return Math.floor(this.getArea() * pow(10, casasDecimais)) / pow(10, casasDecimais);
    }
    public String getArea(String unidade) { return this.getArea(3) + " " + unidade; }

    public double getPerimetro(int casasDecimais) {
        return Math.floor(this.getPerimetro() * pow(10, casasDecimais)) / pow(10, casasDecimais);
    }
    public String getPerimetro(String unidade) { return this.getPerimetro(2) + " " + unidade; }
}
