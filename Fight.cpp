#include "Fight.h"
#include <iostream>
#include <stdlib.h>
//#include <time.h>

using namespace std;

/*
class Fight {
public:
	Fight(Role player, Enemy enemy);
	~Fight();
	void ShowFight();    //��ʾս��ʱ˫����״̬
	void FightChoice();  //��ɫս��ʱ��ѡ��
	int EnemyFight();    //����ս��ʱ��ѡ��
	bool EndFight();     //�ж�ս���Ƿ����
	int GetMoney();      //ս��ʤ����ý�Ǯ
	void GetSkill();	 //ս��ʤ������ؼ�
	int GetIntelnalEngery(Enemy enemy);		//ս��ʤ���������
	void Fighting();     //ս���ܺ���
private:
	Role player;//ս���Ľ�ɫ
	Enemy enemy;//ս���Ĺ���
	int round;//�غ���
};
*/

Fight::Fight(Role player, Enemy enemy) :player(player), enemy(enemy) { round = 1; };
Fight::Fight(Role player, Enemy_npc enemy_npc) : player(player), enemy(enemy_npc) { round = 1; };
Fight::Fight(Role player, Enemy_Boss enemy_Boss) : player(player), enemy(enemy_Boss) { round = 1; };

Fight::~Fight() {};

void Fight::ShowFight() {   //չʾս��ʱ״̬
	player.showRole();
	cout << endl;
	enemy.displayInfo();
	cout << endl << "��ǰΪ��" << round << "�غ�" << endl;
};

void Fight::FightChoice() {         //��ɫս��ѡ��
	int choose = 0;
	cout << "��ѡ��: 1.��ͨ����	2.ʹ���ؼ� 3.ʹ��ҩƷ 4.����" << endl;
	cin >> choose;
	if (choose >= 1 && choose <= 4) {
		switch (choose) {
		case 1:
		{
			if ((enemy.getArmor() - player.getAttack()) > 0) {		//���˻���ֵ���ڽ�ɫ�������
				enemy.setArmor(enemy.getArmor() - player.getAttack());
				cout << "���˵Ļ��׵ֵ�����Ĺ�����" << endl;
				break;
			}
			if ((enemy.getArmor() - player.getAttack()) == 0) {			//���˻���ֵ���ڽ�ɫ�������
				enemy.setArmor(0);
				cout << "���˵Ļ��ױ���ݻ��ˣ�" << endl;
				break;
			}
			if (((enemy.getArmor() - player.getAttack()) < 0) && enemy.getArmor() > 0) {			//���˻���ֵС�ڽ�ɫ���������ԭ������0
				enemy.setArmor(0);
				if (enemy.getHealth() > (player.getAttack() - enemy.getArmor())) {			//��������ֵ���ڽ�ɫ�ݻٻ���������˺�
					enemy.setHealth(enemy.getHealth() - player.getAttack() + enemy.getArmor());
					cout << "��ݻ��˵��˵Ļ��ײ��������" << player.getAttack() - enemy.getArmor() << "���˺���" << endl;
					break;
				}
				else {			//��������ֵС�ڽ�ɫ�ݻٻ���������˺�
					enemy.setHealth(0);
					cout << "���ɱ�˵��ˣ�" << endl;
					break;
				}
			}
			else {			//���˻���ֵ�ڽ�ɫ����ʱ�Ѿ�Ϊ0
				if (enemy.getHealth() > player.getAttack()) {
					enemy.setHealth(enemy.getHealth() - player.getAttack());
					cout << "��Ե��������" << player.getAttack() << "���˺�" << endl;
					break;
				}
				else {			//��������ֵС�ڽ�ɫ�������
					enemy.setHealth(0);
					cout << "���ɱ�˵��ˣ�" << endl;
					break;
				}
			}
			break;
		}
		case 2:
		{
			if (player.showSkill()) {
				double SkillAttack= player.useSkill();			
				if ((enemy.getArmor() - SkillAttack) > 0) {		//���˻���ֵ���ڽ�ɫ�������
					enemy.setArmor(enemy.getArmor() - SkillAttack);
					cout << "���˵Ļ��׵ֵ�����Ĺ�����" << endl;
					break;
				}
				if ((enemy.getArmor() - SkillAttack) == 0) {			//���˻���ֵ���ڽ�ɫ�������
					enemy.setArmor(0);
					cout << "���˵Ļ��ױ���ݻ��ˣ�" << endl;
					break;
				}
				if (((enemy.getArmor() - SkillAttack) < 0) && enemy.getArmor() > 0) {			//���˻���ֵС�ڽ�ɫ���������ԭ������0
					enemy.setArmor(0);
					if (enemy.getHealth() > (SkillAttack - enemy.getArmor())) {			//��������ֵ���ڽ�ɫ�ݻٻ���������˺�
						enemy.setHealth(enemy.getHealth() - SkillAttack + enemy.getArmor());
						cout << "��ݻ��˵��˵Ļ��ײ��������" << SkillAttack - enemy.getArmor() << "���˺���" << endl;
						break;
					}
					else {			//��������ֵС�ڽ�ɫ�ݻٻ���������˺�
						enemy.setHealth(0);
						cout << "���ɱ�˵��ˣ�" << endl;
						break;
					}
				}
				else {			//���˻���ֵ�ڽ�ɫ����ʱ�Ѿ�Ϊ0
					if (enemy.getHealth() > SkillAttack) {
						enemy.setHealth(enemy.getHealth() - SkillAttack);
						cout << "��Ե��������" << SkillAttack << "���˺�" << endl;
						break;
					}
					else {			//��������ֵС�ڽ�ɫ�������
						enemy.setHealth(0);
						cout << "���ɱ�˵��ˣ�" << endl;
						break;
					}
				}
			}
		}
		case 3:
		{
			//player.showDrug();
			player.useDrug();
				break;
		}
		case 4:
		{
			srand((unsigned)time(NULL));
			if (rand() % 100 <= 50) {			//50%�ɹ�
				cout << "����ʧ��!" << endl;
				break;
			}
			else {
				cout << "���ܳɹ�!" << endl;
				round = -1;	//��Ϊս�������ı�׼
				return;		//ֱ����������
			}
			break;
		}
		}
		round++;
	}
	else cout << "��Ч���룬������ѡ��: " << endl;
}

