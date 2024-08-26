#ifndef goods_H
#define goods_H
#include <string>
#include <iostream>
#include <vector>

using namespace std;
class goods {
public:
	goods(int id);
	~goods();

	string getName();
	int getGoodsId();
	string getDesc();
	int getType();
	int getAddAttack();
	int getAddHP();
	int getAddMP();
	int getPriceSell();
	int getPriceBuy();
	void showGoods();
	int getAddArmor();
private:
	string name;	//物品名称
	int goodsId;
	string desc;	//物品描述
	int type;//物品属性：武器-0，防具-1，药品-2
	int addAttack = 0;	//增加攻击
	int addArmor = 0;	//增加防御
	int addMP = 0; //增加内力
	int addHP = 0;//增加血量
	int priceSell;
	int priceBuy;
};

//
//Goods goods[20] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };































#endif