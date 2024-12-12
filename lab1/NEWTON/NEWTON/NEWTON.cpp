#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;
double f1(double x0)
{
	bool rule = true;
	double eps = pow(10, -6); //Точность вычисления
	double xi;
	while (rule) {
		xi = x0 - (x0 - (1 / (3 + sin(3.6 * x0)))) / (1 + (18 * cos((18 / 5) * x0)) / (5 * pow((3 - sin((18 / 5) * x0)), 2))); //Касательная к графику
		if (abs(x0 - xi) <= eps) //Проверка промежуточного корня
		{
			rule = false; //Цикл завершается
		}
		else {
			x0 = xi; //Присваиваем новое значение, чтобы найти следующее приблизительное значение корня
			cout << "Промежуточное значение = " << x0 << endl; //Вывож промежуточного значения
		}
	}
	return xi;
}
int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Введите любой х, входящий в промежуток [0; 0.85]: ";
	double x0, answer;
	double a = 0;
	double b = 0.85;
	cin >> x0;
	if ((x0 >= a) && (x0 <= b)) { //Проверяем входит ли х в промежуток
		answer = f1(x0);
		cout << "Ответ равен: " << answer << endl;
	}
	else {
		cout << "x не входит в промежуток [0; 0.85].";
	}
	return 0;
}