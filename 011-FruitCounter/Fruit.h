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
		cout << "원산지: " << country << endl;
		cout << "개수: " << number << endl;
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
		cout << "◇ 오렌지 ◇" << endl;
		ShowBaseInfo();
		cout << "반지름: " << GetRadius() << "CM" << endl;
		cout << "개당 가격: " << price << endl;
		cout << "총 가격: " << price << " x " << GetNumber() << " = " << GetPrice() << endl << endl;
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
		cout << "◆ 귤 ◆" << endl;
		ShowBaseInfo();
		cout << "반지름: " << GetRadius() << "CM" << endl;
		cout << "개당 가격: " << price << endl;
		cout << "상자 개수: " << box << endl << endl;
		cout << "총 가격: " << price << " x " << GetNumber() << " x " << box << " = " << GetPrice() << endl << endl;
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
		cout << "□ 망고 □" << endl;
		ShowBaseInfo();
		ShowSugar();
		cout << "개당 가격: " << price << endl;
		cout << "총 가격: " << price << " x " << GetNumber() << " = " << GetPrice() << endl << endl;
	}
	void ShowSugar() const {
		cout << "당도: ";
		switch (sugar) {
		case SUGAR::MIDDLE:
			cout << "중" << endl;
			break;
		case SUGAR::HIGH:
			cout << "상" << endl;
			break;
		case SUGAR::VERY_HIGH:
			cout << "최상" << endl;
			break;
		}
	}
	int GetPrice() const {
		return (price * GetNumber());
	}
};