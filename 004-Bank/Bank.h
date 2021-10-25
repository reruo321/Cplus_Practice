#pragma once
#include "Account.h"

class Bank {

    Account** Acc = new Account*[100];
    int total_id;

public:
    Bank();
    int Menu();
    void Make();
    void Deposit();
    void Withdraw();
    void All_UserInfo();
    void ExitBank();
    ~Bank();
};