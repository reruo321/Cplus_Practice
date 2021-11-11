/* Version 0.8 */

#include <iostream>
#include "Bank.h"
#include "BankingCommonDecl.h"

using namespace std;

int main()
{
    int menu_val;

    Bank * bank = new Bank;

    while (1) {
        menu_val = bank->Menu();
        switch (menu_val) {

        case MAKE:
            bank->Make();
            break;
        case DEPOSIT:
            bank->Deposit();
            break;
        case WITHDRAW:
            bank->Withdraw();
            break;
        case INFO:
            bank->All_UserInfo();
            break;
        case EXIT:
            bank->ExitBank();
            return 0;
        default:
            cout << "¼ýÀÚ 1~5¸¦ ÀÔ·ÂÇÏ¼¼¿ä." << endl;
            break;
        }
    }
    return 0;
}
