#define _CRT_SECURE_NO_WARNINGS
#include "Account.h"
#include <iostream>
#include <string>

using namespace std;

Account::Account(int id, const char* name, int money) : money(money) {
    this->id = id;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

Account::Account() {
    id = 0;
    this->name = NULL;
    money = 0;
}

/* Deep Copy */

Account::Account(const Account& aref) : id(aref.id), money(aref.id) {
    name = new char[strlen(aref.name) + 1];
    strcpy(name, aref.name);
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

Account::~Account() {
    delete[]name;
}

NormalAccount::NormalAccount(int id, const char* name, int money, int interest) : Account(id, name, money), interest(interest) {}

void NormalAccount::AddMoney(int money) {
    Account::AddMoney(money);
    Account::AddMoney((int) (money * (interest / 100.0) ));
}

void NormalAccount::UserInfo() const {
    Account::UserInfo();
    cout << "이자율: " << interest << endl;
}

int NormalAccount::GetInterest() const {
    return this->interest;
}

HighCreditAccount::HighCreditAccount(int id, const char* name, int money, int interest, int creditRank): NormalAccount(id, name, money, interest), creditRank(creditRank){}

void HighCreditAccount::AddMoney(int money) {
    NormalAccount::AddMoney(money);
    Account::AddMoney((int) (money * (creditRank / 100.0) ));
}

void HighCreditAccount::UserInfo() const {
    NormalAccount::UserInfo();

    switch (creditRank) {
    case CREDIT_RANK::RANK_A:
        cout << "신용등급: A" << endl;
        break;
    case CREDIT_RANK::RANK_B:
        cout << "신용등급: B" << endl;
        break;
    case CREDIT_RANK::RANK_C:
        cout << "신용등급: C" << endl;
        break;
    }

}