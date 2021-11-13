#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class AccountException {
public:
	virtual void ShowException() const = 0;
};

class DepositException: public AccountException {
	int money;
public:
	DepositException(int money) : AccountException(), money(money) {}
	void ShowException() const {
		cout << money << " 값은 잘못된 입력입니다." << endl;
	}
};

class WithdrawException : public AccountException {
	int money;
public:
	WithdrawException(int money): AccountException(), money(money){}
	void ShowException() const {
			cout << money << " 값은 잘못된 입력입니다." << endl;
	}
};

class WithdrawBalanceException : public AccountException {
	int balance;
public:
	WithdrawBalanceException(int balance) : AccountException(), balance(balance) {}
	void ShowException() const {
		cout << "잔액: " << balance << "원입니다. 잔액이 부족합니다." << endl;
	}
};

class Account {
	char accNum[50];
	int balance;
public:
	Account(const char* acc, int bal) : balance(bal) {
		strcpy(accNum, acc);
	}
	void Deposit(int money) throw (AccountException) {
		cout << money << "원을 입금합니다." << endl;
		if (money < 0)
			throw DepositException(money);
		balance += money;
	}
	void Withdraw(int money) throw (AccountException) {
		cout << money << "원을 출금합니다." << endl;
		if (money < 0)
			throw WithdrawException(money);
		else if (money > balance)
			throw WithdrawBalanceException(balance);
		balance -= money;
	}
	void ShowBalance() const {
		cout << "잔고: " << balance << "원" << endl;
	}
};
