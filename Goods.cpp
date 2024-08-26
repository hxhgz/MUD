 #include "goods.h"

Goods::Goods(int id)
{
	switch (id)
	{
	case 0: {
		goodsId = id;
		name = "木剑";
		desc = "普通的剑，勉强可以击破敌人的防御";
		type = 0;
		addAttack = 5;
		priceBuy = 100;
		priceSell = 50;
		break;
	}
	case 1: {
		goodsId = id;
		name = "玉剑";
		desc = "做工良好，是行走江湖装高冷的不二之选";
		type = 0;
		addAttack = 20;
		priceBuy = 500;
		priceSell = 200;
		break;
	}
	case 2: {
		goodsId = id;
		name = "紫金刀";
		desc = "由上好的紫金石打造而成，锋利至极";
		type = 0;
		addAttack = 80;
		priceBuy = 900;
		priceSell = 400;
		break;
	}
	case 3: {
		goodsId = id;
		name = "黑金古刀";
		desc = "传说中以天外陨石锻造的兵器，由不知名的张小哥友情赞助";
		type = 0;
		addAttack = 160;
		priceBuy = 1500;
		priceSell = 600;
		break;
	}

	case 4: {
		goodsId = id;
		name = "白甲";
		desc = "普通甲具，防御力低";
		type = 1;

		addArmor = 40;
		priceBuy = 200;
		priceSell = 100;
		break;
	}
	case 5: {
		goodsId = id;
		name = "蓝甲";
		desc = "，防御力约为两个白甲";
		type = 1;
		addArmor = 80;
		priceBuy = 300;
		priceSell = 150;
		break;
	}
	case 6: {
		goodsId = id;
		name = "紫甲";
		desc = "四个白甲，性价比超高";
		type = 1;
		addArmor = 160;
		priceBuy = 500;
		priceSell = 250;
		break;
	}
	case 7: {
		goodsId = id;
		name = "金甲";
		desc = "防御力高，金贵的甲衣，不易碎";
		type = 1;
		addArmor = 200;
		priceBuy = 800;
		priceSell = 500;
		break;
	}
	case 8: {
		goodsId = id;
		name = "红甲";
		desc = "神秘的宝贵甲具，相传是最强的盾";
		type = 1;
		addArmor = 300;
		priceBuy = 1500;
		priceSell = 600;
		break;
	}

	case 9: {
		goodsId = id;
		name = "拔剑式";
		desc = "基础剑招";
		type = 2;
		addAttack = 10;
		addMP = -5;
		priceBuy = 200;
		priceSell = 80;
		break;

	}
	case 10: {
		goodsId = id;
		name = "隔山打牛";
		desc = "可以直接攻击敌人内脏";
		type = 2;
		addAttack = 20;
		addMP = -10;
		priceBuy = 200;
		priceSell = 80;
		break;

	}
	case 11: {
		goodsId = id;
		name = "葵花宝典";
		desc = "欲练此功，必先自宫";
		type = 2;
		addAttack = 15;
		addMP = -10;
		priceBuy = 100;
		priceSell = 0;
		break;

	}
	case 12:{
	    goodsId = id;
	    name = "化骨绵绵掌";
		desc = "练至大成可以洞穿敌人心脏";
		type = 2;
		addAttack = 40;
		addMP = -40;
		priceBuy = 1000;
		priceSell = 600;
		break;

		   }
	case 13: {
		goodsId = id;
		name = "蛤蟆神功";
		desc = "师承火云邪神，挫败了一众武林高手";
		type = 2;
		addAttack = 70;
		priceBuy = 2000;
		priceSell = 1000;
		addMP = -60;
		break;

	}
	case 14: {
		goodsId = id;
		name = "独孤九剑";
		desc = "剑术的最强招式，相传九剑一出，必有一死";
		type = 2;
		addAttack = 100;
		addMP = -90;
		priceBuy = 2000;
		priceSell = 1000;
		break;

	}
	case 15: {
		goodsId = id;
		name = "如来神掌";
		desc = "从天外下落而来的招式，威力极大";
		type = 2;
		addAttack = 300;
		priceBuy = 5000;
		priceSell = 2000;
		addMP = -100;
		break;

	}

	case 16: {
		goodsId = id;
		name = "金创药";
		desc = "常见的疗伤药,补充少量气血";
		type = 3;
		addHP = 30;
		priceBuy = 100;
		priceSell = 10;
		break;
	}
	case 17: {
		goodsId = id;
		name = "小还丹";
		desc = "散发着香气的紫色药丸,补充大量气血";
		type = 3;
		addHP = 60;
		priceBuy = 180;
		priceSell = 20;
		break;
	}
	case 18: {
		goodsId = id;
		name = "低级甲粉";
		desc = "名贵药物精心炼成的粉末,修补少量护甲";
		type = 3;
		addArmor = 20;
		priceBuy = 80;
		priceSell = 20;
		break;
	}
	case 19: {
		goodsId = id;
		name = "高级甲粉";
		desc = "名贵药物精心炼成的粉末,修补大量护甲";
		type = 3;
		addArmor = 40;
		priceBuy = 140;
		priceSell = 30;
		break;
	}
	case 20: {
		goodsId = id;
		name = "安魂香";
		desc = "名贵药物精心炼成的丹药,补充内力";
		type = 3;
		addMP = 40;
		priceBuy = 200;
		priceSell = 20;
		break;
	}
     
	case 21:{
		goodsId = id;
		name ="照神经";
		desc = "高立修习多年的功法，练成后内力深厚，武力高强";
		type = 4;
		addAttack = 50;
		priceSell = 100;
		addMP = -10;
		break;

     }
	case 22: {
		goodsId = id;
		name = "重明万方";
		desc = "丽泽周群品，重明照万方。";
		type = 4;
		addAttack = 100;
		priceSell = 200;
		addMP = -20;
		break;
	}
	case 23: {
		goodsId = id;
		name = "呼星唤魅";
		desc = "呼星召鬼歆杯盘，山魅食时人森寒。";
		type = 4;
		addAttack = 400;
		priceSell = 800;
		addMP = -40;
		break;
	}
	case 24: {
		goodsId = id;
		name = "漆骨生花";
		desc = "漆灰骨末丹水沙，凄凄骨血生桐花。";
		type = 4;
		addAttack = 600;
		priceSell = 1200;
		addMP = -60;
		break;
	}
	case 25: {
		goodsId = id;
		name = "冰寒露华";
		desc = "玉碗冰寒滴露华，粉融香雪透轻纱。";
		type = 4;
		addAttack = 500;
		priceSell = 1000;
		addMP = -50;
		
		break;
	}
	case 26: {
		goodsId = id;
		name = "风雷万象";
		desc = "风雷开万象，散天影、入虚坛。";
		type = 4;
		addAttack = 500;
		priceSell = 1000;
		addMP = -50;
		break;
	}
	default:
		break;
	}
}

