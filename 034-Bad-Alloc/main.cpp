#include <iostream>

using namespace std;

int main() {

	int num = 0;

	try {
		while (1) {
			num++;
			cout << num << "번째 할당 시도" << endl;
			new int[10000][10000];
		}
	}
	catch(bad_alloc &b){
		cout << b.what() << endl;
		cout << "할당 불가" << endl;
	}

	return 0;
}
