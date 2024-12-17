#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;
double a = 0;
double b = 0.85;
double eps = pow(10, -6);
double answer;
double x;
double xi;
bool rule = true;
double f(double x)
{
	return x - 1 / (3 + sin(3.6 * x));
}
double pf(double x)
{
	return 1 - (18 * cos((18 / 5) * x)) / (5 * pow((3 + sin((18 / 5) * x)), 2));
}
int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Введите любое значение х в интервале [0; 0.85]: ";
	cin >> x;
	if ((x >= a) && (x <= b)) { //Проверяем входит ли х в промежуток
		int n = 1;
		while (rule)
		{
			xi = x - f(x) / pf(x); //Касательная к графику
			if (abs(x - xi) <= eps) //Проверка промежуточного корня
			{
				rule = false; //Цикл завершается
			}
			else {
				x = xi; //Присваиваем новое значение, чтобы найти следующее приблизительное значение корня
				cout << "Промежуточное значение " << n << " = " << x << endl; //Вывож промежуточного значения
				n++;
			}
		}
		answer = x;
		cout << "Ответ равен: " << answer << endl;
	}
	else {
		cout << "x не входит в промежуток [0; 0.85].";
	}
	return 0;
}