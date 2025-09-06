#include <iostream>
#include <cmath>

/*
   - Во всех вариантах должны быть реализованы следующие методы:
    - Метод инициализации всех полей Init;
    - ввод с клавиатуры всех полей Read;
    - вывод на экран всех полей Display;

	Поля класса должны быть закрытыми private, доступ к ним при необходимости осуществляется через открытые методы public. 

- Добавить две функции по вариантам задания для обработки объектов введенных классов. 
    - Вторую функцию назвать add, у нее два аргумента типа названного класса и она возвращает объект того же класса. <br>` Что понимается под “сложением” поясняется в задании. ` <br>
    - В main продемонстрировать работу с объектами данного класса и их методами. 
- Создать в main динамический объект и динамический массив на C++
    - Продемонстрировать варианты использования new с объектом и массивом объектов, delete, []delete для массива, вызов метода двумя способами:  ->, (*).

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
			std::cout << "Enter Degree's Minute's and Second's: ";
			std::cin >> degree >> minutes >> seconds;
			Normalize();
	}

	void  angle::Display() {
			std::cout << "Degree: " << degree << '\t' 
								<< "Minutes: " << minutes << '\t'
								<< "Seconds: " << seconds << '\n';
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
    std::cout << "Rounded sum degrees: " << sum_angle.RoundToDegs() << "\n";

    std::cout << "Demonstrate method calls:\n";
    p_angle->Display();
    (*c_angle).Display();

    angle* arr = new angle[3];
    for (int i = 0; i < 3; ++i) {
        arr[i].Init(i * 10, i * 5, i * 2);
        arr[i].Display();
    }

    delete p_angle;
    delete c_angle;
    delete[] arr;

    return 0;
}



