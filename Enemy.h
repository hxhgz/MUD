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
	int getMoney() const;			//�����Ǯ

protected:
	//int enemyId;
	string name;
	int health;
	int armor;  //����ֵ
	int attackPower;
	int money;  //����Ľ�Ǯ

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
	int internalEnergy;   //����
	Skill skill;  //ӵ�е��ؼ�
};

class Enemy_Boss :public Enemy {
public:
	Enemy_Boss(/*int enemyId,*/ string name, int health, int armor, int attackPower, int money, const vector<Skill>& skills);
private:
	vector<Skill> skills;  //ӵ�е��ؼ�
};

//С�ֺʹ��û����������ԣ����Ծ͵���Enemy��
//���ǵ�����main�д������ˣ����ܲ���Ҫenemyid������ʱע�͵�

#endif;