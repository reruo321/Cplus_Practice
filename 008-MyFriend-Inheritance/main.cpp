#include "MyFriend.h"
#include <iostream>

using namespace std;

int main() {

	MyFriendInfo f1("ȫ�浿", 21);
	MyFriendDetailInfo fr1("��ö��", 19);
	MyFriendDetailInfo fr2("�ڿ���", 18, "����� ������", "000-1111-2222");

	f1.ShowMyFriendInfo();
	fr1.ShowMyFriendInfo();
	fr1.ShowMyFriendDetailInfo();
	fr2.ShowMyFriendInfo();
	fr2.ShowMyFriendDetailInfo();

	return 0;
}