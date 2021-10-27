#pragma once
#include <iostream>

using namespace std;

class Car {

private:
	int gasolineGauge;
public:

	Car() : gasolineGauge(0) {}
	Car(const int n) : gasolineGauge(n) {}

	int GetGasGauge() {
		return gasolineGauge;
	}
};

class HybridCar : public Car {

private:
	int electricGauge;
public:
	HybridCar() :Car(0), electricGauge(0) {}
	HybridCar(const int n, const int m) : Car(n), electricGauge(m) {}

	int GetElecGauge() {
		return electricGauge;
	}
};

class HybridWaterCar :public HybridCar {

private:
	int waterGauge;
public:
	HybridWaterCar() : HybridCar(0, 0), waterGauge(0) {}
	HybridWaterCar(const int n, const int m, const int l) : HybridCar(n, m), waterGauge(l) {}

	void ShowCurrentGauge() {
		cout << "ÀÜ¿© °¡¼Ö¸°: " << GetGasGauge() << endl;
		cout << "ÀÜ¿© Àü±â·®: " << GetElecGauge() << endl;
		cout << "ÀÜ¿© ¿öÅÍ·®: " << waterGauge << endl;
	}
};