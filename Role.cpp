#include <iostream>
#include <string>
#include "Role.h"

using namespace std;


Role::Role(int t)  {  
	mapId = 0;
	switch (t) {
	case 0: {
		type = 0;		//�����ж���û�б������Ϸ
		break;
	}
	case 1: {
		name = "�����";
		type = 1;
		health_max = 160;
		health = 160;
		attack = 30;
		defend = 0;
		money = 0;
		skill = Role_Skill::Role_Skill();//ֻ��һ����ɫ
		break;
	}


	default:break;
	}
}

void Role::operator=(Role player) {			//����=ʵ�����
	name = player.getName();
	type = player.getType();
	health_max = player.getHealth_max();
	health = player.getHealth();
	Mp = player.getMp();
	
	attack = player.getAttack();
	

	
	defend = player.getDefend();	//������
	money = player.getMoney();
	bag = player.getBag();

	
	mapId = player.getMapId();
	skill = player.getSkill();		//������
	story = player.getStory();
}

//�����Ƿ����ؼ��ͷ�
bool Role::showSkill() {
	if (skillId.size()) {
		cout << "�����ѡ��ʹ�õ��ؼ��У�" << endl;
		for (int i = 0; i < skillId.size(); i++)
			cout << "�ؼ�" << i + 1 << ":" << skill.getName(skillId[i]) << '\t';
		return true;
	}
	else {
		cout << "�㵱ǰ��������δ�䱸�κ��ؼ���" << endl;
		return false;
	}
}

