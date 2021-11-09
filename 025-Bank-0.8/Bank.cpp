/* Version 0.8 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Bank.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "BankingCommonDecl.h"

using namespace std;

Bank::Bank(): total_id(0) {}

int Bank::Menu() const {
    int sel = 0;

MENU_AGAIN:
    cout << "\n-----Menu-----" << endl;
    cout << "1. ���°���" << endl;
    cout << "2. ��    ��" << endl;
    cout << "3. ��    ��" << endl;
    cout << "4. �������� ��ü ���" << endl;
    cout << "5. ���α׷� ����" << endl;
    cout << "����: ";
    cin >> sel;

    if (!cin.good()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "���ڸ� �Է��ϼ���." << endl;
        goto MENU_AGAIN;
    }

    return sel;
}

void Bank::Make() {

    int input_id;
    char input_name[20];
    int input_money;
    int accountType;
    int interest;
    int creditRank;

    cout << "[������������]" << endl;
    cout << "1. ���뿹�ݰ��� 2. �ſ�ŷڰ���" << endl;
    cout << "����: ";

TYPE_AGAIN:
    cin >> accountType;

    if (!cin.good()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "���������� ��ȣ�� �Է��ϼ���." << endl;
        goto TYPE_AGAIN;
    }

    if (accountType == ACCOUNT_TYPE::NORMAL) {
        cout << "[���뿹�ݰ��� ����]" << endl;
    }

    else if (accountType == ACCOUNT_TYPE::HIGH_CREDIT) {
        cout << "[�ſ�ŷڰ��� ����]" << endl;
    }

    else {
        cout << "��ȣ�� 1�� 2 �� �����ϼ���." << endl;
        goto TYPE_AGAIN;
    }

    cout << "����ID: ";
ID_AGAIN:
    cin >> input_id;

    if (!cin.good()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "ID�� ���ڷ� �Է��ϼ���." << endl;
        goto ID_AGAIN;
    }

    for (int i = 0; i < total_id; i++) {
        if (this->Acc[i]->CheckID() == input_id) {
            cout << "�ߺ��� ID�Դϴ�. �ٽ� �Է��ϼ���." << endl;
            goto ID_AGAIN;
        }
    }

    cout << "�̸�: ";
    cin >> input_name;
    cout << "�Աݾ�: ";

MONEY_AGAIN:
    cin >> input_money;

    if (!cin.good()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "�Աݾ��� ���ڷ� �Է��ϼ���." << endl;
        goto MONEY_AGAIN;
    }

    cout << "������: ";

INTEREST_AGAIN:
    cin >> interest;

    if (!cin.good()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "�������� ���ڷ� �Է��ϼ���." << endl;
        goto INTEREST_AGAIN;
    }

    if (accountType == ACCOUNT_TYPE::NORMAL) {
        this->Acc[total_id++] = new NormalAccount(input_id, input_name, input_money, interest);
    }

    else if (accountType == ACCOUNT_TYPE::HIGH_CREDIT) {

        cout << "�ſ���(1toA, 2toB, 3toC): ";

    RANK_AGAIN:
        cin >> creditRank;

        if (!cin.good()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "�ſ����� ���ڷ� �Է��ϼ���." << endl;
            goto RANK_AGAIN;
        }

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
DEPID_AGAIN:

    idExist = false;
    cin >> id;

    if (!cin.good()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "ID�� ���ڷ� �Է��ϼ���." << endl;
        goto DEPID_AGAIN;
    }

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
    DEPOSIT_AGAIN:
        cin >> money;

        if (!cin.good()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "�Աݾ��� ���ڷ� �Է��ϼ���." << endl;
            goto DEPOSIT_AGAIN;
        }

        if (money < 0) {
            cout << "�Աݾ��� �ٽ� �Է��Ͻʽÿ�: ";
            goto DEPOSIT_AGAIN;
        }
        this->Acc[i]->AddMoney(money);
        this->Acc[i]->UserInfo();

        cout << "�Ա��� �Ϸ�Ǿ����ϴ�." << endl;
    }

    else if (yesno == 'n') {
        cout << "ID�� �ٽ� �Է��Ͻʽÿ�." << endl;
        goto DEPID_AGAIN;
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
WITHID_AGAIN:

    idExist = false;
    cin >> id;

    if (!cin.good()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "ID�� ���ڷ� �Է��ϼ���." << endl;
        goto WITHID_AGAIN;
    }

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
    WITHDRAW_AGAIN:
        cin >> money;

        if (!cin.good()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "��ݾ��� ���ڷ� �Է��ϼ���." << endl;
            goto WITHDRAW_AGAIN;
        }

        if (money < 0) {
            cout << "��ݾ��� �ٽ� �Է��Ͻʽÿ�: ";
            goto WITHDRAW_AGAIN;
        }

        else if (money > this->Acc[i]->CheckMoney()) {
            cout << "�ݾ��� �����մϴ�. ��ݾ��� �ٽ� �Է��Ͻʽÿ�: ";
            goto WITHDRAW_AGAIN;
        }

        this->Acc[i]->WithdrawMoney(money);
        this->Acc[i]->UserInfo();
        cout << "����� �Ϸ�Ǿ����ϴ�." << endl;
    }

    else if (yesno == 'n') {
        cout << "ID�� �ٽ� �Է��Ͻʽÿ�." << endl;
        goto WITHID_AGAIN;
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