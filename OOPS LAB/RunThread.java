class MyRunThread1 implements Runnable {
    @Override
    public void run() {
        try{
            for (int i = 1; i < 30; i += 2) {
                System.out.println(i);
                Thread.sleep(1000); 
            }
        }catch(InterruptedException e){
            System.out.println(e);
        }
    }

}

public class RunThread {
    public static void main(String[] args) {
        Thread thread = new Thread(new MyRunThread1());
        thread.start();
        // OR
        MyRunThread1 myRunThread1 = new MyRunThread1();
        Thread t = new Thread(myRunThread1);
        t.start();
    }
}
