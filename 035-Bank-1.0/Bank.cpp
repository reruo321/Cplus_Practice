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
    cout << "1. ���°���" << endl;
    cout << "2. ��    ��" << endl;
    cout << "3. ��    ��" << endl;
    cout << "4. �������� ��ü ���" << endl;
    cout << "5. ���α׷� ����" << endl;
    cout << "����: ";

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

    cout << "[������������]" << endl;
    cout << "1. ���뿹�ݰ��� 2. �ſ�ŷڰ���" << endl;
    cout << "����: ";

    while (1) {
        accountType = IntInput(CHECK_DATA::MENU).Get();

        if (accountType == ACCOUNT_TYPE::NORMAL) {
            cout << "[���뿹�ݰ��� ����]" << endl;
            break;
        }

        else if (accountType == ACCOUNT_TYPE::HIGH_CREDIT) {
            cout << "[�ſ�ŷڰ��� ����]" << endl;
            break;
        }

        else
            cout << "��ȣ�� 1�� 2 �� �����ϼ���." << endl;
    }


    cout << "����ID: ";

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


    cout << "�̸�: ";
    cin >> input_name;
    cout << "�Աݾ�: ";

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

    cout << "������: ";

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
        cout << "�ſ���(1toA, 2toB, 3toC): ";

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
            cout << "�ſ����� 1~3 �� ��ȣ�� �Է��ϼ���." << endl;
            goto RANK_AGAIN;
            break;
        }
    }

    cout << "\n-----���°���-----" << endl;
    this->Acc[total_id-1]->UserInfo();

}

void Bank::Deposit() {

    int id = 0;
    int i = 0;
    char yesno;
    int money;
    bool idExist = false;

    cout << "ID�� �Է��ϼ���: " << endl;
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
        cout << "�������� �ʴ� ID�Դϴ�." << endl;
        return;
    }

    this->Acc[i]->UserInfo();

    cout << "\n�������� �½��ϱ�? (y/n) : ";
YN_AGAIN:
    cin >> yesno;

    if (yesno == 'y') {
        cout << "�Աݾ��� �Է��Ͻʽÿ�: ";

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

        cout << "�Ա��� �Ϸ�Ǿ����ϴ�." << endl;
    }

    else if (yesno == 'n') {
        cout << "ID�� �ٽ� �Է��Ͻʽÿ�." << endl;
        goto ID_AGAIN;
    }

    else {
        cout << "y �Ǵ� n�� �Է��Ͻʽÿ�." << endl;
        goto YN_AGAIN;
    }

}

void Bank::Withdraw() {

    int i = 0;
    int id = 0;
    char yesno;
    int money;
    bool idExist = false;

    cout << "ID�� �Է��ϼ���: " << endl;
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
        cout << "�������� �ʴ� ID�Դϴ�." << endl;
        return;
    }

    this->Acc[i]->UserInfo();

    cout << "\n�������� �½��ϱ�? (y/n) : ";
YN_AGAIN:
    cin >> yesno;

    if (yesno == 'y') {
        cout << "��ݾ��� �Է��Ͻʽÿ�: ";

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
        cout << "����� �Ϸ�Ǿ����ϴ�." << endl;
    }

    else if (yesno == 'n') {
        cout << "ID�� �ٽ� �Է��Ͻʽÿ�." << endl;
        goto ID_AGAIN;
    }

    else {
        cout << "y �Ǵ� n�� �Է��Ͻʽÿ�." << endl;
        goto YN_AGAIN;
    }
}

void Bank::All_UserInfo() const {

    if (total_id == 0) {
        cout << "\n��ϵ� ���� �����ϴ�." << endl;
        return;
    }
    else
        cout << "\n-----�����-----" << endl;

    for (int i = 0; i < total_id; i++)
        this->Acc[i]->UserInfo();

}
void Bank::ExitBank() {
    cout << "�̿����ּż� �����մϴ�." << endl<< endl;
    cout << "������ ������ �����ϰ� �Ҹ� ó���մϴ�..." << endl;

    for (int i = 0; i < total_id; i++) {
        delete Acc[i];
        cout << i << "��° ���������� ó���Ͽ����ϴ�." << endl;
    }
}

Bank::~Bank() {
    for(int i=0; i<total_id; i++)
        delete Acc[i];
}