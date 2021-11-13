/* Version 0.91 */

#pragma once

#include "BoundCheckArray.h"

class Bank {

    BoundCheckArray<Account *> Acc;
    int total_id;

public:
    Bank();
    int Menu() const;
    void Make();
    void Deposit();
    void Withdraw();
    void All_UserInfo() const;
    void ExitBank();
    ~Bank();
};