#ifndef NPC_H
#define NPC_H
#include<string>
#include"Role.h"

class Npc {
public:
	Npc(int num);
	~Npc();

	string getName();
	Role chat(Role player);
	int getGoodsId();
	int getGoodsNum();
	int getMoney();
	bool isChatted(int whichNpc);

private:
	string name;
	int type;
	int goodId;//npc给的物品对应的Id号,默认-1为无
	int goodNum;//npc给的物品数量
	int money;//npc给的钱
	Goods goods[21] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };

};

#endif
