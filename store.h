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



	goods goods[21] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
};
#