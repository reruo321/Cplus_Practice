#define _CRT_SECURE_NO_WARNINGS
#include "NameCard.h"
#include <string>
#include <iostream>

using namespace std;
using namespace COMP_POS;

NameCard::NameCard(const char* Name, const char* Company_Name, const char* Phone_Number, const int Comp_Pos) : comp_pos(Comp_Pos) {
	name = new char[strlen(Name) + 1];
	company_name = new char[strlen(Company_Name) + 1];
	phone_number = new char[strlen(Phone_Number) + 1];

	strcpy(name, Name);
	strcpy(company_name, Company_Name);
	strcpy(phone_number, Phone_Number);
}

/* Deep Copy */

NameCard::NameCard(const NameCard& copy) :comp_pos(copy.comp_pos) {
	name = new char[strlen(copy.name) + 1];
	company_name = new char[strlen(copy.company_name) + 1];
	phone_number = new char[strlen(copy.phone_number) + 1];

	strcpy(name, copy.name);
	strcpy(company_name, copy.company_name);
	strcpy(phone_number, copy.phone_number);
}

void NameCard::ShowCompPos() const {
	switch (comp_pos) {
	case CLERK:
		cout << "사원";
		break;
	case SENIOR:
		cout << "주임";
		break;
	case ASSIST:
		cout << "대리";
		break;
	case MANAGER:
		cout << "과장";
		break;
	}
}

void NameCard::ShowNameCardInfo() const {
	
	cout << "이름: " << name << endl;
	cout << "회사: " << company_name << endl;
	cout << "전화번호: " << phone_number << endl;
	cout << "직급: ";
	ShowCompPos();
	cout << endl << endl;

}

NameCard::~NameCard() {
	delete[]name;
	delete[]company_name;
	delete[]phone_number;
	ShowCompPos();
	cout << " 객체 소멸!" << endl;
}