Goods::~Goods()
{
}



string Goods::getName() {
	return string(name);
}

int Goods::getGoodsId()
{
	return goodsId;
}

string Goods::getDesc()
{
	return string(desc);
}



int Goods::getType()
{
	return type;
}

int Goods::getAddAttack()
{
	return addAttack;
}


int Goods::getAddHP()
{
	return addHP;
}


int Goods::getAddMP()
{
	return addMP;
}
int Goods::getAddArmor() {
	return addArmor;
}

int Goods::getPriceSell()
{
	return priceSell;
}

int Goods::getPriceBuy()
{
	return priceBuy;
}

void Goods::showGoods()
{
	cout << name << endl;
	cout << desc << endl;
	if (type == 0) //武器
	{
		cout << "攻击力:" << addAttack << endl;
	}
	if (type == 1) //防具
	{
		cout << "护甲" << addArmor << endl;
	
	}
	if (type == 2)//秘籍
	{
		cout << "攻击力" << addAttack << "内力消耗：" << -1*addMP << endl;
	}
	if (type == 3) //药品
	{
		cout << "回复气血:" << addHP << endl;
		cout << "回复内力:" << addMP << endl;
	}
	if (type == 4)//敌人秘籍
	{
		cout << "攻击力" << addAttack << "内力消耗：" << -1 * addMP << endl;
	}
}
