/* Version 0.9 */

#pragma once
#include "NormalAccount.h"
#include "BankingCommonDecl.h"

class HighCreditAccount : public NormalAccount {

    int creditRank;

public:

    HighCreditAccount(int id, String name, int money, int interest, int creditRank) : NormalAccount(id, name, money, interest), creditRank(creditRank) {}

    void AddMoney(int money) {
        NormalAccount::AddMoney(money);
        Account::AddMoney((int)(money * (creditRank / 100.0)));
    }

    void UserInfo() const {
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

};