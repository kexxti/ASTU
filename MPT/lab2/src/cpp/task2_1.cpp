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
        std::cout << "Введите цену билета и количество билетов\n";
        std::cin >> ticket_price >> ticket_amount;
    }
    void Display() {
        std::cout << "Цена билета: " << ticket_price << '\t'
                  << "Количество билетов: " << ticket_amount << '\n';
    }
    double ExpectedRevenue() { return ticket_price * ticket_amount; }
};

class spectaclesPerDay {
private:
    spectacle specs[3];   // 3 спектакля
    double fill[3];       // проценты заполнения
    char name[100];
public:
    void Init(const char* n, spectacle s[3], double f[3]) {
        
        strncpy(name, n, sizeof(name)-1);
        
        name[sizeof(name)-1] = '\0';
        
        for (int i = 0; i < 3; i++) {
            specs[i] = s[i];
            fill[i] = f[i];
        }
    }

    void Read() {
        std::cout << "Введите имя объекта: ";
        std::cin.getline(name, sizeof(name));
        for (int i = 0; i < 3; i++) {
            std::cout << "Спектакль #" << i+1 << ":\n";
            specs[i].Read();
            std::cout << "Посещаемость (%): ";
            std::cin >> fill[i];
        }
        std::cin.ignore();
    }

    void Display() {
        std::cout << "Имя: " << name << "\n";
        for (int i = 0; i < 3; i++) {
            std::cout << "Спектакль #" << i+1 << ": ";
            specs[i].Display();
            std::cout << "Посещаемость: " << fill[i] << "%\n";
        }
    }

    double TotalSales() {
        double sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += fill[i] / 100.0 * specs[i].ExpectedRevenue();
        }
        return sum;
    }

    spectacle MinSalesSpec() {
        int minIndex = 0;
        double minValue = fill[0] / 100.0 * specs[0].ExpectedRevenue();
        for (int i = 1; i < 3; i++) {
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

    spectaclesPerDay monday;
    monday.Init("Monday", s, f);

    monday.Display();
    std::cout << "Сумма продаж: " << monday.TotalSales() << "\n";
    std::cout << "Наименее прибыльный спектакль: ";
    monday.MinSalesSpec().Display();

    return 0;
}
