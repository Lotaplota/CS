import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;

void main()
{
    JFrame win = new JFrame("Task Manager");
    win.setSize(400, 350);
    win.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    win.setLocationRelativeTo(null); // Centers the window
    win.setLayout(new FlowLayout());

    // ---- CENTER PANEL ----
    // Creating a task list
    JPanel centerPanel = new JPanel();

    DefaultListModel<String> model = new DefaultListModel<>();
    JList<String> taskList = new JList<>(model);

    String[] tasks = {"comer", "dormir", "cagar"};
    for (String task : tasks) { model.addElement(task); }

    centerPanel.add(taskList);
    centerPanel.add(new JScrollPane(taskList));

    // ---- TOP PANEL ----
    // Creating text field for new task
    JPanel topPanel = new JPanel();
    topPanel.add(new JLabel("New Task"));
    JTextField fieldTask = new JTextField("Task name", 20);
    topPanel.add(fieldTask);

    // Add Task button
    JButton btnAdd = new JButton("Add");
    btnAdd.addActionListener(e -> {
        model.addElement(fieldTask.getText());
        fieldTask.setText("");
    });
    topPanel.add(btnAdd);


    // ---- BOTTOM PANEL ----
    JPanel bottomPanel = new JPanel();

    JCheckBox checkUrgent = new JCheckBox("Mark as urgent");
    bottomPanel.add(checkUrgent);
    JLabel lblNotification = new JLabel("");
    bottomPanel.add(lblNotification);

    // Done button
    JButton btnDone = new JButton("Done");
    btnDone.addActionListener(e -> {
        model.removeElementAt(taskList.getSelectedIndex());
        lblNotification.setText("Task accomplished!");
    });
    bottomPanel.add(btnDone);

    // Remove Task button
    JButton btnRemove = new JButton("Remove");
    btnRemove.addActionListener(e -> {
        model.removeElementAt(taskList.getSelectedIndex());
        lblNotification.setText("Task removed.");
    });
    bottomPanel.add(btnRemove);

    // ---- MENUBAR ----
    // Creating and setting the menu and its items
    JMenuBar menuBar = new JMenuBar();
    win.setJMenuBar(menuBar);

    JMenu menu1 = new JMenu("Options");
    menuBar.add(menu1);

    JMenuItem jmiClear = new JMenuItem("Clear", KeyEvent.VK_C);
    jmiClear.addActionListener(e -> model.removeAllElements());
    menu1.add(jmiClear);

    JMenuItem jmiExit = new JMenuItem("Exit", KeyEvent.VK_E);
    jmiExit.addActionListener(e -> System.exit(0));
    jmiExit.getAccessibleContext().setAccessibleDescription("This exits the program.");
    menu1.add(jmiExit);

    // ---- PANEL LAYERING ----
    win.add(topPanel);
    win.add(centerPanel);
    win.add(bottomPanel);

    // Making the window visible
    win.setVisible(true);
}
