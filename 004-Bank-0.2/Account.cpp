#define _CRT_SECURE_NO_WARNINGS
#include "Account.h"
#include <iostream>
#include <string>

using namespace std;

Account::Account(const int id, const char* name, const int money) : money(money) {
    this->id = id;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

Account::Account() {
    id = 0;
    this->name = NULL;
    money = 0;
}

void Account::AddMoney(const int money) {
    this->money += money;
}

int Account::CheckMoney() const {
    return this->money;
}

void Account::UserInfo() const {
    cout << "\nID: " << id << endl;
    cout << "이름: " << name << endl;
    cout << "금액: " << money << endl;
}

Account::~Account() {
    delete[]name;
}
