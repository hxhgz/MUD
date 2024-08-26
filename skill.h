#ifndef SKILL_H
#define SKILL_H

#include <string>
#include <vector>
#include "Enemy.h"


class Skill {
public:
	Skill();
	~Skill();
	//函数获得技能信息
	string getName(int Id);		//得到秘籍名字
	string getDesc(int Id);		//得到秘籍描述
	int getSkillId(int num);		//得到秘籍id
	int getNeedMp(int Id);		//得到秘籍耗蓝
	double getAddAttack(int Id);	//得到秘籍的攻击力
	bool IfHaveSkill(int Id);	//判断是否有秘籍
	int getSkillNum();




protected:
	//使用容器存储技能信息
	vector<string> skillName;
	vector<string> skillDesc;
	vector<int> skillId;
	vector<int> skillType;
	vector<int> skillNeedMp;
	vector<double> skillAttack;
	vector<int> skill_Id;



};


#endif // SKILL_H
