#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

namespace SUGAR {
	enum {
		MIDDLE = 0,
		HIGH = 2,
		VERY_HIGH = 5,
	};
}

class Fruit {
	char country[20];
	int number;
public:
	Fruit(const char* country, int number): number(number) {
		strcpy(this->country, country);
	}
	void ShowBaseInfo() const {
		cout << "������: " << country << endl;
		cout << "����: " << number << endl;
	}
	void AddFruit(int add) {
		number += add;
	}
	int GetNumber() const {
		return number;
	}
	virtual int GetPrice() const = 0;
	virtual void ShowInfo() const = 0;
};

class Orange: public Fruit {
	int price;
	int radius;
public:
	Orange(const char * country, int number, int radius): Fruit(country, number), price(1000), radius(radius){}
	void ShowInfo() const {
		cout << "�� ������ ��" << endl;
		ShowBaseInfo();
		cout << "������: " << GetRadius() << "CM" << endl;
		cout << "���� ����: " << price << endl;
		cout << "�� ����: " << price << " x " << GetNumber() << " = " << GetPrice() << endl << endl;
	}
	int GetRadius() const {
		return radius;
	}
	int GetPrice() const {
		return price * GetNumber();
	}
};

class Gyul : public Orange {
	int price;
	int box;
public:
	Gyul(const char * country, int number, int radius, int box): Orange(country, number, radius), box(box), price(400){}
	void ShowInfo() const {
		cout << "�� �� ��" << endl;
		ShowBaseInfo();
		cout << "������: " << GetRadius() << "CM" << endl;
		cout << "���� ����: " << price << endl;
		cout << "���� ����: " << box << endl << endl;
		cout << "�� ����: " << price << " x " << GetNumber() << " x " << box << " = " << GetPrice() << endl << endl;
	}
	void AddBox(int add) {
		box += add;
	}
	int GetPrice() const {
		return price * GetNumber() * box;
	}
};

class Mango : public Fruit {
	int price;
	int sugar;
public:
	Mango(const char* country, int number, int sugar) : Fruit(country, number), sugar(sugar), price((int)(1600 * (1 + (0.1 * sugar))) ){}

	void ShowInfo() const {
		cout << "�� ���� ��" << endl;
		ShowBaseInfo();
		ShowSugar();
		cout << "���� ����: " << price << endl;
		cout << "�� ����: " << price << " x " << GetNumber() << " = " << GetPrice() << endl << endl;
	}
	void ShowSugar() const {
		cout << "�絵: ";
		switch (sugar) {
		case SUGAR::MIDDLE:
			cout << "��" << endl;
			break;
		case SUGAR::HIGH:
			cout << "��" << endl;
			break;
		case SUGAR::VERY_HIGH:
			cout << "�ֻ�" << endl;
			break;
		}
	}
	int GetPrice() const {
		return (price * GetNumber());
	}
};