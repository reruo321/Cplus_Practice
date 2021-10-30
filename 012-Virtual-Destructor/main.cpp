#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Dog {
	char* a;
public:
	Dog(const char* a) {
		this->a = new char[strlen(a) + 1];
		strcpy(this->a, a);
		cout << "Bark Bark!" << endl;
	}
	~Dog() {
		cout << "Bye-Bye Dog~" << endl;
		delete []a;
	}
};

class Poodle: public Dog {
	char* b;
public:
	Poodle(const char* a, const char * b): Dog(a) {
		this->b = new char[strlen(b) + 1];
		strcpy(this->b, b);
		cout << "I am Poodle." << endl;
	}
	~Poodle() {
		cout << "See Ya Poodle ~ ~ ~" << endl;
		delete[]b;
	}
};

class Dessert {
	char* a;
public:
	Dessert(const char* a) {
		this->a = new char[strlen(a) + 1];
		strcpy(this->a, a);
		cout << "Sweety Dessert!" << endl;
	}
	virtual ~Dessert() {
		cout << "Yummy Dessert~" << endl;
		delete[]a;
	}
};

class Pudding : public Dessert {
	char* b;
public:
	Pudding(const char* a, const char* b) : Dessert(a) {
		this->b = new char[strlen(b) + 1];
		strcpy(this->b, b);
		cout << "Boing-Boing Pudding!" << endl;
	}
	~Pudding() {
		cout << "Tasty Pudding ~ ~ ~" << endl;
		delete[]b;
	}
};

int main() {

	Dog* dog = new Poodle("a", "b");
	cout << endl;
	delete dog;
	cout << endl;
	Dessert* dessert = new Pudding("a", "b");
	cout << endl;
	delete dessert;
	cout << endl;

	return 0;
}