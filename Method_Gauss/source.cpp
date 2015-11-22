#include <iostream>
#define _USE_MATH_DEFINES
#include "ATLComTime.h"
#include <cmath>
using namespace std;
//�������� �������, ����������� 
//��������������� ��������� e^(cos(x))*sin(x)
double func(double x){
	double f = exp(cos(x))*sin(x);
	return f;
}
//�������, ����������� ������������ ����������
//�� ������ ������, �� ���� �������� ������� ��������������
void IntegrationGauss(double a, double b){
	//������ �������� ���������� ��� ���������
	double true_I = 1.7183;
	cout << "������� ��������������: " << "[" << a << ", " << b << "]" << endl;
	//������� �������� �� ������� ������
	double I =
		(b - a) / 2 *
		(func((a + b) / 2 - (b - a) / (2 * sqrt(3))) +
		func((a + b) / 2 + (b - a) / (2 * sqrt(3))));
	cout << "������ ����� = " << I << endl;
	cout<<"� ������������ = " << fabs((true_I - I) * 100 / true_I) << endl;
}
int main(){
	setlocale(LC_ALL, "ru");
	cout.precision(4);
	cout.setf(ios::fixed);
	IntegrationGauss(0, M_PI / 2);
	return 0;
}