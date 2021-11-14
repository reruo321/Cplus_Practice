#include <iostream>

using namespace std;

class Animal {
	int height;
public:
	Animal(int h) : height(h){}
	void ShowAnimalInfo() const {
		cout << "키: " << height << "CM" << endl;
	}
};

class Pig: public Animal {
	int weight;
public:
	Pig(int h, int w) : Animal(h), weight(w){}
	void ShowPigInfo() {
		ShowAnimalInfo();
		cout << "몸무게: " << weight << "KG" << endl;
	}
};

class VirtualAnimal {
	int height;
public:
	VirtualAnimal(int h) : height(h) {}
	virtual void ShowVirtualAnimalInfo() const {
		cout << "키: " << height << "CM" << endl;
	}
};

class VirtualPig : public VirtualAnimal {
	int weight;
public:
	VirtualPig(int h, int w) : VirtualAnimal(h), weight(w) {}
	void ShowVirtualPigInfo() {
		ShowVirtualAnimalInfo();
		cout << "몸무게: " << weight << "KG" << endl;
	}
};

void ShowConstData(char* str, int& i, int& ii) {
	cout << "String: " << str << endl;
	cout << "Int + Int = " << i + ii << endl;
}

int main() {
	
	cout << "※ C-style Casting" << endl;
	cout << "-----동물 1-----" << endl;
	Animal* pani1 = new Pig(120, 50);
	Pig* ppig1 = (Pig *)pani1;
	ppig1->ShowPigInfo();
	cout << endl << "-----동물 2-----" << endl;
	Animal* pani2 = new Animal(150);
	Pig* ppig2 = (Pig*)pani2;
	ppig2->ShowPigInfo();
	cout << endl << "-----동물 3-----" << endl;
	Pig* ppig3 = new Pig(100, 45);
	Animal* pani3 = (Animal *)ppig3;
	pani3->ShowAnimalInfo();

	cout << endl << "1. Dynamic Casting" << endl;
	cout << "-----동물 1-----" << endl;
	cout << "Animal * pani1_1 = new Pig(120, 50);" << endl;
	cout << "Pig * ppig1_1 = dynamic_cast<Pig*>(pani1_1);  // error!" << endl;
	cout << "ppig1_1->ShowPigInfo();" << endl;
	cout << endl << "-----동물 2-----" << endl;
	cout << "Animal * pani1_2 = new Animal(150);" << endl;
	cout << "Pig * ppig1_2 = dynamic_cast<Pig*>(pani1_2);  // error!" << endl;
	cout << "ppig1_2->ShowPigInfo();" << endl;
	cout << endl << "-----동물 3-----" << endl;
	Pig* ppig1_3 = new Pig(100, 45);
	Animal* pani1_3 = dynamic_cast<Animal *>(ppig1_3);
	pani1_3->ShowAnimalInfo();

	cout << endl << "※ Dynamic Casting with Polymorphic Class" << endl;
	cout << "-----동물 1-----" << endl;
	VirtualAnimal* vpani1 = new VirtualPig(120, 50);
	VirtualPig* vppig1 = dynamic_cast<VirtualPig*>(vpani1);
	vppig1->ShowVirtualPigInfo();
	try {
		cout << endl << "-----동물 2-----" << endl;
		VirtualAnimal* vpani2 = new VirtualAnimal(150);
		VirtualPig* vppig2 = dynamic_cast<VirtualPig*>(vpani2);
		if (vppig2 == NULL)
			throw vppig2;
		vppig2->ShowVirtualPigInfo();
	}
	catch (VirtualPig * NullPtr) {
		cout << "◆ WARNING: NULL POINTER! ◆" << endl;
	}
	cout << endl << "-----동물 3-----" << endl;
	VirtualPig* vppig3 = new VirtualPig(100, 45);
	VirtualAnimal* vpani3 = dynamic_cast<VirtualAnimal*>(vppig3);
	vpani3->ShowVirtualAnimalInfo();

	cout << endl << "2. Static Casting" << endl;
	cout << "-----동물 1-----" << endl;
	Animal* pani2_1 = new Pig(120, 50);
	Pig* ppig2_1 = static_cast<Pig *>(pani2_1);
	ppig2_1->ShowPigInfo();
	cout << endl << "-----동물 2-----" << endl;
	Animal* pani2_2 = new Animal(150);
	Pig* ppig2_2 = static_cast<Pig*>(pani2_2);
	ppig2_2->ShowPigInfo();
	cout << endl << "-----동물 3-----" << endl;
	Pig* ppig2_3 = new Pig(100, 45);
	Animal* pani2_3 = static_cast<Animal *>(ppig2_3);
	pani2_3->ShowAnimalInfo();

	cout << endl << "※ static_cast를 이용한 자료형 변환 계산" << endl;
	double a = static_cast<double>(20) / 3;
	cout << "(double) 20 / 3 = " << a << endl;

	cout << endl << "3. Const Casting" << endl;
	const char * name3 = "홍길동";
	const int& num3_1 = 100;
	const int& num3_2 = 200;
	
	cout << "ShowConstData(name, num3_1, num3_2);  // error!" << endl;
	ShowConstData(const_cast<char *>(name3), const_cast<int&>(num3_1), const_cast<int&>(num3_2));

	cout << endl << "4. Reinterpret Casting" << endl;

	int renum = 0x12345678;
	char* ptr = reinterpret_cast<char*>(&renum);
	for(int i=0; i<sizeof(renum); i++)
		cout << hex << "0x" << static_cast<int>(*(ptr+i)) << endl;
	short* pptr = reinterpret_cast<short*>(ptr);
	for (int i = 0; i < sizeof(renum)/2; i++)
		cout << hex << "0x" << static_cast<int>(*(pptr + i)) << endl;


	return 0;
}
