#include "ATM.h"

int main() {

	Account acc("01234-56789", 10000);
	acc.ShowBalance();
	cout << endl;
	try {
		acc.Deposit(1000);
		acc.Deposit(-2000);
	}
	catch (AccountException& exc) {
		exc.ShowException();
	}
	acc.ShowBalance();
	cout << endl;
	try {
		acc.Withdraw(2000);
		acc.Withdraw(20000);
	}
	catch (AccountException& exc) {
		exc.ShowException();
	}
	acc.ShowBalance();
	cout << endl;
	try {
		acc.Withdraw(4000);
		acc.Withdraw(-3000);
	}
	catch (AccountException &exc) {
		exc.ShowException();
	}
	acc.ShowBalance();

	return 0;
}
