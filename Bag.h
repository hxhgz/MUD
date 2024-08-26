
#ifndef bag_H
#define bag_H


#include <map>  
#include "goods.h"
class Bag {
public:
	Bag();
	~Bag();
	void showbags();//背包初始化的展示
	void showdrugs();
	void showgoods(int* goodsId, int* num);
	void showgoods(int goodsId, int num);//重载应对不同情况，展示物品ID，名称，数量
	int getgoodnumber();//得到物品数量
	int getWhichGoodsId(int whichGoods);			//得到背包里第whichGoods件物品的Id
	int getWhichGoodsNum(int whichGoods);	//得到背包里第whichGoods件物品的数量
	void addgoods(int id, int num);
	bool reducegoods(int id, int num);
	bool isUseDrug();
	bool ischangeArmor();
	void savebag();			//最后保存游戏时单独将物品存入一个数组
	//int** getSaveBag();		//得到保存物品的数组
	map<int, int> getMapBags();

private:
	map<int, int> bags;
	int savegoods[27][2];		//用来Save物品的数组
	//物品实例化
	Goods goods[27] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
};
#endif 
