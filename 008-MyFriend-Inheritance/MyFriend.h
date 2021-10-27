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
		cout << endl << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}

	~MyFriendInfo() {
		cout << name << "�� �⺻������ ó���մϴ�." << endl;
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
		cout << "�ּ�: " << addr << endl;
		cout << "��ȭ: " << phone << endl;
	}

	~MyFriendDetailInfo() {
		cout << "��ȭ��ȣ�� " << phone << "�� ģ���� ���������� ó���մϴ�." << endl;
		delete[]addr;
		delete[]phone;	
	}
};