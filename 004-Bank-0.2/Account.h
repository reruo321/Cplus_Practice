#pragma once

enum {
    MAKE = 1,
    DEPOSIT = 2,
    WITHDRAW = 3,
    INFO = 4,
    EXIT = 5
};

class Account
{
    int id;
    char * name;
    int money;

public:
    Account(const int id, const char * name, const int money);
    Account();
    void AddMoney(const int money);
    void UserInfo() const;
    int CheckMoney() const;
    ~Account();
};
