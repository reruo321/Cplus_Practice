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
    cout << "1. 계좌개설" << endl;
    cout << "2. 입    금" << endl;
    cout << "3. 출    금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
    cout << "선택: ";
    cin >> sel;

    if (!cin.good()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "숫자를 입력하세요." << endl;
        goto MENU_AGAIN;
    }

    return sel;
}

void Bank::Make() {

    char input_name[20];
    int input_money;

    cout << "이름을 입력하세요: ";
    cin >> input_name;
    cout << "금액을 입력하세요: ";

MONEY_AGAIN:
    cin >> input_money;

    if (!cin.good()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "금액은 숫자로 입력하세요." << endl;
        goto MONEY_AGAIN;
    }

    total_id++;

    this->Acc[total_id-1] = new Account(total_id-1, input_name, input_money);

    cout << "\n-----계좌개설-----" << endl;
    this->Acc[total_id-1]->UserInfo();

}

void Bank::Deposit() {

    int id = 0;
    char yesno;
    int money;

    cout << "ID를 입력하세요: " << endl;
DEPID_AGAIN:
    cin >> id;

    if (!cin.good()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "ID는 숫자로 입력하세요." << endl;
        goto DEPID_AGAIN;
    }

    if (id > total_id - 1) {
        cout << "존재하지 않는 ID입니다." << endl;
        return;
    }

    this->Acc[id]->UserInfo();

    cout << "\n고객정보가 맞습니까? (y/n) : ";
YN_AGAIN:
    cin >> yesno;

    if (yesno == 'y') {
        cout << "입금액을 입력하십시오: ";
    DEPOSIT_AGAIN:
        cin >> money;

        if (!cin.good()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "입금액은 숫자로 입력하세요." << endl;
            goto DEPOSIT_AGAIN;
        }

        if (money < 0) {
            cout << "입금액을 다시 입력하십시오: ";
            goto DEPOSIT_AGAIN;
        }
        this->Acc[id]->AddMoney(money);
        this->Acc[id]->UserInfo();

        cout << "입금이 완료되었습니다." << endl;
    }

    else if (yesno == 'n') {
        cout << "ID를 다시 입력하십시오." << endl;
        goto DEPID_AGAIN;
    }

    else {
        cout << "y 또는 n을 입력하십시오." << endl;
        goto YN_AGAIN;
    }

}

void Bank::Withdraw() {

    int id = 0;
    char yesno;
    int money;

    cout << "ID를 입력하세요: " << endl;
WITHID_AGAIN:
    cin >> id;

    if (!cin.good()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "ID는 숫자로 입력하세요." << endl;
        goto WITHID_AGAIN;
    }

    if (id > total_id - 1) {
        cout << "존재하지 않는 ID입니다." << endl;
        return;
    }

    this->Acc[id]->UserInfo();

    cout << "\n고객정보가 맞습니까? (y/n) : ";
YN_AGAIN:
    cin >> yesno;

    if (yesno == 'y') {
        cout << "출금액을 입력하십시오: ";
    WITHDRAW_AGAIN:
        cin >> money;

        if (!cin.good()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "출금액은 숫자로 입력하세요." << endl;
            goto WITHDRAW_AGAIN;
        }

        if (money < 0) {
            cout << "출금액을 다시 입력하십시오: ";
            goto WITHDRAW_AGAIN;
        }

        else if (money > this->Acc[id]->CheckMoney()) {
            cout << "금액이 부족합니다. 출금액을 다시 입력하십시오: ";
            goto WITHDRAW_AGAIN;
        }

        this->Acc[id]->AddMoney(-money);
        this->Acc[id]->UserInfo();
        cout << "출금이 완료되었습니다." << endl;
    }

    else if (yesno == 'n') {
        cout << "ID를 다시 입력하십시오." << endl;
        goto WITHID_AGAIN;
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
        cout << "ID가 " << i << "인 고객님의 정보를 처리하였습니다." << endl;
    }
}

Bank::~Bank() {
    delete[]Acc;
}