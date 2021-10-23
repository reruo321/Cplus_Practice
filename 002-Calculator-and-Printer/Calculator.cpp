#include <iostream>
#include "Calculator.h"

using namespace std;

void Calculator::Init() {
	add = 0;
	sub = 0;
	mul = 0;
	div = 0;
}

double Calculator::Add(double a, double b) {
	add++;
	return a + b;
}

double Calculator::Sub(double a, double b) {
	sub++;
	return a - b;
}

double Calculator::Mul(double a, double b) {
	mul++;
	return a * b;
}

double Calculator::Div(double a, double b) {
	div++;
	return a / b;
}

void Calculator::ShowOpCount() {
	cout << "µ¡¼À: " << add;
	cout << " »¬¼À: " << sub;
	cout << " °ö¼À: " << mul;
	cout << " ³ª´°¼À: " << div << endl;
}