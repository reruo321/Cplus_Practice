/* Version 0.9 */

#define _CRT_SECURE_NO_WARNINGS
#include "String.h"

	String::String() {
		s = NULL;
	}
	String::String(const char* str) {
		s = new char[strlen(str) + 1];
		strcpy(s, str);
	}
	String::String(const String& ref) {
		s = new char[strlen(ref.s) + 1];
		strcpy(s, ref.s);
	}
	String& String::operator=(const String& ref) {
		if (s != NULL)
			delete[]s;
		s = new char[strlen(ref.s) + 1];
		strcpy(s, ref.s);
		return *this;
	}
	String String::operator+(const String& add) const {
		char* str = new char[strlen(s) + strlen(add.s) + 1];
		strcpy(str, s);
		strcat(str, add.s);
		String cat(str);
		delete[]str;
		return cat;
	}
	String& String::operator+=(const String& add) {
		int len = strlen(s);
		char* b = new char[strlen(s) + 1];
		strcpy(b, s);
		delete[]s;

		s = new char[len + strlen(add.s) + 1];
		strcpy(s, b);
		strcat(s, add.s);
		return *this;
	}
	bool String::operator==(const String& cmp) const {
		if (!strcmp(s, cmp.s))
			return 1;
		return 0;
	}
	String::~String() {
		delete[]s;
	}

istream& operator>>(istream& is, String& ref) {
	char buffer[100];
	is >> buffer;
	ref = String(buffer);
	return is;
}

ostream& operator<<(ostream& os, const String& ref) {
	os << ref.s;
	return os;
}
