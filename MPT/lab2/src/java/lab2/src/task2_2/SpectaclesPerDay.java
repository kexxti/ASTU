package task2_2;

import java.util.Scanner;

public class SpectaclesPerDay {
    private Spectacle[] spectacles;
    private double[] fills;
    private String name;

    // вместо конструктора
    public void InitArray(int count) {
        spectacles = new Spectacle[count];
        fills = new double[count];
    }

    public void Init(String n, Spectacle[] specs, double[] fs) {
        name = n;
        for (int i = 0; i < spectacles.length; i++) {
            spectacles[i] = specs[i];
            fills[i] = fs[i];
        }
    }

    public void Read(Scanner sc) {
        sc.nextLine(); // убрать лишний перевод строки
        System.out.print("Введите имя объекта: ");
        name = sc.nextLine();

        for (int i = 0; i < spectacles.length; i++) {
            spectacles[i] = new Spectacle();
            System.out.println("Спектакль " + (i + 1) + ":");
            spectacles[i].Read(sc);
            System.out.print("Заполняемость (%) для спектакля " + (i + 1) + ": ");
            fills[i] = sc.nextDouble();
        }
    }

    public void Display() {
        System.out.println("Имя: " + name);
        for (int i = 0; i < spectacles.length; i++) {
            System.out.print("Спектакль " + (i + 1) + ": ");
            spectacles[i].Display();
            System.out.println("Заполняемость: " + fills[i] + "%");
        }
    }

    public double TotalSales() {
        double sum = 0;
        for (int i = 0; i < spectacles.length; i++) {
            sum += fills[i] / 100.0 * spectacles[i].ExpectedRevenue();
        }
        return sum;
    }

    public Spectacle MinSalesSpec() {
        int minIndex = 0;
        double minValue = fills[0] / 100.0 * spectacles[0].ExpectedRevenue();

        for (int i = 1; i < spectacles.length; i++) {
            double current = fills[i] / 100.0 * spectacles[i].ExpectedRevenue();
            if (current < minValue) {
                minValue = current;
                minIndex = i;
            }
        }
        return spectacles[minIndex];
    }
}
