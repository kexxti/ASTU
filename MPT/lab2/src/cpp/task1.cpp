#include <iostream>
#include <cmath>

/*
   - Во всех вариантах должны быть реализованы следующие методы:
    - Метод инициализации всех полей Init;
    - ввод с клавиатуры всех полей Read;
    - вывод на экран всех полей Display;

	Поля класса должны быть закрытыми private, доступ к ним при необходимости осуществляется 
  через открытые методы public. 

- Добавить две функции по вариантам задания для обработки объектов введенных классов. 
    - Вторую функцию назвать add, у нее два аргумента типа названного класса и 
    она возвращает объект того же класса. <br>` Что понимается под “сложением” поясняется в задании. 
    ` <br>
    - В main продемонстрировать работу с объектами данного класса и их методами. 
- Создать в main динамический объект и динамический массив на C++
    - Продемонстрировать варианты использования new с объектом и массивом объектов, delete,
     []delete для массива, вызов метода двумя способами:  ->, (*).

		Вариант 6
		**Класс *УГОЛ*** для работы с углами на плоскости, определяется тремя вещественными параметрами: 
- градусы  
- минуты  
- секунды 

Должны быть реализованы методы: 
- Округление до градусов
- Сложение углов.

1 deg = 60 min = 60*60 sec
*/

class angle {
private:
  double degree;
  double minutes;
  double seconds;

	void Normalize();

public:
	void Init(double deg, double min, double sec);
	void Read();
  void Display();
	angle Add(angle a1, angle a2);
	int RoundToDegs();

};

  void angle::Normalize() {
        // Перевод секунд в минуты
        minutes += static_cast<int>(seconds) / 60;
        seconds = fmod(seconds, 60);
        // Перевод минут в градусы
        degree += static_cast<int>(minutes) / 60;
        minutes = fmod(minutes, 60);
    }


	void angle::Init(double deg, double min, double sec) {
			degree = deg;
			minutes = min;
			seconds = sec;
			Normalize();
	}

	void angle::Read() {
			std::cout << "Введите Градусы Минуты и Секунды: ";
			std::cin >> degree >> minutes >> seconds;
			Normalize();
	}

	void  angle::Display() {
			std::cout << "Градусы: " << degree << '\t' 
								<< "Минуты: " << minutes << '\t'
								<< "Секунды: " << seconds << '\n';
	}

	angle angle::Add(angle a1, angle a2) {
			angle sum;
			sum.degree = a1.degree + a2.degree;
			sum.minutes = a1.minutes + a2.minutes;
			sum.seconds = a1.seconds + a2.seconds;
			sum.Normalize();
			return sum;
	}

	int angle::RoundToDegs() {
		Normalize(); // Сначала нормализуем значения (секунды и минуты не больше 60)

    if (seconds >= 30) minutes += 1;
    if (minutes >= 30) degree += 1;

    return static_cast<int>(degree);
	}

int main() {
    angle* p_angle = new angle;
    angle* c_angle = new angle;
    angle easy_angle;

    p_angle->Init(10, 20, 30);
    c_angle->Init(5, 40, 40);
    easy_angle.Read();

    angle sum_angle = sum_angle.Add(*p_angle, *c_angle);
    std::cout << "Sum of angles:\n";
    sum_angle.Display();
    std::cout << "Округленная сумма: " << sum_angle.RoundToDegs() << "\n";

    std::cout << "Вызов метода Display:\n";
    p_angle->Display();
    (*c_angle).Display();

    angle* arr = new angle[3];
    for (int i = 0; i < 3; ++i) {
        arr[i].Init(i * 10, i * 5, i * 2);
        arr[i].Display();
    }

    // ---------------------------
    // Статический массив объектов
    // ---------------------------
    std::cout << "\nСтатический массив объектов:\n";
    angle staticArr[3];
    for (int i = 0; i < 3; ++i) {
        staticArr[i].Init(i * 15, i * 10, i * 5);
        staticArr[i].Display();
    }

    // Суммирование всех углов из статического массива
    angle total_static = staticArr[0];
    for (int i = 1; i < 3; ++i) {
        total_static = total_static.Add(total_static, staticArr[i]);
    }
    std::cout << "Сумма всех углов статического массива:\n";
    total_static.Display();

    // ---------------------------
    // Динамический массив объектов
    // ---------------------------
    std::cout << "\nДинамический массив объектов:\n";
    int n = 3;
    angle* dynArr = new angle[n];
    for (int i = 0; i < n; ++i) {
        dynArr[i].Init(i * 20, i * 5, i * 15);
        dynArr[i].Display();
    }

    // Суммирование всех углов из динамического массива
    angle total_dynamic = dynArr[0];
    for (int i = 1; i < n; ++i) {
        total_dynamic = total_dynamic.Add(total_dynamic, dynArr[i]);
    }
    std::cout << "Сумма всех углов динамического массива:\n";
    total_dynamic.Display();

    // Очистка памяти
    delete p_angle;
    delete c_angle;
    delete[] dynArr;

    return 0;
}



