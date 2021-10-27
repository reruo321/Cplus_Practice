#include "MyFriend.h"
#include <iostream>

using namespace std;

int main() {

	MyFriendInfo f1("È«±æµ¿", 21);
	MyFriendDetailInfo fr1("±èÃ¶¼ö", 19);
	MyFriendDetailInfo fr2("¹Ú¿µÈñ", 18, "¼­¿ï½Ã °­µ¿±¸", "000-1111-2222");

	f1.ShowMyFriendInfo();
	fr1.ShowMyFriendInfo();
	fr1.ShowMyFriendDetailInfo();
	fr2.ShowMyFriendInfo();
	fr2.ShowMyFriendDetailInfo();

	return 0;
}