#include"bag.h"
#include<iostream>
#include<iomanip>
using namespace std;
bag::bag() {
	savegoods[20][2] = 0;
}
bag::~bag() {}
void bag::showbags() {
	if (bags.begin() == bags.end())
		cout << "当前背包无物品！" << endl;
	else {
		cout << "背包:" << endl;
		cout << "ID     物品名称     数量" << endl;
		map<int, int>::iterator iter;//创建容器和迭代器，iter的作用是用来遍历背包里的物品，map储存的是id和数量
		for (iter = bags.begin(); iter != bags.end(); ++iter) {
			cout << left << setw(9) << goods[iter->first].getGoodsId() << setw(9) << goods[iter->first].getName() << setw(2) << "/t" << iter->second << endl;
		}
	}
}
void bag::showgoods(int* goodsId, int* num) {

			for (int i = 0; goodsId[i] >= 0; i++)
				cout << i + 1 << "." << setw(10) << left << goods[goodsId[i]].getName() << num[i] << "件" << endl;
			cout << endl;
	}
void bag::showgoods(int goodsId, int num) {
	cout << 1 << "." << setw(10) << left << goods[goodsId].getName() << num << "件" << endl;
	cout << endl;
}

void bag::addgoods(int id, int num) {
	if (bags.count(id))
	{
		bags[id] += num;
	}
	else
	{
		bags.insert(pair<int, int>(id, num));
	}
	
}//id存在，即添加对应数量，不存在就创建新的键值对
void bag::savebag() {
	map<int, int>::iterator iter;
	for (iter = bags.begin(); iter != bags.end(); ++iter) {
		int i = 0;
		savegoods[i][0] = goods[iter->first].getGoodsId();
		savegoods[i][1] = iter->second;
		i++;
	}
}
bool bag::reducegoods(int id, int num) {
	map<int, int>::iterator iter;
	if (bags.find(id) == bags.end())
		return false;
	else {
		if (num > iter->second)
		num = iter->second; // 如果尝试减少的数量超过当前数量，则只减少当前数量的全部  

		bags[id] -= num;
		if (bags[id] <= 0)
			bags.erase(id);
		return true;
	}
}

//void Bag::operator=(Bag bag){}

map<int, int> bag::getMapBags()
{
	return bags;
}

int bag::getgoodnumber() {  //返回背包里物品的数量
	return bags.size();
}

int bag::getWhichGoodsId(int whichGoods) {
	map<int, int>::iterator iter;
	iter = bags.begin();
	for (; whichGoods > 1; whichGoods--)
		iter++;
	return  goods[iter->first].getGoodsId();

}

int bag::getWhichGoodsNum(int whichGoods) {
	map<int, int>::iterator iter;
	for (iter = bags.begin(); whichGoods > 1; whichGoods--)
		iter++;
	return  iter->second;
}
bool bag::isUseDrug() {
	map<int, int>::iterator iter;
	for (iter = bags.begin(); iter != bags.end(); ++iter) {
		if (goods[iter->first].getGoodsId() == 16 || goods[iter->first].getGoodsId() == 17 || goods[iter->first].getGoodsId() == 18 || goods[iter->first].getGoodsId() == 19 || goods[iter->first].getGoodsId() == 20)
			return true;
	}
	return false;
}//检测是否吃药
bool bag::ischangeArmor() {
	map<int, int>::iterator iter;
	for (iter = bags.begin(); iter != bags.end(); ++iter) {
		if (goods[iter->first].getGoodsId() == 5 || goods[iter->first].getGoodsId() == 6 || goods[iter->first].getGoodsId() == 7 || goods[iter->first].getGoodsId() == 8) {
			return true;
	}
	return false;

}//检测是否换甲