#pragma once

enum {
    MAKE = 1,
    DEPOSIT = 2,
    WITHDRAW = 3,
    INFO = 4,
    EXIT = 5
};

namespace CREDIT_RANK {

    enum {
        RANK_A = 7,
        RANK_B = 4,
        RANK_C = 2
    };

}

namespace ACCOUNT_TYPE {

    enum {
        NORMAL = 1,
        HIGH_CREDIT = 2
    };

}

class Account
{
    int id;
    char * name;
    int money;

public:
    Account(int id, const char * name, int money);
    Account();
    Account(const Account& aref);
    virtual void AddMoney(int money);
    virtual void UserInfo() const = 0;
    void WithdrawMoney(int money);
    int CheckMoney() const;
    int CheckID() const;
    ~Account();
};

class NormalAccount : public Account {

    int interest;

public:
    NormalAccount(int id, const char* name, int money, int interest);
    virtual void AddMoney(int money);
    virtual void UserInfo() const;
    int GetInterest() const;
};

class HighCreditAccount : public NormalAccount {
    
    int creditRank;

public:
    HighCreditAccount(int id, const char* name, int money, int interest, int creditRank);
    virtual void AddMoney(int money);
    virtual void UserInfo() const;

};