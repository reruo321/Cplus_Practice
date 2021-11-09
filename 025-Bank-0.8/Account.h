/* Version 0.8 */

#pragma once

class Account
{
    int id;
    char * name;
    int money;

public:
    Account(int id, const char * name, int money);
    Account();
    Account(const Account& aref);
    Account &operator=(const Account& ref);
    virtual void AddMoney(int money);
    virtual void UserInfo() const = 0;
    void WithdrawMoney(int money);
    int CheckMoney() const;
    int CheckID() const;
    ~Account();
};

