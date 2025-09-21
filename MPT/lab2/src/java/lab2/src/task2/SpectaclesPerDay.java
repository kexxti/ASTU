package task2;


import java.util.Scanner;

public class SpectaclesPerDay {
    private Spectacle morningSpec;
    private Spectacle daySpec;
    private Spectacle eveningSpec;

    private double morningFill;
    private double dayFill;
    private double eveningFill;

    private String name;

    public void Init(String n, Spectacle ms, Spectacle ds, Spectacle es,
                     double mf, double df, double ef){
        name = n;
        morningSpec = ms;
        daySpec = ds;
        eveningSpec = es;
        morningFill = mf;
        dayFill = df;
        eveningFill = ef;
    }

    public void Read(Scanner sc) {
        System.out.print("Введите имя объекта: ");
        sc.nextLine(); // consume leftover newline if needed
        name = sc.nextLine();

        System.out.println("Утренний спектакль:");
        morningSpec = new Spectacle();
        morningSpec.Read(sc);
        System.out.print("Утренняя посещаемость (%): ");
        morningFill = sc.nextDouble();

        System.out.println("Дневной спекталь:");
        daySpec = new Spectacle();
        daySpec.Read(sc);
        System.out.print("Дневная посещаемость (%): ");
        dayFill = sc.nextDouble();

        System.out.println("Вечерний спектакль:");
        eveningSpec = new Spectacle();
        eveningSpec.Read(sc);
        System.out.print("Вечерняя посещаемость (%): ");
        eveningFill = sc.nextDouble();
    }

    public void display() {
        System.out.println("Имя: " + name);

        System.out.print("Утро: ");
        morningSpec.Display();
        System.out.println("Посещаемость: " + morningFill + "%");

        System.out.print("День: ");
        daySpec.Display();
        System.out.println("Посещаеомсть: " + dayFill + "%");

        System.out.print("Вечер: ");
        eveningSpec.Display();
        System.out.println("Посещаемость: " + eveningFill + "%");
    }

    public double totalSales() {
        double sum = 0;
        sum += morningFill / 100.0 * morningSpec.ExpectedRevenue();
        sum += dayFill / 100.0 * daySpec.ExpectedRevenue();
        sum += eveningFill / 100.0 * eveningSpec.ExpectedRevenue();
        return sum;
    }

    public Spectacle minSalesSpec() {
        double m = morningFill / 100.0 * morningSpec.ExpectedRevenue();
        double d = dayFill / 100.0 * daySpec.ExpectedRevenue();
        double e = eveningFill / 100.0 * eveningSpec.ExpectedRevenue();

        if (m <= d && m <= e) return morningSpec;
        if (d <= m && d <= e) return daySpec;
        return eveningSpec;
    }


}
