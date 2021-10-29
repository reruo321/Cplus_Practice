#include "FruitCounter.h"

int main() {
	FruitCounter counter;

	cout << "※※※오렌지를 분류합니다.※※※" << endl << endl;

	counter.AddItem(new Orange("미국", 150, 7));
	Orange * o = new Orange("브라질", 100, 6);
	o->ShowInfo();
	o->AddFruit(20);
	cout << "   ▽" << endl << endl;
	o->ShowInfo();
	counter.AddItem(o);
	
	cout << "※※※귤 상자를 정리합니다.※※※" << endl << endl;
	Gyul* g = new Gyul("제주도", 20, 3, 20);
	g->ShowInfo();
	g->AddBox(10);
	cout << "   ▽" << endl << endl;
	g->ShowInfo();
	counter.AddItem(g);

	cout << "※※※망고를 분류합니다.※※※" << endl << endl;
	counter.AddItem(new Mango("필리핀", 80, SUGAR::VERY_HIGH));
	counter.AddItem(new Mango("타이", 100, SUGAR::MIDDLE));
	counter.AddItem(new Mango("수단", 120, SUGAR::HIGH));

	cout << "※※※과일을 모두 확인했습니다.※※※" << endl << endl;
	counter.ShowAllFruitInfo();
	counter.GetTotalItem();
	counter.GetTotalPrice();

	return 0;
}