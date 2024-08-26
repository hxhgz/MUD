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
//Goods goods[20] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };































#endif