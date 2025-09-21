using System;

class Spectacle
{
    private double ticketPrice;
    private int ticketAmount;

    // Property для TicketPrice
    public double TicketPrice
    {
        get { return ticketPrice; }
        set
        {
            if (value >= 0)
                ticketPrice = value;
        }
    }

    public int TicketAmount
    {
        get { return ticketAmount; }
        set
        {
            if (value >= 0)
                ticketAmount = value;
        }
    }

    public void Init(double tp, int ta)
    {
        ticketPrice = tp;
        ticketAmount = ta;
    }

    public void Read()
    {
        Console.WriteLine("Enter Ticket price and Ticket Amount:");
        string[] parts = Console.ReadLine().Split();
        ticketPrice = double.Parse(parts[0]);
        ticketAmount = int.Parse(parts[1]);
    }

    public void Display()
    {
        Console.WriteLine($"Ticket price: {ticketPrice}\tTicket amount: {ticketAmount}");
    }

    public double ExpectedRevenue()
    {
        return ticketPrice * ticketAmount;
    }
}

class SpectaclesPerDay
{
    private Spectacle[] spectacles;   // массив спектаклей
    private double[] fills;           // массив заполнений

    private string name;

    public SpectaclesPerDay(int count)
    {
        spectacles = new Spectacle[count];
        fills = new double[count];
    }

    public void Init(string n, Spectacle[] specs, double[] fs)
    {
        name = n;
        for (int i = 0; i < spectacles.Length; i++)
        {
            spectacles[i] = specs[i];
            fills[i] = fs[i];
        }
    }

    public void Read()
    {
        Console.Write("Enter object name: ");
        name = Console.ReadLine();

        for (int i = 0; i < spectacles.Length; i++)
        {
            spectacles[i] = new Spectacle();
            Console.WriteLine($"Spectacle {i + 1}:");
            spectacles[i].Read();
            Console.Write($"Fill % for spectacle {i + 1}: ");
            fills[i] = double.Parse(Console.ReadLine());
        }
    }

    public void Display()
    {
        Console.WriteLine("Name: " + name);
        for (int i = 0; i < spectacles.Length; i++)
        {
            Console.Write($"Spectacle {i + 1}: ");
            spectacles[i].Display();
            Console.WriteLine($"Fill: {fills[i]}%");
        }
    }

    public double TotalSales()
    {
        double sum = 0;
        for (int i = 0; i < spectacles.Length; i++)
        {
            sum += fills[i] / 100.0 * spectacles[i].ExpectedRevenue();
        }
        return sum;
    }

    public Spectacle MinSalesSpec()
    {
        int minIndex = 0;
        double minValue = fills[0] / 100.0 * spectacles[0].ExpectedRevenue();

        for (int i = 1; i < spectacles.Length; i++)
        {
            double current = fills[i] / 100.0 * spectacles[i].ExpectedRevenue();
            if (current < minValue)
            {
                minValue = current;
                minIndex = i;
            }
        }
        return spectacles[minIndex];
    }
}

class Program
{
    static void Main()
    {
        Spectacle[] specs = new Spectacle[3];
        double[] fills = new double[3];

        specs[0] = new Spectacle(); specs[0].Init(200.0, 25); fills[0] = 90.0;
        specs[1] = new Spectacle(); specs[1].Init(250.0, 40); fills[1] = 80.0;
        specs[2] = new Spectacle(); specs[2].Init(300.0, 50); fills[2] = 75.0;

        SpectaclesPerDay monday = new SpectaclesPerDay(3);
        monday.Init("Monday", specs, fills);

        SpectaclesPerDay tuesday = new SpectaclesPerDay(3);
        tuesday.Read();

        monday.Display();
        Console.WriteLine("Total sales: " + monday.TotalSales());
        Console.WriteLine("Minimum sales spectacle: ");
        monday.MinSalesSpec().Display();

        tuesday.Display();
        Console.WriteLine("Total sales: " + tuesday.TotalSales());
        Console.WriteLine("Minimum sales spectacle: ");
        tuesday.MinSalesSpec().Display();
    }
}
