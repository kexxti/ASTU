/*
- Задания выполняются на C++ в виде консольного приложения

- Реализовать вспомогательный класс по варианту задания с указанными полями и методами.
- Создать основной класс по варианту задания, полями которого являются 3 объекта вспомогательного класса.  Реализовать указанные методы. 
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

	double ExpectedRevenue(double tp, int ta);

	double GetTickPrice();
	int GetTickAmount();
};




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

int main(){



	return 0;
}

