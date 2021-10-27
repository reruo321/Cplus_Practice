#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class MyFriendInfo {
private:
	char* name;
	int age;
public:

	MyFriendInfo(const char* name, int age) : age(age) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

	void ShowMyFriendInfo() {
		cout << endl << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}

	~MyFriendInfo() {
		cout << name << "의 기본정보를 처리합니다." << endl;
		delete[]name;
	}
};

class MyFriendDetailInfo : public MyFriendInfo {
private:
	char* addr;
	char* phone;
public:
	MyFriendDetailInfo(const char* name, int age, const char* addr, const char* phone) : MyFriendInfo(name, age) {
		this->addr = new char[strlen(addr) + 1];
		this->phone = new char[strlen(phone) + 1];

		strcpy(this->addr, addr);
		strcpy(this->phone, phone);	
	}

	MyFriendDetailInfo(const char* name, int age) : MyFriendInfo(name, age) {
		this->addr = new char[strlen("???") + 1];
		this->phone = new char[strlen("???") + 1];

		strcpy(this->addr, "???");
		strcpy(this->phone, "???");
	}

	void ShowMyFriendDetailInfo() {
		ShowMyFriendInfo();
		cout << "주소: " << addr << endl;
		cout << "전화: " << phone << endl;
	}

	~MyFriendDetailInfo() {
		cout << "전화번호가 " << phone << "인 친구의 세부정보를 처리합니다." << endl;
		delete[]addr;
		delete[]phone;	
	}
};