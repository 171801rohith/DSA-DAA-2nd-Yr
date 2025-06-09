package PackageDemo.main;
import PackageDemo.cc.CurrencyC;
import PackageDemo.dc.DistanceC;

public class Main {
    public static void main(String[] args) {
        DistanceC dc = new DistanceC();
        CurrencyC cc = new CurrencyC();
        System.out.println("Currrency Convertor");
        cc.inrtousd();
        cc.usdtoinr();
        System.out.println("Distance Convertor");
        dc.mtokm();
        dc.kmtom();
    }
}
