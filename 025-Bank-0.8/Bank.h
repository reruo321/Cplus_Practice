/* Version 0.8 */

#pragma once

#include "AccountArray.h"

class Bank {

    BoundCheckAccountPtrArray Acc;
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