#ifndef MAP_H
#define MAP_H

#include<string>
#include"Enemy.h"
#include"Role.h"
#include"Npc.h"

using namespace std;

class Map {
public:
	Map();			//��ʼλ���ڵ�ͼ��0��
	Map(int pos);	//�ɲ���posָ������λ��
	~Map();
	void showMap();	//��ʾ��ͼ
	void showRoom();//��ʾ��ǰ������Ϣ�����������ɫ��NPC����Ϣ��
	void Store();
	void Move(char order);
	bool isThereFight();
	bool isThereChat();
	int getPosition();

	string getNpcName();
	void setNpc(Npc newNpc);
	Role chatToNpc(Role player);
	int getNpcGoodsId();
	int getNpcGoodsNum();
	string getName();

private:
	string name;
	int position;
	string mapName[10] = { "��ȸɽׯ","���³�","���½�","���ǵ�","����ԭ","������","�̵�","���Ʒ�","����ɽ","������" };
	//��ͼ��������˳���Ӧcpp�ļ���position������ֵ�ֱ�Ϊ0-9
	int mapNum;
	char pos[5][3];//���*��ʾ��ǰλ��
	int dx;	
	int dy;
	//��ά����  ԭ�������½�����Ϊx������������Ϊy��������
	Npc npc;
};


#endif
