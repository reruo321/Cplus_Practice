#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

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
	Book(const Book& ref): price(ref.price) {
		this->title = new char[strlen(ref.title) + 1];
		this->isbn = new char[strlen(ref.isbn) + 1];

		strcpy(this->title, ref.title);
		strcpy(this->isbn, ref.isbn);
		cout << "○ Book Copy" << endl;
	}
	Book &operator=(const Book &ref) {
		delete[]title;
		delete[]isbn;

		price = ref.price;
		this->title = new char[strlen(ref.title) + 1];
		this->isbn = new char[strlen(ref.isbn) + 1];

		strcpy(this->title, ref.title);
		strcpy(this->isbn, ref.isbn);
		cout << "○ Book Operator =" << endl;

		return *this;
	}

	void ShowBookInfo() const {
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}

	~Book() {
		cout << "○ Book 삭제" << endl;
		delete[]title;
		delete[]isbn;
	}
};

class EBook :public Book {
	char* DRMKey;

public:
	EBook(const char* title, const char* isbn, int price, const char* DRMKey) : Book(title, isbn, price) {
		this->DRMKey = new char[strlen(DRMKey) + 1];
		strcpy(this->DRMKey, DRMKey);
	}
	EBook(const EBook& ref): Book(ref) {
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);
		cout << "● EBook Copy" << endl;
	}
	EBook& operator=(const EBook& ref) {
		Book::operator=(ref);
		delete[]DRMKey;

		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);
		cout << "● EBook Operator =" << endl;

		return *this;
	}
	void ShowEBookInfo() const {
		ShowBookInfo();
		cout << "인증키: " << DRMKey << endl;
	}
	~EBook() {
		delete[]DRMKey;
		cout << "● EBook 삭제" << endl;
	}
};
