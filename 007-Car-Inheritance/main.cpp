#include "Car.h"
#include <iostream>

using namespace std;

int main() {

	Car c1;
	Car c2(1);
	
	cout << "c1의 잔여 가솔린: " << c1.GetGasGauge() << endl << endl;
	cout << "c2의 잔여 가솔린: " << c2.GetGasGauge() << endl << endl;

	HybridCar h1;
	HybridCar h2(10, 20);

	cout << "h1의 잔여 가솔린: " << h1.GetGasGauge() << endl;
	cout << "h1의 잔여 전기량: " << h1.GetElecGauge() << endl << endl;

	cout << "h2의 잔여 가솔린: " << h2.GetGasGauge() << endl;
	cout << "h2의 잔여 전기량: " << h2.GetElecGauge() << endl << endl;

	HybridWaterCar hw1;
	HybridWaterCar hw2(100, 200, 300);

	cout << "hw1의 정보:" << endl;
	hw1.ShowCurrentGauge();
	cout << endl << "hw2의 정보:" << endl;
	hw2.ShowCurrentGauge();

	return 0;
}