#ifndef SKILL_H
#define SKILL_H

#include <string>
#include <vector>
#include "Enemy.h"


class Skill {
	public:
		Skill();
		~Skill();
		//������ü�����Ϣ
		string getName(int Id);		//�õ��ؼ�����
		string getDesc(int Id);		//�õ��ؼ�����
		int getType(int Id);		//�õ��ؼ�����
		int getNeedMp(int Id);		//�õ��ؼ�����
		double getAttack(int Id);	//�õ��ؼ��Ĺ�����


		

protected:
		//ʹ�������洢������Ϣ
		vector<string> skillName;
		vector<string> skillDesc;
		vector<int> skillId;
		vector<int> skillType;
		vector<int> skillNeedMp;
		vector<double> skillAttack;


		

};
//�������м���
class Role_Skill :public Skill {
public:
	Role_Skill();
	bool ifHaveSkill(int Id);	//�ж��Ƿ����ؼ�
private:
	vector<int> skill_Id;

};

#endif // SKILL_H