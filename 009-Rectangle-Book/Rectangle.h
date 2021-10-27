#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Rectangle {

	int row;
	int col;

public:
	Rectangle() :row(0), col(0) {}
	Rectangle(const int row, const int col) : row(row), col(col) {}
	
	void ShowAreaInfo() const {
		cout << "면적: " << row * col << endl;
	}
};

class Square :public Rectangle {

public:
	Square() : Rectangle(0, 0) {}
	Square(const int side): Rectangle(side, side){}
};

class Book {
	char* title;
	char* isbn;
	int price;

public:
	Book(const char* title, const char* isbn, int price): price(price) {
		this->title = new char[strlen(title) + 1];
		this->isbn = new char[strlen(isbn) + 1];

		strcpy(this->title, title);
		strcpy(this->isbn, isbn);
	}
	void ShowBookInfo() const {
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}
};

class EBook :public Book {
	char* DRMKey;

public:
	EBook(const char* title, const char* isbn, int price, const char* DRMKey) : Book(title, isbn, price) {
		this->DRMKey = new char[strlen(DRMKey) + 1];
		strcpy(this->DRMKey, DRMKey);
	}

	void ShowEBookInfo() const {
		ShowBookInfo();
		cout << "인증키: " << DRMKey << endl;
	}
};