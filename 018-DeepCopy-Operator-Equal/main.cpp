#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Person {
	char* name;
	int age;
public:
	Person(const char* myname, int myage) {
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}

	/* TODO: Deep Copy for Operator= */

	Person& operator=(const Person& p) {
		name = new char[strlen(p.name) + 1];
		strcpy(name, p.name);
		age = p.age;
		return *this;
	}

	void ShowPersonInfo() const {
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
	}
	~Person() {
		delete[]name;
		cout << "called destructor!" << endl;
	}
};

int main() {
	Person man1("Lee dong woo", 29);
	Person man2("Yoon ji yul", 22);
	man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	return 0;
}
