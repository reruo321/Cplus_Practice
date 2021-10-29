#include "FruitCounter.h"

int main() {
	FruitCounter counter;

	cout << "�ءءؿ������� �з��մϴ�.�ءء�" << endl << endl;

	counter.AddItem(new Orange("�̱�", 150, 7));
	Orange * o = new Orange("�����", 100, 6);
	o->ShowInfo();
	o->AddFruit(20);
	cout << "   ��" << endl << endl;
	o->ShowInfo();
	counter.AddItem(o);
	
	cout << "�ءءر� ���ڸ� �����մϴ�.�ءء�" << endl << endl;
	Gyul* g = new Gyul("���ֵ�", 20, 3, 20);
	g->ShowInfo();
	g->AddBox(10);
	cout << "   ��" << endl << endl;
	g->ShowInfo();
	counter.AddItem(g);

	cout << "�ءءظ��� �з��մϴ�.�ءء�" << endl << endl;
	counter.AddItem(new Mango("�ʸ���", 80, SUGAR::VERY_HIGH));
	counter.AddItem(new Mango("Ÿ��", 100, SUGAR::MIDDLE));
	counter.AddItem(new Mango("����", 120, SUGAR::HIGH));

	cout << "�ءءذ����� ��� Ȯ���߽��ϴ�.�ءء�" << endl << endl;
	counter.ShowAllFruitInfo();
	counter.GetTotalItem();
	counter.GetTotalPrice();

	return 0;
}