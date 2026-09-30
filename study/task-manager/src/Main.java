import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;

void main()
{
    JFrame jan = new JFrame("Task Manager");
    jan.setSize(400, 350);
    jan.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    jan.setLocationRelativeTo(null); // Centers the window
    jan.setLayout(new FlowLayout());

    JMenuBar menuBar = new JMenuBar();
    jan.setJMenuBar(menuBar);

    // Creating and setting menu and its items
    JMenu menu1 = new JMenu("Options");
    menuBar.add(menu1);

    JMenuItem jmiClear = new JMenuItem("Clear", KeyEvent.VK_C);
    menu1.add(jmiClear);
    JMenuItem jmiExit = new JMenuItem("Exit", KeyEvent.VK_E);
    jmiExit.getAccessibleContext().setAccessibleDescription("This exits the program.");
    menu1.add(jmiExit);

    // Creating text field for new task
    JTextField fieldTask = new JTextField("Task name", 20);
    jan.add(fieldTask);

    // Add Task button
    JButton btnAdd = new JButton("Add Task");
    btnAdd.addActionListener( e -> fieldTask.setVisible( !fieldTask.isVisible() ));
    jan.add(btnAdd);

    // Clear Field button
    JButton btnClear = new JButton("Clear");
    btnClear.addActionListener(e -> fieldTask.setText(""));
    jan.add(btnClear);

    jan.setVisible(true);
}
