#include <iostream>
#include "Bank.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

Bank::Bank() {
    total_id = 0;
}

/* Deep Copy */

Bank::Bank(const Bank& bref) : total_id(bref.total_id) {
    memcpy(Acc, bref.Acc, sizeof(Account *)*BANK_SIZE);
}

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

    char input_name[20];
    int input_money;

    cout << "�̸��� �Է��ϼ���: ";
    cin >> input_name;
    cout << "�ݾ��� �Է��ϼ���: ";

MONEY_AGAIN:
    cin >> input_money;

    if (!cin.good()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "�ݾ��� ���ڷ� �Է��ϼ���." << endl;
        goto MONEY_AGAIN;
    }

    total_id++;

    this->Acc[total_id-1] = new Account(total_id-1, input_name, input_money);

    cout << "\n-----���°���-----" << endl;
    this->Acc[total_id-1]->UserInfo();

}

void Bank::Deposit() {

    int id = 0;
    char yesno;
    int money;

    cout << "ID�� �Է��ϼ���: " << endl;
DEPID_AGAIN:
    cin >> id;

    if (!cin.good()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "ID�� ���ڷ� �Է��ϼ���." << endl;
        goto DEPID_AGAIN;
    }

    if (id > total_id - 1) {
        cout << "�������� �ʴ� ID�Դϴ�." << endl;
        return;
    }

    this->Acc[id]->UserInfo();

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
        this->Acc[id]->AddMoney(money);
        this->Acc[id]->UserInfo();

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

    int id = 0;
    char yesno;
    int money;

    cout << "ID�� �Է��ϼ���: " << endl;
WITHID_AGAIN:
    cin >> id;

    if (!cin.good()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "ID�� ���ڷ� �Է��ϼ���." << endl;
        goto WITHID_AGAIN;
    }

    if (id > total_id - 1) {
        cout << "�������� �ʴ� ID�Դϴ�." << endl;
        return;
    }

    this->Acc[id]->UserInfo();

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

        else if (money > this->Acc[id]->CheckMoney()) {
            cout << "�ݾ��� �����մϴ�. ��ݾ��� �ٽ� �Է��Ͻʽÿ�: ";
            goto WITHDRAW_AGAIN;
        }

        this->Acc[id]->AddMoney(-money);
        this->Acc[id]->UserInfo();
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
        cout << "ID�� " << i << "�� ������ ������ ó���Ͽ����ϴ�." << endl;
    }
}

Bank::~Bank() {
    delete[]Acc;
}