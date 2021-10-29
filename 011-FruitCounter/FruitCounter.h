#pragma once
#include "Fruit.h"
#include <iostream>

class FruitCounter {
	Fruit** fruitList = new Fruit*[100];
	int itemNum;
public:
	FruitCounter() : itemNum(0){}
	void AddItem(Fruit * fruit){
		fruitList[itemNum++] = fruit;
	}
	void ShowAllFruitInfo() const {
		for (int i = 0; i < itemNum; i++)
			fruitList[i]->ShowInfo();
	}
	void GetTotalItem() const {
		cout << "품목 개수: " << itemNum << "종" << endl;
	}
	void GetTotalPrice() const {
		int sum = 0;
		for (int i = 0; i < itemNum; i++)
			sum += fruitList[i]->GetPrice();
		cout << "과일 총 가격: " << sum << endl;
	}
	~FruitCounter() {
		for (int i = 0; i < itemNum; i++)
			delete fruitList[i];
	}
};