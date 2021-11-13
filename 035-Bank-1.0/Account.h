/* Version 0.9 */

#pragma once
#include "String.h"

class Account
{
    int id;
    String name;
    int money;

public:
    Account(int id, String name, int money);
    Account();
    Account(const Account& aref);
    Account &operator=(const Account& ref);
    virtual void AddMoney(int money);
    virtual void UserInfo() const = 0;
    void WithdrawMoney(int money);
    int CheckMoney() const;
    int CheckID() const;
};

