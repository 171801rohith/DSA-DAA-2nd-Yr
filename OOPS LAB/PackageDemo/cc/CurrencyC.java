package PackageDemo.cc;

import java.util.Scanner;

public class CurrencyC {
    double inr, usd;
    Scanner sc = new Scanner(System.in);
    public void inrtousd(){
        System.out.print("Enter currency in INR :");
        inr = sc.nextDouble();
        usd = inr / 85.13;
        System.out.println("INR: " + inr + "\nUSD: " + usd);
    }
    public void usdtoinr(){
        System.out.print("Enter currency in USD :");
        usd = sc.nextDouble();
        inr = usd * 85.13;
        System.out.println("USD: " + usd + "\nINR: " + inr);
    }
}
