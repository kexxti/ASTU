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
    private Spectacle morningSpec;
    private Spectacle daySpec;
    private Spectacle eveningSpec;

    private double morningFill;
    private double dayFill;
    private double eveningFill;

    private string name;

    public void Init(string n, Spectacle ms, Spectacle ds, Spectacle es,
                     double mf, double df, double ef)
    {
        name = n;
        morningSpec = ms;
        daySpec = ds;
        eveningSpec = es;
        morningFill = mf;
        dayFill = df;
        eveningFill = ef;
    }

    public void Read()
    {
        Console.Write("Enter object name: ");
        name = Console.ReadLine();

        Console.WriteLine("Morning spectacle:");
        morningSpec = new Spectacle();
        morningSpec.Read();
        Console.Write("Morning fill (%): ");
        morningFill = double.Parse(Console.ReadLine());

        Console.WriteLine("Day spectacle:");
        daySpec = new Spectacle();
        daySpec.Read();
        Console.Write("Day fill (%): ");
        dayFill = double.Parse(Console.ReadLine());

        Console.WriteLine("Evening spectacle:");
        eveningSpec = new Spectacle();
        eveningSpec.Read();
        Console.Write("Evening fill (%): ");
        eveningFill = double.Parse(Console.ReadLine());
    }

    public void Display()
    {
        Console.WriteLine("Name: " + name);

        Console.Write("Morning: ");
        morningSpec.Display();
        Console.WriteLine("Fill: " + morningFill + "%");

        Console.Write("Day: ");
        daySpec.Display();
        Console.WriteLine("Fill: " + dayFill + "%");

        Console.Write("Evening: ");
        eveningSpec.Display();
        Console.WriteLine("Fill: " + eveningFill + "%");
    }

    public double TotalSales()
    {
        double sum = 0;
        sum += morningFill / 100.0 * morningSpec.ExpectedRevenue();
        sum += dayFill / 100.0 * daySpec.ExpectedRevenue();
        sum += eveningFill / 100.0 * eveningSpec.ExpectedRevenue();
        return sum;
    }

    public Spectacle MinSalesSpec()
    {
        double m = morningFill / 100.0 * morningSpec.ExpectedRevenue();
        double d = dayFill / 100.0 * daySpec.ExpectedRevenue();
        double e = eveningFill / 100.0 * eveningSpec.ExpectedRevenue();

        if (m <= d && m <= e) return morningSpec;
        if (d <= m && d <= e) return daySpec;
        return eveningSpec;
    }
}

class Program
{
    static void Main()
    {
        Spectacle ms = new Spectacle();
        ms.Init(200.0, 25);
        Spectacle ds = new Spectacle();
        ds.Init(250.0, 40);
        Spectacle es = new Spectacle();
        es.Init(300.0, 50);

        SpectaclesPerDay monday = new SpectaclesPerDay();
        monday.Init("Monday", ms, ds, es, 90.0, 80.0, 75.0);

        SpectaclesPerDay tuesday = new SpectaclesPerDay();
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
