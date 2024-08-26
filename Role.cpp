#include <iostream>
#include <string>
#include "Role.h"

using namespace std;


Role::Role(int t)  {  
	mapId = 0;
	switch (t) {
	case 0: {
		type = 0;		//用来判断有没有保存的游戏
		break;
	}
	case 1: {
		name = "秋凤梧";
		type = 1;
		health_max = 160;
		health = 160;
		attack = 30;
		defend = 0;
		money = 0;
		skill = Role_Skill::Role_Skill();//只有一个角色
		break;
	}


	default:break;
	}
}

void Role::operator=(Role player) {			//重载=实现深复制
	name = player.getName();
	type = player.getType();
	health_max = player.getHealth_max();
	health = player.getHealth();
	Mp = player.getMp();
	
	attack = player.getAttack();
	

	
	defend = player.getDefend();	//待考虑
	money = player.getMoney();
	bag = player.getBag();

	
	mapId = player.getMapId();
	skill = player.getSkill();		//待考虑
	story = player.getStory();
}

//返回是否有秘籍释放
bool Role::showSkill() {
	if (skillId.size()) {
		cout << "你可以选择使用的秘籍有：" << endl;
		for (int i = 0; i < skillId.size(); i++)
			cout << "秘籍" << i + 1 << ":" << skill.getName(skillId[i]) << '\t';
		return true;
	}
	else {
		cout << "你当前背包里尚未配备任何秘籍。" << endl;
		return false;
	}
}

double Role::useSkill() {
	cout << endl << "请选择：";
	int useWhatSkill;
	cin >> useWhatSkill;
	if (!skill.ifHaveSkill(useWhatSkill)) {
		cout << "你的背包里尚未拥有这个秘籍，无法使用。" << endl;
		return 0;
	}
	else if (getMp() < skill.getNeedMp(useWhatSkill)) {
		cout << "你的内力不足，无法使用该秘籍。" << endl;
		return 0;
	}
	else {
		setMp(getMp() - skill.getNeedMP(useWhatSkill));
		cout << "你消耗" << skill.getNeedMP(useWhatSkill) << "点内力使用了“" << skill.getName(useWhatSkill) << "”技能，对";			//这里跳转回Filght.cpp继续
		return skill.getAddAttack(useWhatSkill);//返回技能的攻击加成
	}
}


Role::~Role() {}

string Role::getName() {
	return name;
}

int Role::getType() {
	return type;
}

int Role::getMapId() {
	return mapId;
}

void Role::setMapId(int NewMapId) {
	mapId = NewMapId;
}

int Role::getStory()
{
	return story;
}

void Role::setStory(int s)
{
	story = s;
}

int Role::getHealth_max() {
	return health_max;
}

void Role::setHealth_max(int hp_m) {
	health_max = hp_m;
}

int Role::getHealth() {
	return health;
}

void Role::setHealth(int hp) {
	health = hp;
	if (hp > getHealth_max())
		health = getHealth_max();
	if (health < 0)
		health = 0;
}

int Role::getMp() {
	return Mp;
}

void Role::setMp(int mp) {

	if (mp > 0)
		Mp = mp;
	else
		Mp = 0;
}

int Role::getAttack() {
	return attack;
}

void Role::setAttack(int a) {
	attack = a;

}

int Role::getDefend() {//防御值，护甲可加防御值
	return defend;
}
void Role::setDefend(int d) {
	defend = d;
}


int Role::getMoney() {
	return money;
}

void Role::setMoney(int m) {
	money = m;
}

void Role::showRole()
{
	cout << endl;
	cout << endl << "当前人物属性:" << '\t';
	cout << "姓名:" << name << '\t';
	
	cout << "气血:" << health << "/" << health_max << '\t';

	cout << "内力:" << Mp << endl;
	cout << "护甲：" << getDefend() << endl;
	cout << "攻击:" << attack << '\t';

	cout << "金钱:" << money << endl;
}


Bag Role::getBag() {
	return bag;
}

Skill Role::getSkill() {
	return skill;
}

void Role::showBag() {
	bag.showbags();
}

int Role::getBagWhichGoodsId(int whichGoods) {
	return bag.getWhichGoodsId(whichGoods);

}

int Role::getBagWhichGoodsNum(int whichGoods) {
	return bag.getWhichGoodsNum(whichGoods);

}

void Role::addGoodsToBag(int* goodsId, int* num) {
	cout << endl << "得到了：" << endl;

	bag.showgoods(goodsId, num);
	
	if (bag.getgoodnumber() > 20) {
		cout << "背包已满，无法添加。" << endl;
	}
	else if (bag.getgoodnumber() + num[0] + num[1] + num[2] + num[3] > 20) {//掉落的物品可以有秘籍和武器,数量num暂定，金币不是good里面的
		cout << "背包剩余空位不足，无法完全添加。" << endl;
		cout << "你仅能添加" << 20 - bag.getgoodnumber() << "件。" << endl;
		cout << "请选择要添加的物品：";
		for (int chioce = 0; num[chioce] == 0 || bag.getgoodnumber() >= 20;) {
			cin >> chioce;
			if (num[chioce] + bag.getgoodnumber() > 20) {
				bag.addgoods(goodsId[chioce], 20 - bag.getgoodnumber());
				cout << "成功添加" << 20 - bag.getGoodsNum() << "件到背包！" << endl << endl;
			}
			else {
				bag.addgoods(goodsId[chioce], num[chioce]);
				cout << "成功添加" << num[chioce] << "件到背包！" << endl << endl;
			}
		}
	}
	else {
		for (int i = 0; goodsId[i] >= 0; i++)
			bag.addgoods(goodsId[i], num[i]);
		cout << "全部成功添加到背包！" << endl << endl;
	}
}

