#include "Enemy.h"
#include <iostream>
#include <string>

using namespace std;

Enemy::Enemy() {};

Enemy::Enemy(/*int enemyId,*/string name, int health, int armor, int attackPower, int money)
	:/*enemyId(enemyId),*/ name(name), health(health), armor(armor), attackPower(attackPower),money(money) {};

void Enemy::displayInfo() const {
	cout << endl << "当前怪物:" << name << endl;
	cout << "生命值:" << health << '\t';
	cout << "护甲值:" << armor << endl;
	cout << "攻击值:" << attackPower << endl;
};

int Enemy::getMoney() const {
	return money;
};			

Enemy_npc::Enemy_npc(/*int enemyId,*/ string name, int health, int internalEnergy, int armor, int attackPower, int money, const Skill& skill)
	:Enemy(/*enemyId,*/ name, health, armor, attackPower, money), internalEnergy(internalEnergy),skill(skill){};

void Enemy_npc::displayInfo() const {
	cout << endl << "当前敌人:" << name << endl;
	cout << "生命值:" << health << '\t';
	cout << "护甲值:" << armor << endl;
	cout << "攻击值:" << attackPower << '\t';
	cout << "内力值:" << internalEnergy << endl;
};

Enemy_Boss::Enemy_Boss(/*int enemyId,*/ string name, int health, int armor, int attackPower, int money, const vector<Skill>& skills)
	:Enemy(/*enemyId,*/ name, health, armor, attackPower, money),skills(skills) {};


/*

创建敌人(在main函数中):

Skill npcSkill1 = {"空明拳", 10};
Skill npcSkill2 = {"劈空掌", 17};
Skill npcSkill3 = {"弹指神通", 28};
vector<Skill> bossSkills = {
	{"烈焰吐息", 33},{"龙咬", 23}
};

//属性依次为	名字，血量，护甲，攻击伤害，掉落金币
	Enemy enemy1("雷霆巨蜥",100, 50，5，50);
	Enemy enemy2("玄冰麒麟",150, 15，15，125);
	Enemy enemy3("炽焰凤凰",225, 25，20，275);
	Enemy enemy4("修格斯",300, 30，25，500);

//属性依次为	名字，血量，内力，护甲，攻击伤害，掉落金币,秘籍
	Enemy_npc npc1("高立", 100, 50, 10, 5, 100, npcSkill);
	Enemy_npc npc2("麻锋", 100, 50, 30, 20, 175, npcSkill);
	Enemy_npc npc3("西门玉", 100, 50, 50, 35, 325, npcSkill);

//属性依次为	名字，血量，护甲，攻击伤害，掉落金币,秘籍
	Enemy_Boss boss("青龙", 500, 100, 50, 1000, bossSkills);

*/