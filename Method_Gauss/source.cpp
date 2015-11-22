#include <iostream>
#define _USE_MATH_DEFINES
#include "ATLComTime.h"
#include <cmath>
using namespace std;
//составим функцию, реализующую 
//подинтегральное выражение e^(cos(x))*sin(x)
double func(double x){
	double f = exp(cos(x))*sin(x);
	return f;
}
//функция, реализующая приближенное вычисление
//по методу Гаусса, на вход подаются границы интегрирования
void IntegrationGauss(double a, double b){
	//точное значение используем для сравнения
	double true_I = 1.7183;
	cout << "границы интеграрования: " << "[" << a << ", " << b << "]" << endl;
	//находим интеграл по формуле Гаусса
	double I =
		(b - a) / 2 *
		(func((a + b) / 2 - (b - a) / (2 * sqrt(3))) +
		func((a + b) / 2 + (b - a) / (2 * sqrt(3))));
	cout << "найден ответ = " << I << endl;
	cout<<"с погрешностью = " << fabs((true_I - I) * 100 / true_I) << endl;
}
int main(){
	setlocale(LC_ALL, "ru");
	cout.precision(4);
	cout.setf(ios::fixed);
	IntegrationGauss(0, M_PI / 2);
	return 0;
}