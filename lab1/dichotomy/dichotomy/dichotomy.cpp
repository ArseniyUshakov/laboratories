#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

double f(double x0) //Функция нелинейного уравнения
{
	return (x0 - (1 / (3 + sin(3.6 * x0))));
}
double dichotomy(double a, double b)
{
	double x0;
	double xi = 0;
	double eps = pow(10, -6); //Точность решения
	bool rule = true;
    while (rule)
    {
        x0 = (a + b) / 2;
        if (abs(x0 - xi) <= eps) //Проверка промежуточного значения корня
        {
           rule = false; //Завершаем цикл половинчатого деления
        }
        if (f(x0) * f(a) < 0) //Проверка на какой половине есть корень
        {
            b = x0;
        }
        else
        {
            a = x0;
            xi = x0;
            cout << "Промежуточное значение = " << xi << endl; //Вывод промежуточного значения
        }
    }
    return x0;
}
int main()
{
    setlocale(LC_ALL, "RUS");
    double answer;
    double a = 0;
    double b = 0.85;
    answer = dichotomy(a, b);
    cout << "Корень уравнения = " << answer;
    return 0;
}