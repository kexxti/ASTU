package task1_2;

import java.util.Scanner;

public class Angle {

    private double degree;
    private double minutes;
    private double seconds;

    private void normalize(){
        minutes += (int) seconds / 60;
        seconds = seconds % 60;

        degree += (int) minutes / 60;
        minutes = minutes % 60;
    }

    public void Init(double deg, double min, double sec) {
        degree = deg;
        minutes = min;
        seconds = sec;
        normalize();
    }

    public void Read(Scanner sc) {
        System.out.println("Введите Градусы Минуты и Секунды");
        degree = sc.nextDouble();
        minutes = sc.nextDouble();
        seconds = sc.nextDouble();
        normalize();
    }


    public void Display() {
        System.out.printf("Градусы: %.0f\tМинуты: %.0f\tСекунды: %.0f%n",
                degree, minutes, seconds);

    }

    public Angle Add(Angle a1, Angle a2) {
        Angle sum = new Angle();
        sum.degree = a1.degree + a2.degree;
        sum.minutes = a1.minutes + a2.minutes;
        sum.seconds = a1.seconds + a2.seconds;
        sum.normalize();

        return sum;
    }

    public int RoundToDegs() {
        normalize();
        if (seconds >= 30) minutes += 1;
        if (minutes >= 30) degree += 1;

        return (int)(degree);
    }



    public static void main(String[] args) {
        Angle a1 = new Angle();
        Angle a2 = new Angle();
        Angle a3 = new Angle();
        Scanner sc = new Scanner(System.in);

        a1.Init(61, 51, 41);
        a2.Read(sc);
        a3.Read(sc);

        System.out.println("Угол a1:");
        a1.Display();
        System.out.println("Угол a2:");
        a2.Display();
        System.out.println("Угол a3:");
        a3.Display();

        Angle sum = new Angle();
        sum = sum.Add(a1, a3);
        System.out.println("Сумма углов:");
        sum.Display();
        System.out.println("Сумма углов c округлением:");
        System.out.println(sum.RoundToDegs());

        // ---- Добавляем массив объектов ----
        Angle[] arr = new Angle[3];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = new Angle();
            arr[i].Init(i * 10, i * 5, i * 2); // простая инициализация
            arr[i].Display();
        }

        // ---- Суммируем функцию RoundToDegs() для всех элементов ----
        int totalDegrees = 0;
        for (int i = 0; i < arr.length; i++) {
            totalDegrees += arr[i].RoundToDegs();
        }

        System.out.println("Сумма округленных градусов всех элементов массива: " + totalDegrees);

        sc.close();
    }

}