int Fight::EnemyFight() {        //����ս��ѡ��
	int enemyId = enemy.getId();
	int enemyAttack = 0, hurt = 0;
	srand((unsigned)time(NULL));
	if (enemyId > 0 || enemyId < 5) enemyAttack = enemy.getAttack();
	if (enemyId > 4 || enemyId < 8) {
		if (rand() % 100 <= 50) enemyAttack = enemy.getAttack();
		else {
			Enemy_npc* EnemyNPC = dynamic_cast<Enemy_npc*>(&enemy);//����ת������Ϊenemy���в���getSkill����
			//�����ǱȽ�npcʣ���������ؼ���������
			//�����⼸��npc��skill��id����������أ����Լ򵥴���
			if (EnemyNPC->getInternalEnergy() > (EnemyNPC->getSkill()).getNeedMp(enemyId + 16)) {
				enemyAttack = (EnemyNPC->getSkill()).getAddAttack(enemyId + 16);
			}
			else {
				cout << "���˵�ħ��ֵ���㣬�޷��������ܣ�û�ж�������˺���" << endl;
				return 0;
			}
		}
	}
	if (enemyId == 8) {
		Enemy_Boss* EnemyBOSS = dynamic_cast<Enemy_Boss*>(&enemy);
		int sr = rand() % 100;
		if (sr <= 25) enemyAttack = enemy.getAttack();
		if (sr > 25 && sr < 65) enemyAttack = (EnemyBOSS->getSkill()).getAddAttack(24);
		if (sr >= 65 && sr <= 90) enemyAttack = (EnemyBOSS->getSkill()).getAddAttack(25);
		if (sr > 90 && sr <= 100) enemyAttack = (EnemyBOSS->getSkill()).getAddAttack(26);
	}
	hurt = enemyAttack - player.getArmor();
	if (hurt< 0) {
		player.setDefend(player.getDefend() - enemyAttack);
		cout << "��ķ������ֵ��˵��˵���ͨ������û�ж�������˺���" << endl;
	}
	else {
		player.setDefend(0);
		cout << "���˴ݻ�����Ļ���";
		if (hurt > 0) {
			player.setHealth(player.getHealth() - enemyAttack);
			cout << "�����������" << enemyAttack << "����˺�" << endl;
		}
		cout << endl;
	}
	
};

int Fight::FightJudgement() {     //�ж�ս���Ƿ����
	if (player.getHealth() * enemy.getHealth() == 0) return 0;
	else return 1;
};

int Fight::GetMoney() {     //��ý�Ǯ
	cout << "�����" << player.getMoney() + enemy.getMoney() << "��Ǯ" << endl;
	player.setMoney(player.getMoney() + enemy.getMoney());
};

void Fight::GetSkill() {
	int enemyId = enemy.getId();
	if (enemyId < 5)return;
	if (enemyId == 8) {
		player.addGoodsToBag(24, 1);
		player.addGoodsToBag(25, 1);
		player.addGoodsToBag(26, 1);
	}
	else {
		if (enemyId == 5)player.addGoodsToBag(21, 1);
		if (enemyId == 6)player.addGoodsToBag(22, 1);
		if (enemyId == 7)player.addGoodsToBag(23, 1);
	}
};

int Fight::GetIntelnalEngery() {         //�������
	int enemyId = enemy.getId();
	if (enemyId > 4 || enemyId < 8) {
		player.setMp(player.getMp() + enemy.getInternalEnergy());
		cout << "����������������" << player.getMp() + enemy.getInternalEnergy() << "�㣡" << endl;
	}
	else return 0;
};

void Fight::Fighting() {
	while (FightJudgement()) {
		ShowFight();
		FightChoice();
		EnemyFight();
		if (round == -1)return;		//���ܳɹ�����ս��
	}
	if (player.getHealth() > 0) {
		cout << "ս��ʤ����" << endl;
		GetIntelnalEngery();
		GetSkill();
		GetMoney();
	}
	else {
		if (enemy.getHealth() > 0)cout << "����������ս������" << endl;
		else cout << "���ź�����������ع��ھ���" << endl;
		cout << "���ڽ����е�һ���ó�����ʱ�������µķ�������������д��������ģ�����ð�հɣ�" << endl;
		system("pause");
		exit(0);
	}
};
