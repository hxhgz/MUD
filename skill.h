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
		int getType(int Id);		//得到秘籍类型
		int getNeedMp(int Id);		//得到秘籍耗蓝
		double getAttack(int Id);	//得到秘籍的攻击力


		

protected:
		//使用容器存储技能信息
		vector<string> skillName;
		vector<string> skillDesc;
		vector<int> skillId;
		vector<int> skillType;
		vector<int> skillNeedMp;
		vector<double> skillAttack;


		

};
//人物现有技能
class Role_Skill :public Skill {
public:
	Role_Skill();
	bool ifHaveSkill(int Id);	//判断是否有秘籍
private:
	vector<int> skill_Id;

};

#endif // SKILL_H