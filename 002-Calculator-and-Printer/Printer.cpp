#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Printer.h"

using namespace std;

void Printer::SetString(const string s) {
	str = s;
}

void Printer::ShowString() {
	cout << str << endl;
}