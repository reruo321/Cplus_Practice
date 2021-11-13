/* Version 1.0 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Bank.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "BankingCommonDecl.h"
#include "BankingException.h"

using namespace std;

Bank::Bank(): total_id(0) {}

int Bank::Menu() const {

    int menu = 0;

    cout << "\n-----Menu-----" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입    금" << endl;
    cout << "3. 출    금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
    cout << "선택: ";

    menu = IntInput(CHECK_DATA::MENU).Get();

    return menu;
}

void Bank::Make() {

    int input_id;
    String input_name;
    int input_money;
    int accountType;
    int interest;
    int creditRank;

    cout << "[계좌종류선택]" << endl;
    cout << "1. 보통예금계좌 2. 신용신뢰계좌" << endl;
    cout << "선택: ";

    while (1) {
        accountType = IntInput(CHECK_DATA::MENU).Get();

        if (accountType == ACCOUNT_TYPE::NORMAL) {
            cout << "[보통예금계좌 개설]" << endl;
            break;
        }

        else if (accountType == ACCOUNT_TYPE::HIGH_CREDIT) {
            cout << "[신용신뢰계좌 개설]" << endl;
            break;
        }

        else
            cout << "번호는 1과 2 중 선택하세요." << endl;
    }


    cout << "계좌ID: ";

    while (1) {
        input_id = IntInput(CHECK_DATA::ID).Get();

        try {
            if (input_id < 0)
                throw MinusIDException();

            for (int i = 0; i < total_id; i++) {
                if (this->Acc[i]->CheckID() == input_id) {
                    throw DuplicatedIDException();
                }
            }
            break;
        }
        catch (BankingException &e) {
            e.ExceptReason();
        }
    }


    cout << "이름: ";
    cin >> input_name;
    cout << "입금액: ";

    while (1) {
        try {
            input_money = IntInput(CHECK_DATA::MONEY).Get();
            if (input_money < 0)
                throw MinusMoneyException();
            break;
        }
        catch(BankingException &e) {
            e.ExceptReason();
        }
    }

    cout << "이자율: ";

    while (1) {
        try {
            interest = IntInput(CHECK_DATA::INTEREST).Get();
            if (interest < 0)
                throw MinusInterestException();
            break;
        }
        catch (BankingException& e) {
            e.ExceptReason();
        }
    }

    if (accountType == ACCOUNT_TYPE::NORMAL) {
        this->Acc[total_id++] = new NormalAccount(input_id, input_name, input_money, interest);
    }

    else if (accountType == ACCOUNT_TYPE::HIGH_CREDIT) {

    RANK_AGAIN:
        cout << "신용등급(1toA, 2toB, 3toC): ";

        creditRank = IntInput(CHECK_DATA::RANK).Get();

        switch (creditRank) {
        case 1:
            this->Acc[total_id++] = new HighCreditAccount(input_id, input_name, input_money, interest, CREDIT_RANK::RANK_A);
            break;
        case 2:
            this->Acc[total_id++] = new HighCreditAccount(input_id, input_name, input_money, interest, CREDIT_RANK::RANK_B);
            break;
        case 3:
            this->Acc[total_id++] = new HighCreditAccount(input_id, input_name, input_money, interest, CREDIT_RANK::RANK_C);
            break;
        default:
            cout << "신용등급은 1~3 중 번호로 입력하세요." << endl;
            goto RANK_AGAIN;
            break;
        }
    }

    cout << "\n-----계좌개설-----" << endl;
    this->Acc[total_id-1]->UserInfo();

}

void Bank::Deposit() {

    int id = 0;
    int i = 0;
    char yesno;
    int money;
    bool idExist = false;

    cout << "ID를 입력하세요: " << endl;
ID_AGAIN:

    idExist = false;
    id = IntInput(CHECK_DATA::ID).Get();

    for (i = 0; i < total_id; i++) {
        if (this->Acc[i]->CheckID() == id) {
            idExist = true;
            break;
        }
    }

    if (idExist == false) {
        cout << "존재하지 않는 ID입니다." << endl;
        return;
    }

    this->Acc[i]->UserInfo();

    cout << "\n고객정보가 맞습니까? (y/n) : ";
YN_AGAIN:
    cin >> yesno;

    if (yesno == 'y') {
        cout << "입금액을 입력하십시오: ";

        while (1) {
            try {
                money = IntInput(CHECK_DATA::MONEY).Get();
                if (money < 0)
                    throw MinusMoneyException();
                break;
            }
            catch (BankingException& e) {
                e.ExceptReason();
            }
        }

        this->Acc[i]->AddMoney(money);
        this->Acc[i]->UserInfo();

        cout << "입금이 완료되었습니다." << endl;
    }

    else if (yesno == 'n') {
        cout << "ID를 다시 입력하십시오." << endl;
        goto ID_AGAIN;
    }

    else {
        cout << "y 또는 n을 입력하십시오." << endl;
        goto YN_AGAIN;
    }

}

void Bank::Withdraw() {

    int i = 0;
    int id = 0;
    char yesno;
    int money;
    bool idExist = false;

    cout << "ID를 입력하세요: " << endl;
ID_AGAIN:

    idExist = false;
    id = IntInput(CHECK_DATA::ID).Get();

    for (i = 0; i < total_id; i++) {
        if (this->Acc[i]->CheckID() == id) {
            idExist = true;
            break;
        }
    }

    if (idExist == false) {
        cout << "존재하지 않는 ID입니다." << endl;
        return;
    }

    this->Acc[i]->UserInfo();

    cout << "\n고객정보가 맞습니까? (y/n) : ";
YN_AGAIN:
    cin >> yesno;

    if (yesno == 'y') {
        cout << "출금액을 입력하십시오: ";

        while (1) {
            try {
                money = IntInput(CHECK_DATA::MONEY).Get();

                if (money < 0)
                    throw MinusMoneyException();
                if (money > this->Acc[i]->CheckMoney())
                    throw NotEnoughMoneyException(this->Acc[i]->CheckMoney());

                break;
            }
            catch (BankingException& e) {
                e.ExceptReason();
            }
        }

        this->Acc[i]->WithdrawMoney(money);
        this->Acc[i]->UserInfo();
        cout << "출금이 완료되었습니다." << endl;
    }

    else if (yesno == 'n') {
        cout << "ID를 다시 입력하십시오." << endl;
        goto ID_AGAIN;
    }

    else {
        cout << "y 또는 n을 입력하십시오." << endl;
        goto YN_AGAIN;
    }
}

void Bank::All_UserInfo() const {

    if (total_id == 0) {
        cout << "\n등록된 고객이 없습니다." << endl;
        return;
    }
    else
        cout << "\n-----고객목록-----" << endl;

    for (int i = 0; i < total_id; i++)
        this->Acc[i]->UserInfo();

}
void Bank::ExitBank() {
    cout << "이용해주셔서 감사합니다." << endl<< endl;
    cout << "고객님의 정보를 안전하게 소멸 처리합니다..." << endl;

    for (int i = 0; i < total_id; i++) {
        delete Acc[i];
        cout << i << "번째 계좌정보를 처리하였습니다." << endl;
    }
}

Bank::~Bank() {
    for(int i=0; i<total_id; i++)
        delete Acc[i];
}