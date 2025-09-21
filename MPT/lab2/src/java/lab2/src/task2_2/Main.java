package task2_2;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Spectacle[] specs = new Spectacle[3];
        double[] fills = new double[3];

        specs[0] = new Spectacle(); specs[0].Init(200.0, 25); fills[0] = 90.0;
        specs[1] = new Spectacle(); specs[1].Init(250.0, 40); fills[1] = 80.0;
        specs[2] = new Spectacle(); specs[2].Init(300.0, 50); fills[2] = 75.0;

        SpectaclesPerDay monday = new SpectaclesPerDay();
        monday.InitArray(3); // инициализация массива
        monday.Init("Monday", specs, fills);

        SpectaclesPerDay tuesday = new SpectaclesPerDay();
        tuesday.InitArray(3);
        tuesday.Read(sc);

        monday.Display();
        System.out.println("Суммарные продажи: " + monday.TotalSales());
        System.out.println("Наименее прибыльный спектакль:");
        monday.MinSalesSpec().Display();

        tuesday.Display();
        System.out.println("Суммарные продажи: " + tuesday.TotalSales());
        System.out.println("Наименее прибыльный спектакль:");
        tuesday.MinSalesSpec().Display();

        sc.close();
    }
}
