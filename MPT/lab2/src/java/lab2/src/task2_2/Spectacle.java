package task2_2;

import java.util.Scanner;

public class Spectacle {

    private double ticket_price;
    private int ticket_amount;

    public void Init(double tp, int ta){
        ticket_price = tp;
        ticket_amount = ta;
    }

    public void Read(Scanner sc) {
        System.out.println("Введите Цену билета и Количество билетов");

        ticket_price = sc.nextDouble();
        ticket_amount = sc.nextInt();
    }

    public void Display() {
        System.out.printf("Цена билета: %.0f\tКоличество билетов: %d", ticket_price, ticket_amount);
    }

    public double ExpectedRevenue() {
        return ticket_amount * ticket_price;
    }

    public double GetTickPrice(){
        return  ticket_price;
    }

    public int getTickAmount() {
        return ticket_amount;
    }
}