void Role::addGoodsToBag(int goodsId, int num) {
	cout << endl << "得到了：" << endl;

	bag.showgoods(goodsId, num);
	if (bag.getgoodnumber() > 20) {
		cout << "背包已满，无法添加。" << endl;
	}
	else if (bag.getgoodnumber() + num > 20) {
		cout << "背包剩余空位不足，无法完全添加。" << endl;
		cout << "你仅能添加" << 20 - bag.getgoodnumber() << "件。" << endl;
		cout << "请选择要添加的物品：";
		for (int chioce = 0; num == 0 || bag.getgoodnumber() >= 20;) {
			cin >> chioce;
			if (num + bag.getgoodnumber() > 20) {
				bag.addgoods(goodsId, 20 - bag.getgoodnumber());
				cout << "成功添加" << 20 - bag.getgoodnumber() << "件到背包！" << endl << endl;
			}
			else {
				bag.addgoods(goodsId, num);
				cout << "成功添加" << num << "件到背包！" << endl << endl;
			}
		}
	}
	else {
		bag.addgoods(goodsId, num);
		cout << "全部成功添加到背包！" << endl << endl;
	}
}



bool Role::subGoodsToBag(int goodsId, int num) {
	return bag.reducegoods(goodsId, num);
}

void Role::setBag(Bag bags) {
	bag = bags;
}

void Role::savePlayerBag() {
	bag.savebag();
}



void Role::newBag() {
	Bag bags;
	bag = bags;
}



void Role::addSaveGoodsToBag(int goodsId, int num) {
	bag.addgoods(goodsId, num);
}

void Role::useDrug() {
	if (bag.isUseDrug()) {
		cout << "是否使用补品：	1.是	2.否" << endl;
		int choice;
		cin >> choice;
		if (choice == 2)
			return;
		if (choice == 1) {
			cout << "请选择要使用的补品：" << endl;
			for (int i = bag.getgoodnumber(); i > 0; i--) {
				for (int j = 16; j < 20; j++)
					if (getBagWhichGoodsId(i) == j)
						cout << i << "." << '\t' << goods[getBagWhichGoodsId(i)].getName() << '\t' << getBagWhichGoodsNum(i) << " 件" << endl;
			}
			cout << "0.取消" << endl;
			int choiceGoodsId, choiceGoodsNum;
			while (true) {
				cin >> choiceGoodsId;
				if (choiceGoodsId < 0 || choiceGoodsId > bag.getgoodnumber())
					cout << "选择错误，请重新选择！" << endl;
				else break;

			}
			choiceGoodsId = getBagWhichGoodsId(choiceGoodsId);
			cout << "请选择使用多少（输入0取消）：" << endl;
			cin >> choiceGoodsNum;
			subGoodsToBag(choiceGoodsId, choiceGoodsNum);
			cout << "成功使用药品！";
			if (choiceGoodsId == 16 || choiceGoodsId == 17) {
				for (int i = choiceGoodsNum; i > 0; i--)
					setHealth(goods[choiceGoodsId].getAddHP() + getHealth());
				cout << "共恢复" << goods[choiceGoodsId].getAddHP() * choiceGoodsNum << "点气血。" << endl << endl;
			}
			if (choiceGoodsId == 18 || choiceGoodsId == 19) {
				for (int i = choiceGoodsNum; i > 0; i--)
					setDefend(goods[choiceGoodsId].getAddArmor() + getArmor());
				cout << "共恢复" << goods[choiceGoodsId].getAddArmor() * choiceGoodsNum << "点护甲值。" << endl << endl;
			}
			if (choiceGoodsId == 20) {
				for (int i = choiceGoodsNum; i > 0; i--)
					setMp(goods[choiceGoodsId].getAddMP() + getMp());
				cout << "共恢复" << goods[choiceGoodsId].getAddMP() * choiceGoodsNum << "点内力。" << endl << endl;
			}
			if (choiceGoodsId == 0) return;
		}
	}
}

void Role::showEquip()
{
	cout << "当前已装备:" << endl;
	cout << "武器:";
	if (weapon == -1) {
		cout << "无" << endl;
	}
	else {
		cout << goods[weapon].getName() << endl;
	}
	cout << "护甲:";
	if (armor == -1) {
		cout << "无" << endl;
	}
	else {
		cout << goods[armor].getName() << endl;
	}
}

void Role::wearEquip(int id)
{
	if (goods[id].getType() == 0) {
		if (weapon != -1) {
			removeEquip(weapon);
		}
		setAttack(getAttack() + goods[id].getAddAttack());
		weapon = id;
	}
	else if (goods[id].getType() == 1) {
		if (armor != -1) {
			removeEquip(armor);
		}
		setDefend(getDefend() + goods[id].getAddArmor());
	
			armor = id;
	}
	bag.reduceGoods(id, 1);
	cout << "已装备 " << goods[id].getName() << endl;
}

void Role::removeEquip(int id)
{
	if (goods[id].getType() == 0) {
		if (weapon != -1) {
			cout << "当前无武器" << endl;
		}
		setAttack(getAttack() - goods[id].getAddAttack());
		weapon = -1;
	}
	else if (goods[id].getType() == 1) {
		if (armor != -1) {
			cout << "当前无护甲" << endl;
		}
		setDefend(getDefend() - goods[id].getAddArmor());
	
		armor = -1;
	}
	bag.addGoods(id, 1);
	cout << "已换下 " << goods[id].getName() << endl;
}



int Role::getWeapon()
{
	return weapon;
}

void Role::setWeapon(int w)
{
	weapon = w;
}

int Role::getArmor()
{
	return armor;
}

void Role::setArmor(int a)
{
	armor = a;
}