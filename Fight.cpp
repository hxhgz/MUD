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
	void ShowFight();    //显示战斗时双方的状态
	void FightChoice();  //角色战斗时的选择
	int EnemyFight();    //敌人战斗时的选择
	bool EndFight();     //判断战斗是否结束
	int GetMoney();      //战斗胜利获得金钱
	void GetSkill();	 //战斗胜利获得秘籍
	int GetIntelnalEngery(Enemy enemy);		//战斗胜利获得内力
	void Fighting();     //战斗总函数
private:
	Role player;//战斗的角色
	Enemy enemy;//战斗的怪物
	int round;//回合数
};
*/

Fight::Fight(Role player, Enemy enemy) :player(player), enemy(enemy) { round = 1; };
Fight::Fight(Role player, Enemy_npc enemy_npc) : player(player), enemy(enemy_npc) { round = 1; };
Fight::Fight(Role player, Enemy_Boss enemy_Boss) : player(player), enemy(enemy_Boss) { round = 1; };

Fight::~Fight() {};

void Fight::ShowFight() {   //展示战斗时状态
	player.showRole();
	cout << endl;
	enemy.displayInfo();
	cout << endl << "当前为第" << round << "回合" << endl;
};

void Fight::FightChoice() {         //角色战斗选择
	int choose = 0;
	cout << "请选择: 1.普通攻击	2.使用秘籍 3.使用药品 4.逃跑" << endl;
	cin >> choose;
	if (choose >= 1 && choose <= 4) {
		switch (choose) {
		case 1:
		{
			if ((enemy.getArmor() - player.getAttack()) > 0) {		//敌人护甲值大于角色本次输出
				enemy.setArmor(enemy.getArmor() - player.getAttack());
				cout << "敌人的护甲抵挡了你的攻击！" << endl;
				break;
			}
			if ((enemy.getArmor() - player.getAttack()) == 0) {			//敌人护甲值等于角色本次输出
				enemy.setArmor(0);
				cout << "敌人的护甲被你摧毁了！" << endl;
				break;
			}
			if (((enemy.getArmor() - player.getAttack()) < 0) && enemy.getArmor() > 0) {			//敌人护甲值小于角色本次输出但原来大于0
				enemy.setArmor(0);
				if (enemy.getHealth() > (player.getAttack() - enemy.getArmor())) {			//敌人生命值大于角色摧毁护甲溢出的伤害
					enemy.setHealth(enemy.getHealth() - player.getAttack() + enemy.getArmor());
					cout << "你摧毁了敌人的护甲并且造成了" << player.getAttack() - enemy.getArmor() << "点伤害！" << endl;
					break;
				}
				else {			//敌人生命值小于角色摧毁护甲溢出的伤害
					enemy.setHealth(0);
					cout << "你击杀了敌人！" << endl;
					break;
				}
			}
			else {			//敌人护甲值在角色攻击时已经为0
				if (enemy.getHealth() > player.getAttack()) {
					enemy.setHealth(enemy.getHealth() - player.getAttack());
					cout << "你对敌人造成了" << player.getAttack() << "点伤害" << endl;
					break;
				}
				else {			//敌人生命值小于角色本次输出
					enemy.setHealth(0);
					cout << "你击杀了敌人！" << endl;
					break;
				}
			}
			break;
		}
		case 2:
		{
			if (player.showSkill()) {
				double SkillAttack= player.useSkill();			
				if ((enemy.getArmor() - SkillAttack) > 0) {		//敌人护甲值大于角色本次输出
					enemy.setArmor(enemy.getArmor() - SkillAttack);
					cout << "敌人的护甲抵挡了你的攻击！" << endl;
					break;
				}
				if ((enemy.getArmor() - SkillAttack) == 0) {			//敌人护甲值等于角色本次输出
					enemy.setArmor(0);
					cout << "敌人的护甲被你摧毁了！" << endl;
					break;
				}
				if (((enemy.getArmor() - SkillAttack) < 0) && enemy.getArmor() > 0) {			//敌人护甲值小于角色本次输出但原来大于0
					enemy.setArmor(0);
					if (enemy.getHealth() > (SkillAttack - enemy.getArmor())) {			//敌人生命值大于角色摧毁护甲溢出的伤害
						enemy.setHealth(enemy.getHealth() - SkillAttack + enemy.getArmor());
						cout << "你摧毁了敌人的护甲并且造成了" << SkillAttack - enemy.getArmor() << "点伤害！" << endl;
						break;
					}
					else {			//敌人生命值小于角色摧毁护甲溢出的伤害
						enemy.setHealth(0);
						cout << "你击杀了敌人！" << endl;
						break;
					}
				}
				else {			//敌人护甲值在角色攻击时已经为0
					if (enemy.getHealth() > SkillAttack) {
						enemy.setHealth(enemy.getHealth() - SkillAttack);
						cout << "你对敌人造成了" << SkillAttack << "点伤害" << endl;
						break;
					}
					else {			//敌人生命值小于角色本次输出
						enemy.setHealth(0);
						cout << "你击杀了敌人！" << endl;
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
			if (rand() % 100 <= 50) {			//50%成功
				cout << "逃跑失败!" << endl;
				break;
			}
			else {
				cout << "逃跑成功!" << endl;
				round = -1;	//作为战斗结束的标准
				return;		//直接跳出函数
			}
			break;
		}
		}
		round++;
	}
	else cout << "无效输入，请重新选择: " << endl;
}

int Fight::EnemyFight() {        //敌人战斗选择
	int enemyId = enemy.getId();
	int enemyAttack = 0, hurt = 0;
	srand((unsigned)time(NULL));
	if (enemyId > 0 || enemyId < 5) enemyAttack = enemy.getAttack();
	if (enemyId > 4 || enemyId < 8) {
		if (rand() % 100 <= 50) enemyAttack = enemy.getAttack();
		else {
			Enemy_npc* EnemyNPC = dynamic_cast<Enemy_npc*>(&enemy);//类型转换，因为enemy类中不含getSkill函数
			//这里是比较npc剩余内力和秘籍所需内力
			//由于这几个npc和skill的id都是线性相关，所以简单处理
			if (EnemyNPC->getInternalEnergy() > (EnemyNPC->getSkill()).getNeedMp(enemyId + 16)) {
				enemyAttack = (EnemyNPC->getSkill()).getAddAttack(enemyId + 16);
			}
			else {
				cout << "敌人的魔法值不足，无法发动技能，没有对你造成伤害。" << endl;
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
		cout << "你的防御力抵挡了敌人的普通攻击，没有对你造成伤害。" << endl;
	}
	else {
		player.setDefend(0);
		cout << "敌人摧毁了你的护甲";
		if (hurt > 0) {
			player.setHealth(player.getHealth() - enemyAttack);
			cout << "并对你造成了" << enemyAttack << "点的伤害" << endl;
		}
		cout << endl;
	}
	
};

int Fight::FightJudgement() {     //判断战斗是否结束
	if (player.getHealth() * enemy.getHealth() == 0) return 0;
	else return 1;
};

int Fight::GetMoney() {     //获得金钱
	cout << "获得了" << player.getMoney() + enemy.getMoney() << "金钱" << endl;
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

int Fight::GetIntelnalEngery() {         //获得内力
	int enemyId = enemy.getId();
	if (enemyId > 4 || enemyId < 8) {
		player.setMp(player.getMp() + enemy.getInternalEnergy());
		cout << "你的内力上限提高了" << player.getMp() + enemy.getInternalEnergy() << "点！" << endl;
	}
	else return 0;
};

void Fight::Fighting() {
	while (FightJudgement()) {
		ShowFight();
		FightChoice();
		EnemyFight();
		if (round == -1)return;		//逃跑成功结束战斗
	}
	if (player.getHealth() > 0) {
		cout << "战斗胜利！" << endl;
		GetIntelnalEngery();
		GetSkill();
		GetMoney();
	}
	else {
		if (enemy.getHealth() > 0)cout << "你已死亡，战斗结束" << endl;
		else cout << "很遗憾，你与敌人重归于尽了" << endl;
		cout << "你在江湖中的一段旅程已暂时结束，新的风云正待你来书写。重整旗鼓，重启冒险吧！" << endl;
		system("pause");
		exit(0);
	}
};
