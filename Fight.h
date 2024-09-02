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
	void ShowFight();    //显示战斗时双方的状态
	void FightChoice();  //角色战斗时的选择
	int EnemyFight();    //敌人战斗时的选择
	int FightJudgement();     //判断战斗情况
	int GetMoney();      //战斗胜利获得金钱
	void GetSkill();	 //战斗胜利获得秘籍
	int GetIntelnalEngery();		//战斗胜利获得内力
	void Fighting();     //战斗总函数
private:
	Role player;//战斗的角色
	Enemy& enemy;//战斗的怪物
	int round;//回合数
};

#endif
