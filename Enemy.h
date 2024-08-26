#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include <vector>
#include <string>

using namespace std;

class Enemy {
public:
	Enemy();
	Enemy(/*int enemyId,*/string name,int health,int armor,int attackPower,int money);
	virtual ~Enemy() = default;
	virtual void displayInfo() const;
	int getMoney() const;			//掉落金钱
	int getArmor() const;
	void setArmor(int armor);
protected:
	//int enemyId;
	string name;
	int health;
	int armor;  //护甲值
	int attackPower;
	int money;  //掉落的金钱

	struct Skill {
		string name;
		int attackPower;
	};
};

class Enemy_npc :public Enemy {
public:
	Enemy_npc(/*int enemyId,*/ string name, int health, int internalEnergy, int armor, int attackPower, int money, const Skill& skill);
	void displayInfo() const;
private:
	int internalEnergy;   //内力
	Skill skill;  //拥有的秘籍
};

class Enemy_Boss :public Enemy {
public:
	Enemy_Boss(/*int enemyId,*/ string name, int health, int armor, int attackPower, int money, const vector<Skill>& skills);
private:
	vector<Skill> skills;  //拥有的秘籍
};

//小怪和大怪没有特殊的属性，所以就当作Enemy类
//考虑到是在main中创建敌人，可能不需要enemyid，就暂时注释掉

#endif;
