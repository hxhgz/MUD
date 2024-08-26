
#ifndef bag_H
#define bag_H


#include <map>  
#include "goods.h"
class bag {
public:
	bag();
	~bag();
	void showbags();//������ʼ����չʾ
	void showgoods(int* goodsId, int* num);
	void showgoods(int goodsId, int num);//����Ӧ�Բ�ͬ�����չʾ��ƷID�����ƣ�����
	int getgoodnumber();//�õ���Ʒ����
	int getWhichGoodsId(int whichGoods);			//�õ��������whichGoods����Ʒ��Id
	int getWhichGoodsNum(int whichGoods);	//�õ��������whichGoods����Ʒ������
	void addgoods(int id, int num);
	bool reducegoods(int id, int num);
	bool isUseDrug();
	bool ischangeArmor();
	void savebag();			//��󱣴���Ϸʱ��������Ʒ����һ������
	//int** getSaveBag();		//�õ�������Ʒ������
	map<int, int> getMapBags();

private:
	map<int, int> bags;
	int savegoods[20][2];		//����Save��Ʒ������
	//��Ʒʵ����
	goods goods[20] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
};
#endif 