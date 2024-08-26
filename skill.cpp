
#include <iostream>
#include "Skill.h"

using namespace std;

Skill::Skill() {

	//初始化所有技能名称、描述、类型、需要的MP、攻击力
	skillName.push_back("拔剑式");
	skillName.push_back("隔山打牛");
	skillName.push_back("葵花宝典");
	skillName.push_back("化骨绵绵掌");
	skillName.push_back("蛤蟆神功");
	skillName.push_back("独孤九剑");
	skillName.push_back("如来神掌");


	skillDesc.push_back("基础剑招");
	skillDesc.push_back("可以直接攻击敌人内脏");
	skillDesc.push_back("欲练此功，必先自宫");
	skillDesc.push_back("练至大成可以洞穿敌人心脏");
	skillDesc.push_back("师承火云邪神，挫败了一众武林高手");
	skillDesc.push_back("剑术的最强招式，相传九剑一出，必有一死");
	skillDesc.push_back("从天外下落而来的招式，威力极大");



	skillId.push_back(9);
	skillId.push_back(10);
	skillId.push_back(11);
	skillId.push_back(12);
	skillId.push_back(13);
	skillId.push_back(14);
	skillId.push_back(15);



	skillNeedMp.push_back(5);
	skillNeedMp.push_back(10);
	skillNeedMp.push_back(10);
	skillNeedMp.push_back(40);
	skillNeedMp.push_back(60);
	skillNeedMp.push_back(90);
	skillNeedMp.push_back(100);

	skillAttack.push_back(10);
	skillAttack.push_back(20);
	skillAttack.push_back(15);
	skillAttack.push_back(40);
	skillAttack.push_back(70);
	skillAttack.push_back(100);
	skillAttack.push_back(300);

};
//完成函数获得技能信息功能

int Skill::getSkillNum() {
	return skill_Id.size();
}
int Skill::getSkillId(int num) {
	return skill_Id[num];
}
string Skill::getName(int Id) {
	return skillName[Id];
}
string Skill::getDesc(int Id) {
	return skillDesc[Id];
}

int Skill::getNeedMp(int Id)
{
	return skillNeedMp[Id];
}
double Skill::getAddAttack(int Id) {
	return skillAttack[Id];
}
bool Skill::IfHaveSkill(int Id) {
	bool flag = false;
	for (int i = 0; i < skill_Id.size(); i++) {
		if (skillId[i] == Id) {
			flag = true;
			break;
		}
	}
	return flag;
}



