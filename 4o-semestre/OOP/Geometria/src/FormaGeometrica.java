public abstract class FormaGeometrica {
    public final double PI = 3.14;

    public abstract double getArea();
    public abstract double getPerimetro();

    public double getArea(int casasDecimais) { return Math.floor(this.getArea() * 100) / 100; }
    public String getArea(String unidade) { return this.getArea(2) + " " + unidade; }

    public double getPerimetro(int casasDecimais) { return Math.floor(this.getPerimetro() * 100) / 100; }
    public String getPerimetro(String unidade) { return this.getPerimetro(2) + " " + unidade; }
}
