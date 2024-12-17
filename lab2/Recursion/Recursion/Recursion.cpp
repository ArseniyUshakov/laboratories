#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;
int n;
double x, s;
double pow(double x, int n)
{
	if (n == 0)
		return 1;
	return (x * pow(x, n - 1));
}
double recursion(double x, int n)
{
	if (n == 0)
		return x;
	return ((pow(x, 4 * n + 1) / (4 * n + 1)) + recursion(x, n - 1));
}
int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Введите значение n и x через пробел ";
	cin >> n >> x;
		s = recursion(x, n);
		cout << "S = " << s << endl;
		return 0;
}