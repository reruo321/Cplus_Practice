#include <iostream>

using namespace std;

int StoI(char* s) {
	int len = strlen(s);
	int num = 0;

	for (int i = 0; i < len; i++) {
		if (s[i] < '0' || s[i] > '9')
			throw s[i];
		num += (int)(pow((double)10, len - 1 - i) * ((double)s[i] + (double)(9 - '9')));
	}
	return num;
}

int main() {

	char str1[100];
	char str2[200];

	while (1) {
		cin >> str1 >> str2;
		try {
			cout << StoI(str1) << " + " << StoI(str2) << " = " << StoI(str1) + StoI(str2) << endl;
			break;
		}
		catch(char c){
			cout << "문자 " << c << "가 입력되었습니다. 숫자만 다시 입력하십시오." << endl;
		}
	}

	return 0;
}
