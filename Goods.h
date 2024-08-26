#ifndef Goods_H
#define Goods_H
#include <string>
#include <iostream>
#include <vector>

using namespace std;
class Goods {
public:
	Goods(int id);
	~Goods();

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
	string name;	//��Ʒ����
	int goodsId;
	string desc;	//��Ʒ����
	int type;//��Ʒ���ԣ�����-0������-1��ҩƷ-2
	int addAttack = 0;	//���ӹ���
	int addArmor = 0;	//���ӷ���
	int addMP = 0; //��������
	int addHP = 0;//����Ѫ��
	int priceSell;
	int priceBuy;
};

//
//Goods goods[26] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26 };
#endif































