#include "Enemy.h"
#include <iostream>
#include <string>

using namespace std;

Enemy::Enemy() {};

Enemy::Enemy(/*int enemyId,*/string name, int health, int armor, int attackPower, int money)
	:/*enemyId(enemyId),*/ name(name), health(health), armor(armor), attackPower(attackPower),money(money) {};

void Enemy::displayInfo() const {
	cout << endl << "��ǰ����:" << name << endl;
	cout << "����ֵ:" << health << '\t';
	cout << "����ֵ:" << armor << endl;
	cout << "����ֵ:" << attackPower << endl;
};

int Enemy::getMoney() const {
	return money;
};			

Enemy_npc::Enemy_npc(/*int enemyId,*/ string name, int health, int internalEnergy, int armor, int attackPower, int money, const Skill& skill)
	:Enemy(/*enemyId,*/ name, health, armor, attackPower, money), internalEnergy(internalEnergy),skill(skill){};

void Enemy_npc::displayInfo() const {
	cout << endl << "��ǰ����:" << name << endl;
	cout << "����ֵ:" << health << '\t';
	cout << "����ֵ:" << armor << endl;
	cout << "����ֵ:" << attackPower << '\t';
	cout << "����ֵ:" << internalEnergy << endl;
};

Enemy_Boss::Enemy_Boss(/*int enemyId,*/ string name, int health, int armor, int attackPower, int money, const vector<Skill>& skills)
	:Enemy(/*enemyId,*/ name, health, armor, attackPower, money),skills(skills) {};


/*

��������(��main������):

Skill npcSkill1 = {"����ȭ", 10};
Skill npcSkill2 = {"������", 17};
Skill npcSkill3 = {"��ָ��ͨ", 28};
vector<Skill> bossSkills = {
	{"������Ϣ", 33},{"��ҧ", 23}
};

//��������Ϊ	���֣�Ѫ�������ף������˺���������
	Enemy enemy1("��������",100, 50��5��50);
	Enemy enemy2("��������",150, 15��15��125);
	Enemy enemy3("������",225, 25��20��275);
	Enemy enemy4("�޸�˹",300, 30��25��500);

//��������Ϊ	���֣�Ѫ�������������ף������˺���������,�ؼ�
	Enemy_npc npc1("����", 100, 50, 10, 5, 100, npcSkill);
	Enemy_npc npc2("���", 100, 50, 30, 20, 175, npcSkill);
	Enemy_npc npc3("������", 100, 50, 50, 35, 325, npcSkill);

//��������Ϊ	���֣�Ѫ�������ף������˺���������,�ؼ�
	Enemy_Boss boss("����", 500, 100, 50, 1000, bossSkills);

*/