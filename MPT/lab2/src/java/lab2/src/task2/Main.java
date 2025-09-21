package task2;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Spectacle ms = new Spectacle();
        ms.Init(200, 25);
        Spectacle ds = new Spectacle();
        ds.Init(250, 40);
        Spectacle es = new Spectacle();
        es.Init(300, 50);

        SpectaclesPerDay monday = new SpectaclesPerDay();
        monday.Init("Monday", ms, ds, es, 90, 80, 75);

        monday.display();
        System.out.println("Суммарные продажи: " + monday.totalSales());
        System.out.print("Наименее прибыльный спектакль: ");
        monday.minSalesSpec().Display();

        System.out.println("\nСейчас введите данные для вторника:");
        SpectaclesPerDay tuesday = new SpectaclesPerDay();
        tuesday.Read(sc);
        tuesday.display();
        System.out.println("Суммарные продажи: " + tuesday.totalSales());
        System.out.print("Наименее прибыльный спектакль: ");
        tuesday.minSalesSpec().Display();

        sc.close();
    }
}
