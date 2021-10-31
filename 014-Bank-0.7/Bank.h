/* Version 0.7 */

#pragma once
#include <iostream>
#include "Account.h"
#include "BankingCommonDecl.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#define BANK_SIZE 100

class Bank {

    Account** Acc = new Account*[BANK_SIZE];
    int total_id;

public:
    Bank();
    Bank(const Bank& bref);
    int Menu() const;
    void Make();
    void Deposit();
    void Withdraw();
    void All_UserInfo() const;
    void ExitBank();
    ~Bank();
};