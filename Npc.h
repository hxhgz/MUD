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
	int goodId;//npc������Ʒ��Ӧ��Id��,Ĭ��-1Ϊ��
	int goodNum;//npc������Ʒ����
	int money;//npc����Ǯ
	Goods goods[21] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };

};

#endif
