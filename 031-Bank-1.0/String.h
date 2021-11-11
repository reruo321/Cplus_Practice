/* Version 0.9 */

#pragma once
#include <iostream>

using namespace std;

class String {
	char* s;
public:
	String();
	String(const char* str);
	String(const String& ref);
	String& operator=(const String& ref);
	String operator+(const String& add) const;
	String& operator+=(const String& add);
	bool operator==(const String& cmp) const;
	~String();
	friend istream& operator>>(istream& is, String& ref);
	friend ostream& operator<<(ostream& os, const String& ref);
};