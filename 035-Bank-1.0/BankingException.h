/* Version 1.0 */

#pragma once
#include <iostream>
#include "BankingCommonDecl.h"

using namespace std;

class BankingException {
public:
	virtual void ExceptReason() const = 0;
};

class MinusIDException : public BankingException {
public:
	void ExceptReason() const {
		cout << "ID는 음수로 입력할 수 없습니다. 다시 입력하세요." << endl;
	}
};

class MinusMoneyException : public BankingException {
public:
	void ExceptReason() const {
		cout << "금액은 음수로 입력할 수 없습니다. 다시 입력하세요." << endl;
	}
};

class MinusInterestException : public BankingException {
public:
	void ExceptReason() const {
		cout << "이자율은 음수로 입력할 수 없습니다. 다시 입력하세요." << endl;
	}
};

class NotEnoughMoneyException : public BankingException {
	int balance;
public:
	NotEnoughMoneyException(int balance) : balance(balance) {}
	void ExceptReason() const {
		cout << "계좌잔액은 " << balance << "원입니다. 잔액이 부족합니다." << endl;
	}
};

class NoAccountIdException : public BankingException {
public:
	void ExceptReason() const {
		cout << "등록되지 않은 계좌 ID입니다." << endl;
	}
};

class DuplicatedIDException : public BankingException {
public:
	void ExceptReason() const {
		cout << "중복된 ID입니다. 다른 ID로 시도해주세요." << endl;
	}
};

class NotIntException : public BankingException {
	int check_data;
public:
	NotIntException() : check_data(0) {}
	NotIntException(int check_data) : check_data(check_data) {}
	void ExceptReason() const {
		switch (check_data)
		{
		case CHECK_DATA::MENU:
			cout << "메뉴는 숫자 번호로 선택하세요." << endl;
			break;
		case CHECK_DATA::ID:
			cout << "ID는 숫자로 입력하세요." << endl;
			break;
		case CHECK_DATA::MONEY:
			cout << "금액은 숫자로 입력하세요." << endl;
			break;
		case CHECK_DATA::INTEREST:
			cout << "이자율은 숫자로 입력하세요." << endl;
			break;
		case CHECK_DATA::RANK:
			cout << "신용등급은 숫자로 입력하세요." << endl;
			break;
		default:
			cout << "NotIntException 시스템 오류입니다. 시스템을 종료합니다." << endl;
			exit(1);
		}
	}
};

class IntInput {
	const int check_data;
public:
	IntInput(): check_data(0) {}
	IntInput(int check_data): check_data(check_data){}
	int Get() const {
		int input = 0;
	INPUT_AGAIN:
		try{
			cin >> input;
			if (!cin.good())
				throw NotIntException(check_data);
			return input;
		}
		catch(NotIntException &e){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			e.ExceptReason();
			goto INPUT_AGAIN;
		}
		return input;
	}
};
