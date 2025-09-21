#include <iostream>
#include <cstring>

/*
- Задания выполняются на C++ в виде консольного приложения

- Реализовать вспомогательный класс по варианту задания с указанными полями и методами.
- Создать основной класс по варианту задания, полями которого являются 3 объекта вспомогательного 
класса.  Реализовать указанные методы. 
- В main продемонстрировать использование объектов основного и вспомогательного класса. 
- В основном классе должно быть строковое поле название объекта в виде массива char. 
- Во всех вариантах должны быть реализованы следующие методы для основного и вспомогательного класса:
    - Метод инициализации Init;
    - Ввод с клавиатуры Read;
    - Вывод на экран Display.

### Вариант 6

**Спектакль** имеет *два поля*: 
- вещественное – цена билета 
- целое – количество билетов, переданное в кассы. 

Реализовать метод вычисления общей ожидаемой сумы продаж. 

**Основной класс спектакли за день** имеет:
- Три поля спектакль (утренний, дневной и вечерний) 
- Три поля:
    - процент заполнения партера на спектаклях. 

- Определить методы:
    - Вычисляющие сумму денег от продажи билетов за день
    - Возвращающий спектакль с минимальной ожидаемой суммы продаж.
*/


class spectacle {
private:
	double ticket_price;
	int ticket_amount;
public:

	void Init(double tp, int ta);
	void Read();
	void Display();

	double ExpectedRevenue();

	double GetTickPrice();
	int GetTickAmount();
};

void spectacle::Init(double tp, int ta){
	ticket_price = tp;
	ticket_amount = ta;
}
void spectacle::Read(){
	std::cout << "Enter Ticket price and Ticket Amount" << '\n';
	std::cin >> ticket_price >> ticket_amount;
}
void spectacle::Display(){
	std::cout << "Ticket price: " << ticket_price << '\t'
			  << "Ticket amount: " << ticket_amount << '\n';
}

double spectacle::GetTickPrice(){
	return ticket_price;
}
int spectacle::GetTickAmount(){
	return ticket_amount;
}

double spectacle::ExpectedRevenue(){
	return ticket_price * ticket_amount;
}


class spectaclesPerDay {
private:

	spectacle morning_spec;
	spectacle day_spec;
	spectacle evening_spec;

	double morning_fill;
	double day_fill;
	double evening_fill;

	char name[100];


public:
	void Init(const char* name, spectacle ms, spectacle ds, spectacle es, \
						double mf, double df, double ef);
	void Read();
	void Display();

	double TotalSales();
	spectacle MinSalesSpec();
};


using spd = spectaclesPerDay;




void spd::Init(const char* n, spectacle ms, spectacle ds, spectacle es, \
               double mf, double df, double ef) {
    strncpy(name, n, sizeof(name)-1);
    name[sizeof(name)-1] = '\0';
    morning_spec = ms;
    day_spec = ds;
    evening_spec = es;
    morning_fill = mf;
    day_fill = df;
    evening_fill = ef;
}

void spd::Read() {
    std::cout << "Enter object name: ";
    std::cin.getline(name, sizeof(name));
    std::cout << "Morning spectacle:\n";
    morning_spec.Read();
    std::cout << "Morning fill (%): ";
    std::cin >> morning_fill;
    std::cout << "Day spectacle:\n";
    day_spec.Read();
    std::cout << "Day fill (%): ";
    std::cin >> day_fill;
    std::cout << "Evening spectacle:\n";
    evening_spec.Read();
    std::cout << "Evening fill (%): ";
    std::cin >> evening_fill;
    std::cin.ignore();
}

void spd::Display() {
    std::cout << "Name: " << name << '\n';
    std::cout << "Morning: "; morning_spec.Display();
    std::cout << "Fill: " << morning_fill << "%\n";
    std::cout << "Day: "; day_spec.Display();
    std::cout << "Fill: " << day_fill << "%\n";
    std::cout << "Evening: "; evening_spec.Display();
    std::cout << "Fill: " << evening_fill << "%\n";
}

double spd::TotalSales() {
    double sum = 0;
    sum += morning_fill / 100 * morning_spec.ExpectedRevenue();
    sum += day_fill / 100 * day_spec.ExpectedRevenue();
    sum += evening_fill / 100 * evening_spec.ExpectedRevenue();
    return sum;
}

spectacle spd::MinSalesSpec() {
    double m = morning_fill / 100 * morning_spec.ExpectedRevenue();
    double d = day_fill / 100 * day_spec.ExpectedRevenue();
    double e = evening_fill / 100 * evening_spec.ExpectedRevenue();

    if (m <= d && m <= e) return morning_spec;
    if (d <= m && d <= e) return day_spec;
    return evening_spec;
}


int main(){
    spectacle ms, ds, es;
    ms.Init(200.0, 25);
    ds.Init(250.0, 40);
    es.Init(300.0, 50);

    spd monday;
    monday.Init("Monday", ms, ds, es, 90.0, 80.0, 75.0);
    spd tuesday;
    tuesday.Read();

    monday.Display();
    std::cout << "Total sales: " << monday.TotalSales() << "\n";
    std::cout << "Minimum sales spectacle: ";
    monday.MinSalesSpec().Display();

    tuesday.Display();
    std::cout << "Total sales: " << tuesday.TotalSales() << "\n";
    std::cout << "Minimum sales spectacle: ";
    tuesday.MinSalesSpec().Display();
    return 0;
}


