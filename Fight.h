#pragma once
#ifndef FIGHT_H
#define FIGHT_H

#include "Enemy.h"
#include "Bag.h"
#include "Skill.h"
#include "Role.h"
#include "Goods.h"

class Fight {
public:
	Fight(Role player, Enemy enemy);
	Fight(Role player, Enemy_npc enemy_npc);
	Fight(Role player, Enemy_Boss enemy_Boss);

	~Fight();
	void ShowFight();    //��ʾս��ʱ˫����״̬
	void FightChoice();  //��ɫս��ʱ��ѡ��
	int EnemyFight();    //����ս��ʱ��ѡ��
	int FightJudgement();     //�ж�ս�����
	int GetMoney();      //ս��ʤ����ý�Ǯ
	void GetSkill();	 //ս��ʤ������ؼ�
	int GetIntelnalEngery();		//ս��ʤ���������
	void Fighting();     //ս���ܺ���
private:
	Role player;//ս���Ľ�ɫ
	Enemy& enemy;//ս���Ĺ���
	int round;//�غ���
};

#endif
