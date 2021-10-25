#include <iostream>
#include "NameCard.h"

int main() {
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
//	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);

	NameCard copy1 = manClerk;
	NameCard copy2 = manSenior;
	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();

	return 0;
}