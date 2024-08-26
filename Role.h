#ifndef ROLE_H
#define ROLE_H

#include <string>
#include "Skill.h"
#include "Bag.h"
#include"Goods.h"
//#include"Task.h"
using namespace std;

class Role {
public:
	Role(int type);
	~Role();

	void operator =(Role player);

	string getName();
	int getType();

	int getHealth_max();
	void setHealth_max(int hp_m);//������

	int getHealth();
	void setHealth(int hp);//������

	int getMp();
	void setMp(int intf);//������


	int getAttack();
	void setAttack(int a);//������



	int getDefend();
	void setDefend(int d);

	int getMoney();
	void setMoney(int m);//������

	int getMapId();
	void setMapId(int NewMapId);//������

	int getStory();
	void setStory(int s);//������

	Skill getSkill();
	void setSkill(Skill& newSkill);//������

	void addSaveGoodsToBag(int goodId, int num);//������

	Bag getBag();
	void showBag();
	int getBagWhichGoodsId(int whichGoods);			//�õ��������whichGoods����Ʒ
	int getBagWhichGoodsNum(int whichGoods);
	//��ʾ����
	void addGoodsToBag(int* goodsId, int* num);//���뱳��,����Ӧ���������
	void addGoodsToBag(int goodsId, int num);

	bool subGoodsToBag(int goodsId, int num);	//���ٱ��������Ʒ

	void setBag(Bag bags);

	void savePlayerBag();		//�����������汳��
	//int** getBagSave();
	void newBag();

	void showRole();//�������� ��ǰװ��
	bool showSkill();//��ʾ�ؼ�,�����Ƿ����ʹ�ü���

	double useSkill();		//ʹ���ؼ�,�����ؼ��Ĺ������ӳ�
	void useDrug();			//ʹ��ҩƷ

	int getWeapon();//����
	void setWeapon(int w);//������

	int getArmor();//����
	void setArmor(int a);//������

	void showEquip();//չʾ��ǰװ��
	void wearEquip(int id);//����װ��
	void removeEquip(int id);//����װ��




private:
	string name;
	int type;
	int health_max;
	int health;
	int defend;//����ֵ
	int Mp;//����ֵ,��������

	int attack;


	int money;
	Bag bag;			//����
	//int bag[20];
	int mapId;			//��¼��ҵ�ǰ���ڵ�
	Skill skill;		//����ӵ�еļ���
	
	int story = 0;//����ڵ�
	int weapon = -1;//��ǰ����id  Ĭ��-1Ϊ��
	int armor = -1; //��ǰ����id
	
				  //��Ʒʵ����
	goods goods[21] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };

};
#endif