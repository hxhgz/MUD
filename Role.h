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
	void setHealth_max(int hp_m);//保存用

	int getHealth();
	void setHealth(int hp);//保存用

	int getMp();
	void setMp(int intf);//保存用


	int getAttack();
	void setAttack(int a);//保存用



	int getDefend();
	void setDefend(int d);

	int getMoney();
	void setMoney(int m);//保存用

	int getMapId();
	void setMapId(int NewMapId);//保存用

	int getStory();
	void setStory(int s);//保存用

	Skill getSkill();
	void setSkill(Skill& newSkill);//保存用

	void addSaveGoodsToBag(int goodId, int num);//保存用

	Bag getBag();
	void showBag();
	int getBagWhichGoodsId(int whichGoods);			//得到背包里第whichGoods件物品
	int getBagWhichGoodsNum(int whichGoods);
	//显示背包
	void addGoodsToBag(int* goodsId, int* num);//加入背包,重载应对两种情况
	void addGoodsToBag(int goodsId, int num);

	bool subGoodsToBag(int goodsId, int num);	//减少背包里的物品

	void setBag(Bag bags);

	void savePlayerBag();		//用来单独保存背包
	//int** getBagSave();
	void newBag();

	void showRole();//人物属性 当前装备
	bool showSkill();//显示秘籍,返回是否可以使用技能

	double useSkill();		//使用秘籍,返回秘籍的攻击力加成
	void useDrug();			//使用药品

	int getWeapon();//武器
	void setWeapon(int w);//保存用

	int getArmor();//护甲
	void setArmor(int a);//保存用

	void showEquip();//展示当前装备
	void wearEquip(int id);//穿上装备
	void removeEquip(int id);//脱下装备




private:
	string name;
	int type;
	int health_max;
	int health;
	int defend;//护甲值
	int Mp;//内力值,不设上限

	int attack;


	int money;
	Bag bag;			//背包
	//int bag[20];
	int mapId;			//记录玩家当前所在地
	Skill skill;		//他所拥有的技能
	
	int story = 0;//剧情节点
	int weapon = -1;//当前武器id  默认-1为无
	int armor = -1; //当前护甲id
	
				  //物品实例化
	goods goods[21] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };

};
#endif