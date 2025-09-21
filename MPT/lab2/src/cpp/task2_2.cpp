#include <iostream>
#include <cstring>

class spectacle {
private:
    double ticket_price;
    int ticket_amount;
public:
    void Init(double tp, int ta) {
        ticket_price = tp;
        ticket_amount = ta;
    }
    void Read() {
        std::cout << "Enter Ticket price and Ticket Amount\n";
        std::cin >> ticket_price >> ticket_amount;
    }
    void Display() {
        std::cout << "Ticket price: " << ticket_price << '\t'
                  << "Ticket amount: " << ticket_amount << '\n';
    }
    double ExpectedRevenue() { return ticket_price * ticket_amount; }
};

class spectaclesPerDay {
private:
    spectacle* specs;  // динамический массив спектаклей
    double* fill;      // динамический массив заполнения
    int count;         // количество спектаклей
    char name[100];
public:
    spectaclesPerDay(int n = 3) {
        count = n;
        specs = new spectacle[n];
        fill = new double[n];
    }
    ~spectaclesPerDay() {
        delete[] specs;
        delete[] fill;
    }

    void Init(const char* n, spectacle s[], double f[], int nCount) {
        count = nCount;
        strncpy(name, n, sizeof(name)-1);
        name[sizeof(name)-1] = '\0';
        for (int i = 0; i < count; i++) {
            specs[i] = s[i];
            fill[i] = f[i];
        }
    }

    void Read() {
        std::cout << "Enter object name: ";
        std::cin.getline(name, sizeof(name));
        for (int i = 0; i < count; i++) {
            std::cout << "Spectacle #" << i+1 << ":\n";
            specs[i].Read();
            std::cout << "Fill (%): ";
            std::cin >> fill[i];
        }
        std::cin.ignore();
    }

    void Display() {
        std::cout << "Name: " << name << "\n";
        for (int i = 0; i < count; i++) {
            std::cout << "Spectacle #" << i+1 << ": ";
            specs[i].Display();
            std::cout << "Fill: " << fill[i] << "%\n";
        }
    }

    double TotalSales() {
        double sum = 0;
        for (int i = 0; i < count; i++) {
            sum += fill[i] / 100.0 * specs[i].ExpectedRevenue();
        }
        return sum;
    }

    spectacle MinSalesSpec() {
        int minIndex = 0;
        double minValue = fill[0] / 100.0 * specs[0].ExpectedRevenue();
        for (int i = 1; i < count; i++) {
            double val = fill[i] / 100.0 * specs[i].ExpectedRevenue();
            if (val < minValue) {
                minValue = val;
                minIndex = i;
            }
        }
        return specs[minIndex];
    }
};

int main() {
    spectacle s[3];
    s[0].Init(200.0, 25);
    s[1].Init(250.0, 40);
    s[2].Init(300.0, 50);
    double f[3] = {90.0, 80.0, 75.0};

    spectaclesPerDay monday(3);
    monday.Init("Monday", s, f, 3);

    monday.Display();
    std::cout << "Total sales: " << monday.TotalSales() << "\n";
    std::cout << "Minimum sales spectacle: ";
    monday.MinSalesSpec().Display();

    return 0;
}
