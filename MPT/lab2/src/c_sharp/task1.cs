using System;

class Angle
{
    private double degree;
    private double minutes;
    private double seconds;

    // Свойство для доступа к seconds (пример property)
    public double Seconds
    {
        get { return seconds; }
        set
        {
            if (value >= 0)
            {
                seconds = value;
                Normalize();
            }
        }
    }

    private void Normalize()
    {
        // Перевод секунд в минуты
        minutes += (int)(seconds / 60);
        seconds = seconds % 60;

        // Перевод минут в градусы
        degree += (int)(minutes / 60);
        minutes = minutes % 60;
    }

    public void Init(double deg, double min, double sec)
    {
        degree = deg;
        minutes = min;
        seconds = sec;
        Normalize();
    }

    public void Read()
    {
        Console.Write("Введите Градусы Минуты и Секунды: ");
        string[] parts = Console.ReadLine().Split();
        degree = double.Parse(parts[0]);
        minutes = double.Parse(parts[1]);
        seconds = double.Parse(parts[2]);
        Normalize();
    }

    public void Display()
    {
        Console.WriteLine($"Градусы: {degree}\tМинуты: {minutes}\tСекунды: {seconds}");
    }

    public Angle Add(Angle a1, Angle a2)
    {
        Angle sum = new Angle();
        sum.degree = a1.degree + a2.degree;
        sum.minutes = a1.minutes + a2.minutes;
        sum.seconds = a1.seconds + a2.seconds;
        sum.Normalize();
        return sum;
    }

    public int RoundToDegs()
    {
        Normalize();

        if (seconds >= 30) minutes += 1;
        if (minutes >= 30) degree += 1;

        return (int)degree;
    }
}

class Program
{
    static void Main()
    {
        Angle pAngle = new Angle();
        Angle cAngle = new Angle();
        Angle easyAngle = new Angle();

        pAngle.Init(10, 20, 30);
        cAngle.Init(5, 40, 40);
        easyAngle.Read();

        Angle sumAngle = sumAngle = sumAngle.Add(pAngle, cAngle);
        Console.WriteLine("Sum of angles:");
        sumAngle.Display();
        Console.WriteLine("Округленная сумма: " + sumAngle.RoundToDegs());

        Console.WriteLine("Вызов метода Display:");
        pAngle.Display();
        cAngle.Display();

        Angle[] arr = new Angle[3];
        for (int i = 0; i < 3; i++)
        {
            arr[i] = new Angle();
            arr[i].Init(i * 10, i * 5, i * 2);
            arr[i].Display();
        }

    }
}
