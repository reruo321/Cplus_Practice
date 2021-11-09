#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class String {
	char* s;
public:
	String() {
		s = NULL;
	}
	String(const char* str) {
		s = new char[strlen(str) + 1];
		strcpy(s, str);
	}
	String(const String &ref) {
		s = new char[strlen(ref.s) + 1];
		strcpy(s, ref.s);
	}
	String& operator=(const String& ref) {
		if(s != NULL)
			delete []s;
		s = new char[strlen(ref.s) + 1];
		strcpy(s, ref.s);
		return *this;
	}
	String operator+(const String& add) const {
		char* str = new char[strlen(s) + strlen(add.s) + 1];
		strcpy(str, s);
		strcat(str, add.s);
		String cat(str);
		delete []str;
		return cat;
	}
	String& operator+=(const String& add) {
		int len = strlen(s);
		char* b = new char[strlen(s)+1];
		strcpy(b, s);
		delete[]s;
		
		s = new char[len + strlen(add.s) + 1];
		strcpy(s, b);
		strcat(s, add.s);
		return *this;
	}
	bool operator==(const String& cmp) const {
		if (!strcmp(s, cmp.s))
			return 1;
		return 0;
	}
	~String() {
		delete[]s;
	}
	friend istream& operator>>(istream& is, String& ref);
	friend ostream& operator<<(ostream &os, const String& ref);
};

istream& operator>>(istream& is, String& ref) {
	char buffer[100];
	is >> buffer;
	ref = String(buffer);
	return is;
}
ostream& operator<<(ostream &os, const String& ref) {
	os << ref.s;
	return os;
}

int main() {

	String str1 = "I like ";
	String str2 = "string class";
	String str3 = str1 + str2;
	
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;
	if (str1 == str3)
		cout << "동일 문자열!" << endl;
	else
		cout << "동일하지 않은 문자열!" << endl;

	string str4;
	cout << "문자열 입력: " << endl;
	cin >> str4;
	cout << "입력한 문자열: " << str4 << endl;

	return 0;
}
