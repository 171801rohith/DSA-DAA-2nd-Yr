package PackageDemo.dc;

import java.util.Scanner;

public class DistanceC {
        double meter, kilometer;
    Scanner sc = new Scanner(System.in);
    public void mtokm(){
        System.out.print("Enter distance in METER :");
        meter = sc.nextDouble();
        kilometer = meter / 1000;
        System.out.println("METER: " + meter + "\nKILOMETER: " + kilometer);
    }
    public void kmtom(){
        System.out.print("Enter distance in KILOMETER :");
        kilometer = sc.nextDouble();
        meter = kilometer * 1000;
        System.out.println("KILOMETER: " + kilometer + "\nMETER: " + meter);
    }
}
