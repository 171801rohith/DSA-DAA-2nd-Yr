import java.util.Scanner;

class A {
    int num;

    public A(int num) {
        this.num = num;
    }

    public void display() {
        System.out.println("Num = " + num);
    }
}

public class ClassExample {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number: ");
        int number = sc.nextInt();
        A a = new A(number);
        a.display();
        sc.close();
    }
}
