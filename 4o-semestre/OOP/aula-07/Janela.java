import javax.swing.*;

void main()
{
    JFrame janela = new JFrame("My window");
    janela.setSize(400, 300);
    janela.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    janela.setVisible(true);
    janela.setLayout(null);

    JButton botao = new JButton("Click me!");
    botao.setBounds(50, 50, 120, 30);
    janela.add(botao);

    JLabel rotulo = new JLabel("Exemple label");
    rotulo.setBounds(200, 50, 150, 30);
    janela.add(rotulo);

    janela.setVisible(true);
}

