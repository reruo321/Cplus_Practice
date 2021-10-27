#include "Car.h"
#include <iostream>

using namespace std;

int main() {

	Car c1;
	Car c2(1);
	
	cout << "c1�� �ܿ� ���ָ�: " << c1.GetGasGauge() << endl << endl;
	cout << "c2�� �ܿ� ���ָ�: " << c2.GetGasGauge() << endl << endl;

	HybridCar h1;
	HybridCar h2(10, 20);

	cout << "h1�� �ܿ� ���ָ�: " << h1.GetGasGauge() << endl;
	cout << "h1�� �ܿ� ���ⷮ: " << h1.GetElecGauge() << endl << endl;

	cout << "h2�� �ܿ� ���ָ�: " << h2.GetGasGauge() << endl;
	cout << "h2�� �ܿ� ���ⷮ: " << h2.GetElecGauge() << endl << endl;

	HybridWaterCar hw1;
	HybridWaterCar hw2(100, 200, 300);

	cout << "hw1�� ����:" << endl;
	hw1.ShowCurrentGauge();
	cout << endl << "hw2�� ����:" << endl;
	hw2.ShowCurrentGauge();

	return 0;
}