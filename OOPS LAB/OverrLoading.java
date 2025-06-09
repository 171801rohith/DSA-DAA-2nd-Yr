import java.util.Scanner;

public class OverrLoading {

    public static void add(int x, int y) {
        System.out.println("Sum = " + (x + y));
    }

    public static void add(float x, float y) {
        System.out.println("Sum = " + (x + y));
    }

    public static void subs(int x, int y) {
        System.out.println("Substraction = " + (x - y));
    }

    public static void subs(float x, float y) {
        System.out.println("Substraction = " + (x - y));
    }

    public static void div(int x, int y) {
        System.out.println("Division = " + (x / y));
    }

    public static void div(float x, float y) {
        System.out.println("Division = " + (x / y));
    }

    public static void mul(int x, int y) {
        System.out.println("Multiplication = " + (x * y));
    }

    public static void mul(float x, float y) {
        System.out.println("Multiplication = " + (x * y));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int ch;
        int opt;
        while (true) {
            System.out.println("1. Using Integer\t\t2. Using Float");
            ch = sc.nextInt();
            switch (ch) {
                case 1: {
                    System.out.println("1. Add");
                    System.out.println("2. Substract");
                    System.out.println("3. Divide");
                    System.out.println("4. Multiply");
                    opt = sc.nextInt();
                    System.out.println("Enter 2 values");
                    int x = sc.nextInt();
                    int y = sc.nextInt();
                    switch (opt) {
                        case 1:
                            add(x, y);
                            break;
                        case 2:
                            subs(x, y);
                            break;
                        case 3:
                            div(x, y);
                            break;
                        case 4:
                            mul(x, y);
                            break;
                        default:
                            return;
                    }
                }
                    break;
                case 2: {
                    System.out.println("1. Add");
                    System.out.println("2. Substract");
                    System.out.println("3. Divide");
                    System.out.println("4. Multiply");
                    opt = sc.nextInt();
                    float x = sc.nextInt();
                    float y = sc.nextInt();
                    switch (opt) {
                        case 1:
                            add(x, y);
                            break;
                        case 2:
                            subs(x, y);
                            break;
                        case 3:
                            div(x, y);
                            break;
                        case 4:
                            mul(x, y);
                            break;
                        default:
                            return;
                    }
                }
                    break;
                default:
                    return;
            }

        }
    }
}