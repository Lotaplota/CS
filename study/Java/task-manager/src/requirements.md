# Challenge: Build a "Task List" App
Create a small window where the user can add tasks to a list and mark options about them. It uses every component you've learned.

## Requirements
1. The window (JFrame)

- [X] Title: "Task Manager"
- [x] Size around 400x350, closes the program when the X is clicked, centered on screen.

2. Menu (JMenuBar, JMenu, JMenuItem)

- A File menu with two items:
- [X] Clear List: removes all tasks from the list<br> 
- [X] Exit: closes the program

3. Top area (JPanel)

A JLabel with the text "New task:"
A JTextField where the user types the task
A JButton labeled "Add"

4. Center area

A JList showing all the tasks added so far. (Tip: use a DefaultListModel to hold the items, and put the JList inside a JScrollPane.)

5. Bottom area (JPanel)

A JCheckBox labeled "Mark as urgent"
A JLabel that shows a status message, such as "Task added!" or "Type something first!"
Behavior
Clicking Add puts the text from the JTextField into the JList, then clears the text field.
If the text field is empty, don't add anything and show a warning in the status label.
If Mark as urgent is checked when adding, the task should appear as "[URGENT] task name".
Clear List empties the list.
Suggested Steps
Create the JFrame and make it appear on screen.
Add the JPanels and place the components using BorderLayout (top, center, bottom).
Add the menu bar.
Make the Add button work using an ActionListener.
Add the checkbox logic and the menu actions.
Bonus (only if you finish early)
Add a second menu called Help with an "About" item that shows a message dialog (JOptionPane.showMessageDialog).
Let the user press Enter in the text field to add the task too.
Hints
frame.setLocationRelativeTo(null) centers the window.
checkBox.isSelected() tells you whether it's checked.
textField.getText().trim() gets the text without extra spaces.
listModel.addElement(...) and listModel.clear() change what the JList shows.

Good luck! If you get stuck on a specific part, send me your code and I'll help you figure it out without just handing over the answer.