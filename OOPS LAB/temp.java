import javax.swing.*;
import java.awt.event.*;

class MyAdapter extends MouseAdapter {
    public MyAdapter() {
        JFrame f = new JFrame("Nothing");
        f.setSize(400, 400);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.addMouseListener(this); 
        f.setVisible(true);
    }

    @Override
    public void mouseClicked(MouseEvent e) {
        System.out.println(e.getX() + ", " + e.getY());
    }
}

public class temp {
    public static void main(String[] args) {
        new MyAdapter();
    }
}

