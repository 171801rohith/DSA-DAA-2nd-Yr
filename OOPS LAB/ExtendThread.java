class MyThread extends Thread {
    public void run() {
        try {
            for (int i = 0; i < 300; i += 2) {
                System.out.println("EVEN" + i);
                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            System.out.println(e);
        }
    }
}

class MyThread1 extends Thread {
    public void run() {
        try {
            for (int i = 1; i < 300; i += 2) {
                System.out.println(i + "ODD");
                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            System.out.println(e);
        }
    }
}

public class ExtendThread {
    public static void main(String[] args) {
        MyThread thread = new MyThread();
        MyThread1 thread1 = new MyThread1();
        thread.start();
        thread1.start();
    }
}
