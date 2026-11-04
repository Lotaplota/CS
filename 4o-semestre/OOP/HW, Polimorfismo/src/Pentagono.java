import static java.lang.Math.*;

// Limitei a classe a pentágonos regulares devido à gama extensiva de possíveis pentágonos
// Como foi pedida a classe "Retângulo" e não a "Quadrilátero", me dei essa liberdade
public class Pentagono extends FormaGeometrica implements Diagonalizavel {
    double lado;
    double apotema;

    public Pentagono(double lado) {
        this.lado = lado;
        this.apotema = lado / (2 * tan( toRadians(36) ));
    }

    public double getDiagonais() { return lado * ((1 + sqrt(5)) / 2); }

    @Override
    public double getArea() { return (5.0 / 2) * lado * apotema;  }

    @Override
    public double getPerimetro() { return 5 * lado; }

    @Override
    public String toString() {
        return "---- " + getClass().getSimpleName() + " ----" +
                "\nLado: " + lado + ", apohtema: " + apotema +
                "\nAhrea: " + this.getArea() +
                "\nPerihmetro: " + this.getPerimetro();
    }
}
