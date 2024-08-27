
#include <iostream>
#include<algorithm>
#include "Skill.h"

using namespace std;

Skill::Skill() {

	//初始化所有技能名称、描述、类型、需要的MP、攻击力
	//主角能买的秘籍
	skillName.push_back("拔剑式");
	skillName.push_back("隔山打牛");
	skillName.push_back("葵花宝典");
	skillName.push_back("化骨绵绵掌");
	skillName.push_back("蛤蟆神功");
	skillName.push_back("独孤九剑");
	skillName.push_back("如来神掌");
	//由敌人掉的秘籍
	skillName.push_back("照神经");
	skillName.push_back("重明万方");
	skillName.push_back("呼星唤魅");
	skillName.push_back("漆骨生花");
	skillName.push_back("冰寒露华");
	skillName.push_back("风雷万象");

	//主角能买的秘籍
	skillDesc.push_back("基础剑招。");
	skillDesc.push_back("可以直接攻击敌人内脏。");
	skillDesc.push_back("欲练此功，必先自宫。");
	skillDesc.push_back("练至大成可以洞穿敌人心脏。");
	skillDesc.push_back("师承火云邪神，挫败了一众武林高手。");
	skillDesc.push_back("剑术的最强招式，相传九剑一出，必有一死。");
	skillDesc.push_back("从天外下落而来的招式，威力极大。");
	//由敌人掉的秘籍
	skillDesc.push_back("高立修习多年的功法，练成后内力深厚，武力高强。");
	skillDesc.push_back("丽泽周群品，重明照万方。");
	skillDesc.push_back("呼星召鬼歆杯盘，山魅食时人森寒。");
	skillDesc.push_back("漆灰骨末丹水沙，凄凄骨血生桐花。");
	skillDesc.push_back("玉碗冰寒滴露华，粉融香雪透轻纱。");
	skillDesc.push_back("风雷开万象，散天影、入虚坛。");


	//主角能买的秘籍
	skill_Id.push_back(9);
	skill_Id.push_back(10);
	skill_Id.push_back(11);
	skill_Id.push_back(12);
	skill_Id.push_back(13);
	skill_Id.push_back(14);
	skill_Id.push_back(15);
	//由敌人掉的秘籍
	skill_Id.push_back(21);
	skill_Id.push_back(22);
	skill_Id.push_back(23);
	skill_Id.push_back(24);
	skill_Id.push_back(25);
	skill_Id.push_back(26);


	//主角能买的秘籍
	skillNeedMp.push_back(5);
	skillNeedMp.push_back(10);
	skillNeedMp.push_back(10);
	skillNeedMp.push_back(40);
	skillNeedMp.push_back(60);
	skillNeedMp.push_back(90);
	skillNeedMp.push_back(100);
	//由敌人掉的秘籍
	skillNeedMp.push_back(10);
	skillNeedMp.push_back(20);
	skillNeedMp.push_back(40);
	skillNeedMp.push_back(60);
	skillNeedMp.push_back(50);
	skillNeedMp.push_back(50);

	//主角能买的秘籍
	skillAttack.push_back(10);
	skillAttack.push_back(20);
	skillAttack.push_back(15);
	skillAttack.push_back(40);
	skillAttack.push_back(70);
	skillAttack.push_back(100);
	skillAttack.push_back(300);
	//由敌人掉的秘籍
	skillAttack.push_back(50);
	skillAttack.push_back(100);
	skillAttack.push_back(400);
	skillAttack.push_back(600);
	skillAttack.push_back(500);
	skillAttack.push_back(500);

};
//完成函数获得技能信息功能

//Id代表秘籍的标号，对应goods里面的9-15和21-26，但是访问其他数组时的索引值应该是从0开始，所以要这样处理
//Id是由我们处理，应该不会出现其他输入情况，后面若出现问题再会看
void Skill::SortSkillId() {
	sort(skill_Id.begin(), skill_Id.end());
}

int Skill::getSkillNum(){
	
	return skill_Id.size();
}

int Skill::getSkillId(int num) {
	return skill_Id[num];
}


string Skill::getName(int Id) {
	 if (Id < 16) {
		 return skillName[Id-9];//Id代表秘籍的标号，对应goods里面的9-15和21-26，但是访问其他数组时的索引值应该是从0开始，所以要这样处理
	}
	else {
		 return skillName[Id-14];
	}
}

string Skill::getDesc(int Id) {
	
	if (Id < 16) {
		return skillDesc[Id-9];//Id代表秘籍的标号，对应goods里面的9-15和21-26，但是访问其他数组时的索引值应该是从0开始，所以要这样处理
	}
	else {
		return skillDesc[Id-14];
	}
}

int Skill::getNeedMp(int Id)
{
	
	if (Id < 16) {
		return skillNeedMp[Id-9];//Id代表秘籍的标号，对应goods里面的9-15和21-26，但是访问其他数组时的索引值应该是从0开始，所以要这样处理
	}
	else {
		return skillNeedMp[Id-14];
	}
}
double Skill::getAddAttack(int Id) {
	
	if (Id < 16) {
		return skillAttack[Id-9];//Id代表秘籍的标号，对应goods里面的9-15和21-26，但是访问其他数组时的索引值应该是从0开始，所以要这样处理
	}
	else {
		return skillAttack[Id-14];
	}
}

bool Skill::IfHaveSkill(int Id) {
	if (Id < 16) {//Id代表秘籍的标号，对应goods里面的9-15和21-26，但是访问其他数组时的索引值应该是从0开始，所以要这样处理
		Id -= 9;
	}
	if(Id>20){
		Id -= 14;
	}
	bool flag = false;
	for (int i = 0; i < skill_Id.size(); i++) {
		if (skill_Id[i] == Id) {
			flag = true;
			break;
		}
	}
	return flag;
}