double Role::useSkill() {
	cout << endl << "��ѡ��";
	int useWhatSkill;
	cin >> useWhatSkill;
	if (!skill.ifHaveSkill(useWhatSkill)) {
		cout << "��ı�������δӵ������ؼ����޷�ʹ�á�" << endl;
		return 0;
	}
	else if (getMp() < skill.getNeedMp(useWhatSkill)) {
		cout << "����������㣬�޷�ʹ�ø��ؼ���" << endl;
		return 0;
	}
	else {
		setMp(getMp() - skill.getNeedMP(useWhatSkill));
		cout << "������" << skill.getNeedMP(useWhatSkill) << "������ʹ���ˡ�" << skill.getName(useWhatSkill) << "�����ܣ���";			//������ת��Filght.cpp����
		return skill.getAddAttack(useWhatSkill);//���ؼ��ܵĹ����ӳ�
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

int Role::getDefend() {//����ֵ�����׿ɼӷ���ֵ
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
	cout << endl << "��ǰ��������:" << '\t';
	cout << "����:" << name << '\t';
	
	cout << "��Ѫ:" << health << "/" << health_max << '\t';

	cout << "����:" << Mp << endl;
	cout << "���ף�" << getDefend() << endl;
	cout << "����:" << attack << '\t';

	cout << "��Ǯ:" << money << endl;
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
	cout << endl << "�õ��ˣ�" << endl;

	bag.showgoods(goodsId, num);
	
	if (bag.getgoodnumber() > 20) {
		cout << "�����������޷���ӡ�" << endl;
	}
	else if (bag.getgoodnumber() + num[0] + num[1] + num[2] + num[3] > 20) {//�������Ʒ�������ؼ�������,����num�ݶ�����Ҳ���good�����
		cout << "����ʣ���λ���㣬�޷���ȫ��ӡ�" << endl;
		cout << "��������" << 20 - bag.getgoodnumber() << "����" << endl;
		cout << "��ѡ��Ҫ��ӵ���Ʒ��";
		for (int chioce = 0; num[chioce] == 0 || bag.getgoodnumber() >= 20;) {
			cin >> chioce;
			if (num[chioce] + bag.getgoodnumber() > 20) {
				bag.addgoods(goodsId[chioce], 20 - bag.getgoodnumber());
				cout << "�ɹ����" << 20 - bag.getGoodsNum() << "����������" << endl << endl;
			}
			else {
				bag.addgoods(goodsId[chioce], num[chioce]);
				cout << "�ɹ����" << num[chioce] << "����������" << endl << endl;
			}
		}
	}
	else {
		for (int i = 0; goodsId[i] >= 0; i++)
			bag.addgoods(goodsId[i], num[i]);
		cout << "ȫ���ɹ���ӵ�������" << endl << endl;
	}
}

void Role::addGoodsToBag(int goodsId, int num) {
	cout << endl << "�õ��ˣ�" << endl;

	bag.showgoods(goodsId, num);
	if (bag.getgoodnumber() > 20) {
		cout << "�����������޷���ӡ�" << endl;
	}
	else if (bag.getgoodnumber() + num > 20) {
		cout << "����ʣ���λ���㣬�޷���ȫ��ӡ�" << endl;
		cout << "��������" << 20 - bag.getgoodnumber() << "����" << endl;
		cout << "��ѡ��Ҫ��ӵ���Ʒ��";
		for (int chioce = 0; num == 0 || bag.getgoodnumber() >= 20;) {
			cin >> chioce;
			if (num + bag.getgoodnumber() > 20) {
				bag.addgoods(goodsId, 20 - bag.getgoodnumber());
				cout << "�ɹ����" << 20 - bag.getgoodnumber() << "����������" << endl << endl;
			}
			else {
				bag.addgoods(goodsId, num);
				cout << "�ɹ����" << num << "����������" << endl << endl;
			}
		}
	}
	else {
		bag.addgoods(goodsId, num);
		cout << "ȫ���ɹ���ӵ�������" << endl << endl;
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
		cout << "�Ƿ�ʹ�ò�Ʒ��	1.��	2.��" << endl;
		int choice;
		cin >> choice;
		if (choice == 2)
			return;
		if (choice == 1) {
			cout << "��ѡ��Ҫʹ�õĲ�Ʒ��" << endl;
			for (int i = bag.getgoodnumber(); i > 0; i--) {
				for (int j = 16; j < 20; j++)
					if (getBagWhichGoodsId(i) == j)
						cout << i << "." << '\t' << goods[getBagWhichGoodsId(i)].getName() << '\t' << getBagWhichGoodsNum(i) << " ��" << endl;
			}
			cout << "0.ȡ��" << endl;
			int choiceGoodsId, choiceGoodsNum;
			while (true) {
				cin >> choiceGoodsId;
				if (choiceGoodsId < 0 || choiceGoodsId > bag.getgoodnumber())
					cout << "ѡ�����������ѡ��" << endl;
				else break;

			}
			choiceGoodsId = getBagWhichGoodsId(choiceGoodsId);
			cout << "��ѡ��ʹ�ö��٣�����0ȡ������" << endl;
			cin >> choiceGoodsNum;
			subGoodsToBag(choiceGoodsId, choiceGoodsNum);
			cout << "�ɹ�ʹ��ҩƷ��";
			if (choiceGoodsId == 16 || choiceGoodsId == 17) {
				for (int i = choiceGoodsNum; i > 0; i--)
					setHealth(goods[choiceGoodsId].getAddHP() + getHealth());
				cout << "���ָ�" << goods[choiceGoodsId].getAddHP() * choiceGoodsNum << "����Ѫ��" << endl << endl;
			}
			if (choiceGoodsId == 18 || choiceGoodsId == 19) {
				for (int i = choiceGoodsNum; i > 0; i--)
					setDefend(goods[choiceGoodsId].getAddArmor() + getArmor());
				cout << "���ָ�" << goods[choiceGoodsId].getAddArmor() * choiceGoodsNum << "�㻤��ֵ��" << endl << endl;
			}
			if (choiceGoodsId == 20) {
				for (int i = choiceGoodsNum; i > 0; i--)
					setMp(goods[choiceGoodsId].getAddMP() + getMp());
				cout << "���ָ�" << goods[choiceGoodsId].getAddMP() * choiceGoodsNum << "��������" << endl << endl;
			}
			if (choiceGoodsId == 0) return;
		}
	}
}

void Role::showEquip()
{
	cout << "��ǰ��װ��:" << endl;
	cout << "����:";
	if (weapon == -1) {
		cout << "��" << endl;
	}
	else {
		cout << goods[weapon].getName() << endl;
	}
	cout << "����:";
	if (armor == -1) {
		cout << "��" << endl;
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
	cout << "��װ�� " << goods[id].getName() << endl;
}

void Role::removeEquip(int id)
{
	if (goods[id].getType() == 0) {
		if (weapon != -1) {
			cout << "��ǰ������" << endl;
		}
		setAttack(getAttack() - goods[id].getAddAttack());
		weapon = -1;
	}
	else if (goods[id].getType() == 1) {
		if (armor != -1) {
			cout << "��ǰ�޻���" << endl;
		}
		setDefend(getDefend() - goods[id].getAddArmor());
	
		armor = -1;
	}
	bag.addGoods(id, 1);
	cout << "�ѻ��� " << goods[id].getName() << endl;
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