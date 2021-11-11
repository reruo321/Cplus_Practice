/* Version 0.9 */
#pragma once
#include <iostream>
#include "Account.h"

using namespace std;

class NormalAccount : public Account {

    int interest;

public:

    NormalAccount(int id, String name, int money, int interest) : Account(id, name, money), interest(interest) {}

    void AddMoney(int money) {
        Account::AddMoney(money);
        Account::AddMoney((int)(money * (interest / 100.0)));
    }

    void UserInfo() const {
        Account::UserInfo();
        cout << "ÀÌÀÚÀ²: " << interest << endl;
    }

    int GetInterest() const {
        return this->interest;
    }

};
