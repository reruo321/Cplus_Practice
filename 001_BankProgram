#include <iostream>
#include <cstring>
#include <limits>

typedef struct _USER {
    struct _USER* next;
    int id;
    char name[10];
    int money;
} USER, * PUSER;

enum {
    MAKE = 1,
    DEPOSIT = 2,
    WITHDRAW = 3,
    INFO = 4,
    EXIT = 5
};

int menu();
void make(PUSER header, int* userNum);
void personal_Info(PUSER curr);
void deposit(PUSER head);
void withdraw(PUSER head);
void info(PUSER head);
void exitbank(PUSER head);

using namespace std;

int main()
{
    int menu_val = 0;
    int userNum = 0;
    PUSER head = (PUSER)malloc(sizeof(USER));
    head->next = NULL;

    while (1) {
        menu_val = menu();
        switch (menu_val) {

        case MAKE:
            make(head, &userNum);
            break;
        case DEPOSIT:
            deposit(head);
            break;
        case WITHDRAW:
            withdraw(head);
            break;
        case INFO:
            info(head);
            break;
        case EXIT:
            exitbank(head);
            return 0;
        default:
            cout << "숫자 1~5를 입력하세요." << endl;
            break;
        }
    }
    return 0;
}

int menu() { 
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

void make(PUSER head, int* userNum) {

    if (head == NULL)
        return;

    PUSER user = (PUSER)malloc(sizeof(USER));
    if (user == NULL)
        return;

    PUSER curr = head;

    (*userNum)++;

    for (int i = 1; i < *userNum; i++)
        curr = curr->next;

    curr->next = user;
    user->next = NULL;
    user->id = *userNum;

    cout << "이름을 입력하세요: ";
    cin >> user->name;
    cout << "금액을 입력하세요: ";
    MONEY_AGAIN:
    cin >> user->money;

    if (!cin.good()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "금액은 숫자로 입력하세요." << endl;
        goto MONEY_AGAIN;
    }

    cout << "\n-----계좌개설-----" << endl;
    cout << "ID: " << user->id << endl;
    cout << "이름: " << user->name << endl;
    cout << "금액: " << user->money << endl;

}

void personal_Info(PUSER curr) {
    cout << "\nID: " << curr->id << endl;
    cout << "이름: " << curr->name << endl;
    cout << "금액: " << curr->money << endl;
}

void deposit(PUSER head) {
    int id, money;
    bool valid_id = false;
    char yesno;
    PUSER curr;

    ID_AGAIN:

    curr = head;
    if (curr == NULL)
        return;

    cout << "ID를 입력하세요: " << endl;
    DEPID_AGAIN:
    cin >> id;

    if (!cin.good()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "ID는 숫자로 입력하세요." << endl;
        goto DEPID_AGAIN;
    }

    while (curr->next != NULL) {
        curr = curr->next;
        if (curr->id == id) {
            valid_id = true;
            break;
        }
    }
    
    if (valid_id == false) {
        cout << "존재하지 않는 ID입니다." << endl;
        return;
    }

    personal_Info(curr);

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

        if (money < 0){
            cout << "입금액을 다시 입력하십시오: ";
            goto DEPOSIT_AGAIN;
    }
        curr->money += money;
        personal_Info(curr);
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

void withdraw(PUSER head) {
    int id, money;
    bool valid_id = false;
    char yesno;
    PUSER curr;

ID_AGAIN:

    curr = head;
    if (curr == NULL)
        return;

    cout << "ID를 입력하세요: " << endl;
    WITHID_AGAIN:
    cin >> id;

    if (!cin.good()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "ID는 숫자로 입력하세요." << endl;
        goto WITHID_AGAIN;
    }

    while (curr->next != NULL) {
        curr = curr->next;
        if (curr->id == id) {
            valid_id = true;
            break;
        }
    }

    if (valid_id == false) {
        cout << "존재하지 않는 ID입니다." << endl;
        return;
    }

    personal_Info(curr);

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

        else if (money > curr->money) {
            cout << "금액이 부족합니다. 출금액을 다시 입력하십시오: ";
            goto WITHDRAW_AGAIN;
        }

        curr->money -= money;
        personal_Info(curr);
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

void info(PUSER head) {
    PUSER curr = head;
    if (curr->next == NULL) {
        cout << "\n등록된 고객이 없습니다." << endl;
        return;
    }
    else
        cout << "\n-----고객목록-----" << endl;

    while (curr->next != NULL) {
        curr = curr->next;
        personal_Info(curr);
    }
}
void exitbank(PUSER head) {
    cout << "이용해주셔서 감사합니다." << endl;
    
    PUSER curr = head;

    while (curr->next != NULL) {
        PUSER next = curr->next;
        free(curr);
        curr = next;    
    }

}
