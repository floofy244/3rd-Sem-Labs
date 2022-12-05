// text editor using swings

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;
import java.io.*;

public class text extends JFrame implements ActionListener
{
    private JTextArea textArea;
    private JFileChooser fileChooser;
    private File file;
    private String fileName;
    private String fileContent;
    private String fileContent2;
    private String fileContent3;
    private String fileContent4;
    private String fileContent5;
    private String fileContent6;
    private String fileContent7;
    private String fileContent8;
    private String fileContent9;
    private String fileContent10;
    private String fileContent11;
    private String fileContent12;
    private String fileContent13;
    private String fileContent14;
    private String fileContent15;
    private String fileContent16;
    private String fileContent17;
    private String fileContent18;
    private String fileContent19;
    private String fileContent20;
    private String fileContent21;
    private String fileContent22;
    private String fileContent23;
    private String fileContent24;
    private String fileContent25;
    private String fileContent26;
    private String fileContent27;
    private String fileContent28;
    private String fileContent29;
    private String fileContent30;
    private String fileContent31;
    private String fileContent32;
    private String fileContent33;
    private String fileContent34;
    private String fileContent35;
    private String fileContent36;
    private String fileContent37;
    private String fileContent38;
    private String fileContent39;
    private String fileContent40;
    private String fileContent41;
    private String fileContent42;
    private String fileContent43;
    private String fileContent44;
    private String fileContent45;
    private String fileContent46;
    private String fileContent47;
    private String fileContent48;
    private String fileContent49;
    private String fileContent50;
    private String fileContent51;
    private String fileContent52;
    private String fileContent53;
    private String fileContent54;
    private String fileContent55;
    private String fileContent56;
    private String fileContent57;
    private String fileContent58;
    private String fileContent59;
    private String fileContent60;
    private String fileContent61;
    private String fileContent62;
    private String fileContent63;
    private String fileContent64;
    private String fileContent65;
    private String fileContent66;
    private String fileContent67;
    private String fileContent68;
    private String fileContent69;
    private String fileContent70;
    private String fileContent71;
    private String fileContent72;
    private String fileContent73;

