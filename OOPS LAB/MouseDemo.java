import javax.swing.JFrame;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

class MouseListenerDemo extends JFrame implements MouseListener {
    public MouseListenerDemo() {
        setSize(500, 500);
        setTitle("Keyboard Demo");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        addMouseListener(this);
        setVisible(true);
    }

    @Override
    public void mouseClicked(MouseEvent e) {
        System.out.println("Mouse clicked at (" + e.getX() + ", " + e.getY() + ")");
    }

    @Override
    public void mousePressed(MouseEvent e) {
        System.out.println("Mouse Pressed at (" + e.getX() + ", " + e.getY() + ")");
    }

    @Override
    public void mouseReleased(MouseEvent e) {
        System.out.println("Mouse Released at (" + e.getX() + ", " + e.getY() + ")");
    }

    @Override
    public void mouseEntered(MouseEvent e) {
        System.out.println("Mouse Entered the Frame");
    }

    @Override
    public void mouseExited(MouseEvent e) {
        System.out.println("Mouse Exited the Frame");
    }
}

public class MouseDemo {
    public static void main(String[] args) {
        new MouseListenerDemo();
    }
}
