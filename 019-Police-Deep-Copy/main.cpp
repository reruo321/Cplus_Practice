#include <iostream>
#include <cstring>

using namespace std;

class Gun {
	int bullet;
public:
	Gun(int bnum): bullet(bnum){}
	void Shot() {
		cout << "BBANG!" << endl;
		bullet--;
	}
};

class Police {
	int handcuffs;
	Gun* pistol;
public:
	Police(int bnum, int bcuff) : handcuffs(bcuff) {
		if (bnum > 0)
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}
	Police(const Police& ref) : handcuffs(ref.handcuffs) {
		if (ref.pistol != NULL)
			pistol = new Gun(*(ref.pistol));
		else
			pistol = NULL;
		cout << "Copy Constructor" << endl;
	}
	Police& operator=(const Police& ref) {
		if (pistol != NULL)
			delete pistol;

		handcuffs = ref.handcuffs;
		if (ref.pistol != NULL)
			pistol = new Gun(*(ref.pistol));
		else
			pistol = NULL;
		cout << "Operator =" << endl;
		return *this;
	}
	void PutHandcuff() {
		cout << "SNAP!" << endl;
		handcuffs--;
	}
	void Shot() {
		if (pistol == NULL)
			cout << "Hut BBANG!" << endl;
		else
			pistol->Shot();
	}
	~Police() {
		if (pistol != NULL)
			delete pistol;
	}
};

int main() {
	Police pman1(5, 3);
	pman1.Shot();
	pman1.PutHandcuff();

	Police pman2(pman1);
	pman2.Shot();
	pman2.PutHandcuff();

	Police pman3(0, 0);
	pman3 = pman1;
	pman3.Shot();
	pman3.PutHandcuff();

	return 0;
}