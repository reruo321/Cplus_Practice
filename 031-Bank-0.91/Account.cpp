/* Version 0.9 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;

Account::Account(int id, String name, int money) : money(money) {
    this->id = id;
    this->name = name;
}

Account::Account() {
    id = 0;
    this->name = NULL;
    money = 0;
}

/* Deep Copy */

Account::Account(const Account& aref) : id(aref.id), money(aref.id) {
    name = aref.name;
}

Account& Account::operator=(const Account& ref) {
    id = ref.id;
    money = ref.money;
    name = ref.name;

    return *this;
}

void Account::AddMoney(int money) {
    this->money += money;
}

void Account::WithdrawMoney(int money) {
    this->money -= money;
}

int Account::CheckMoney() const {
    return this->money;
}

int Account::CheckID() const {
    return this->id;
}

void Account::UserInfo() const {
    cout << "\nID: " << id << endl;
    cout << "이름: " << name << endl;
    cout << "금액: " << money << endl;
}
