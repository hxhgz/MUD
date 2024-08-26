#ifndef MAP_H
#define MAP_H

#include<string>
#include"Enemy.h"
#include"Role.h"
#include"Npc.h"

using namespace std;

class Map {
public:
	Map();			//初始位置在地图的0处
	Map(int pos);	//由参数pos指定所在位置
	~Map();
	void showMap();	//显示地图
	void showRoom();//显示当前房间信息（包括怪物、角色、NPC等信息）
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
	string mapName[10] = { "孔雀山庄","箫月城","拜月教","炎烨岛","锦绣原","幽兰谷","商店","断云峰","终南山","升龙谷" };
	//地图名称数组顺序对应cpp文件中position参数的值分别为0-9
	int mapNum;
	char pos[5][3];//存放*表示当前位置
	int dx;	
	int dy;
	//二维坐标  原点在左下角向上为x轴正方向，向右为y轴正方向
	Npc npc;
};


#endif
