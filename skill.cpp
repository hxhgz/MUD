#include <iostream>
#include "Skill.h"

using namespace std;

Skill::Skill() {

	//��ʼ�����м������ơ����������͡���Ҫ��MP��������
	skillName.push_back("�ν�ʽ");
	skillName.push_back("��ɽ��ţ");
	skillName.push_back("��������");
	skillName.push_back("����������");
	skillName.push_back("�����");
	skillName.push_back("���¾Ž�");
	skillName.push_back("��������");


	skillDesc.push_back("��������");
	skillDesc.push_back("����ֱ�ӹ�����������");
	skillDesc.push_back("�����˹��������Թ�");
	skillDesc.push_back("������ɿ��Զ�����������");
	skillDesc.push_back("ʦ�л���а�񣬴����һ�����ָ���");
	skillDesc.push_back("��������ǿ��ʽ���ഫ�Ž�һ��������һ��");
	skillDesc.push_back("�����������������ʽ����������");

	/*skillType.push_back(2);
	skillType.push_back(2);
	skillType.push_back(2);
	skillType.push_back(2);
	skillType.push_back(2);
	skillType.push_back(2);
	skillType.push_back(2);*/

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
//��ɺ�����ü�����Ϣ����

string Skill::getName(int Id) {
	return skillName[Id];
}
string Skill::getDesc(int Id) {
	return skillDesc[Id];
}
int Skill::getType(int Id) {
	return skillType[Id];
}
int Skill::getNeedMp(int Id)
{
	return skillNeedMp[Id];
}
double Skill::getAttack(int Id) {
	return skillAttack[Id];
}
bool Role_Skill::ifHaveSkill(int Id) {
	bool flag = false;
	for (int i = 0; i < skill_Id.size(); i++) {
		if (skillId[i] == Id) {
			flag = true;
			break;
		}
	}
	return flag;
}

	
//�����洢���еļ���
Role_Skill::Role_Skill() {

	/*vector<string> skill_Name;

	vector<string> skill_Desc;

	vector<int> skill_Type;

	vector<int> skill_NeedMp;

	vector<double> skill_Attack;*/

}
