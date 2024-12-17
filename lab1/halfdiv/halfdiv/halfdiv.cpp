#include <cmath>
#include <clocale>
#include <iostream>
using namespace std;
double answer;
double a;
double b;
double x0;
bool rule = true;
double xi = 0;
double eps = pow(10, -6); //Точность решения
double f(double x0) //Функция нелинейного уравнения
{
    return (x0 - (1 / (3 + sin(3.6 * x0))));
}
int main()
{
    setlocale(LC_ALL, "RUS");
    cout << "Введите значение интервала [a; b] ";
    cin >> a >> b;    
    int n = 1;  
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
        }
        xi = x0;
        cout << "Промежуточное значение " << n << " = " << xi << endl; //Вывод промежуточного значения
        n++;
    }
    answer = xi;
    cout << "Корень уравнения = " << answer;
    return 0;
}