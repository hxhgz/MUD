#ifndef STORE_H
#define STORE_H




#include<iostream>
#include<map>
#include"Goods.h"
#include"Bag.h"
#include"Role.h"
using namespace std;
class Store {
public:
	Store();
	~Store();
	void showStore();
	Role Buywares(Role player);
	Role Sellwares(Role player);
private:
	map<int, int> stores;

	Goods goods[27] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26 };
};

#endif // !STORE_H