    public text()
    {
        super("Text Editor");
        textArea = new JTextArea();
        fileChooser = new JFileChooser();
        fileChooser.setFileSelectionMode(JFileChooser.FILES_ONLY);
        fileChooser.setMultiSelectionEnabled(false);
        fileChooser.setFileFilter(new javax.swing.filechooser.FileFilter()
        {
            public boolean accept(File f)
            {
                return f.isDirectory() || f.getName().toLowerCase().endsWith(".txt");
            }
            public String getDescription()
            {
                return "Text Files (*.txt)";
            }
        });
        JMenuBar menuBar = new JMenuBar();
        JMenu fileMenu = new JMenu("File");
        JMenuItem openItem = new JMenuItem("Open");
        JMenuItem saveItem = new JMenuItem("Save");
        JMenuItem exitItem = new JMenuItem("Exit");
        JMenu editMenu = new JMenu("Edit");
        JMenuItem cutItem = new JMenuItem("Cut");
        JMenuItem copyItem = new JMenuItem("Copy");
        JMenuItem pasteItem = new JMenuItem("Paste");
        JMenuItem deleteItem = new JMenuItem("Delete");
        JMenuItem selectAllItem = new JMenuItem("Select All");
        JMenuItem findItem = new JMenuItem("Find");
        JMenuItem replaceItem = new JMenuItem("Replace");

        JMenu helpMenu = new JMenu("Help");
        JMenuItem aboutItem = new JMenuItem("About");



        openItem.addActionListener(this);
        saveItem.addActionListener(this);
        exitItem.addActionListener(this);
        cutItem.addActionListener(this);
        copyItem.addActionListener(this);
        pasteItem.addActionListener(this);
        deleteItem.addActionListener(this);
        selectAllItem.addActionListener(this);
        aboutItem.addActionListener(this);
        findItem.addActionListener(this);
        replaceItem.addActionListener(this);

        fileMenu.add(openItem);
        fileMenu.add(saveItem);
        fileMenu.add(exitItem);
        editMenu.add(cutItem);
        editMenu.add(copyItem);
        editMenu.add(pasteItem);
        editMenu.add(deleteItem);
        editMenu.add(selectAllItem);
        helpMenu.add(aboutItem);
        editMenu.add(findItem);
        editMenu.add(replaceItem);

        menuBar.add(fileMenu);
        menuBar.add(editMenu);
        menuBar.add(helpMenu);

        setJMenuBar(menuBar);
        add(new JScrollPane(textArea), BorderLayout.CENTER);
        setSize(500, 500);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e)
    {
        if (e.getActionCommand().equals("Open"))
        {
            if (fileChooser.showOpenDialog(this) == JFileChooser.APPROVE_OPTION)
            {
                file = fileChooser.getSelectedFile();
                fileName = file.getName();
                try
                {
                    BufferedReader in = new BufferedReader(new FileReader(file));
                    String line = in.readLine();
                    fileContent = "";
                    while (line != null)
                    {
                        fileContent += line + " ";
                        line = in.readLine();
                    }
                    in.close();
                    textArea.setText(fileContent);
                }
                catch (IOException ioe)
                {
                    JOptionPane.showMessageDialog(this, "Error reading file", "Error", JOptionPane.ERROR_MESSAGE);
                }
            }
        }
        else if (e.getActionCommand().equals("Save"))
        {
            if (fileChooser.showSaveDialog(this) == JFileChooser.APPROVE_OPTION)
            {
                file = fileChooser.getSelectedFile();
                fileName = file.getName();
                try
                {
                    BufferedWriter out = new BufferedWriter(new FileWriter(file));
                    out.write(textArea.getText());
                    out.close();
                }
                catch (IOException ioe)
                {
                    JOptionPane.showMessageDialog(this, "Error writing file", "Error", JOptionPane.ERROR_MESSAGE);
                }
            }
        }
        else if (e.getActionCommand().equals("copy"))
        {
            fileContent2 = textArea.getText();
        }
        else if (e.getActionCommand().equals("paste"))
        {
            fileContent3 = textArea.getText();
            textArea.setText(fileContent2);
        }
        else if (e.getActionCommand().equals("cut"))
        {
            fileContent4 = textArea.getText();
            textArea.setText("");
        }
        else if (e.getActionCommand().equals("undo"))
        {
            fileContent5 = textArea.getText();
            textArea.setText(fileContent4);
        }
        else if (e.getActionCommand().equals("redo"))
        {
            fileContent6 = textArea.getText();
            textArea.setText(fileContent5);
        }
        else if (e.getActionCommand().equals("select all"))
        {
            fileContent7 = textArea.getText();
            textArea.selectAll();
        }
        else if (e.getActionCommand().equals("deselect all"))
        {
            fileContent8 = textArea.getText();
            textArea.select(0, 0);
        }
        else if (e.getActionCommand().equals("find"))
        {
            fileContent9 = textArea.getText();
            String find = JOptionPane.showInputDialog("Enter the word to find");
            int index = fileContent9.indexOf(find);
            if (index == -1)
            {
                JOptionPane.showMessageDialog(this, "Word not found", "Error", JOptionPane.ERROR_MESSAGE);
            }
            else
            {
                textArea.select(index, index + find.length());
            }
        }
        else if (e.getActionCommand().equals("replace"))
        {
            fileContent10 = textArea.getText();
            String find = JOptionPane.showInputDialog("Enter the word to find");
            String replace = JOptionPane.showInputDialog("Enter the word to replace");
            int index = fileContent10.indexOf(find);
            if (index == -1)
            {
                JOptionPane.showMessageDialog(this, "Word not found", "Error", JOptionPane.ERROR_MESSAGE);
            }
            else
            {
                textArea.replaceRange(replace, index, index + find.length());
            }
        }
        else if (e.getActionCommand().equals("Exit"))
        {
            System.exit(0);
        }
    }

    public static void main(String[] args)
    {
        text t = new text();
    }
}