#ifndef __PNT_H_
#define __PNT_H_
#include <string>

using namespace std;

class Printer
{
private:
	string str;
public:
	void SetString(const string s);
	void ShowString();
};

#endif