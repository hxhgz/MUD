#include "goods.h"

goods::goods(int id)
{
	switch (id)
	{
	case 0: {
		goodsId = id;
		name = "ľ��";
		desc = "��ͨ�Ľ�����ǿ���Ի��Ƶ��˵ķ���";
		type = 0;
		addAttack = 5;
		priceBuy = 100;
		priceSell = 50;
		break;
	}
	case 1: {
		goodsId = id;
		name = "��";
		desc = "�������ã������߽���װ����Ĳ���֮ѡ";
		type = 0;
		addAttack = 20;
		priceBuy = 500;
		priceSell = 200;
		break;
	}
	case 2: {
		goodsId = id;
		name = "�Ͻ�";
		desc = "���Ϻõ��Ͻ�ʯ������ɣ���������";
		type = 0;
		addAttack = 80;
		priceBuy = 900;
		priceSell = 400;
		break;
	}
	case 3: {
		goodsId = id;
		name = "�ڽ�ŵ�";
		desc = "��˵����������ʯ����ı������ɲ�֪������С����������";
		type = 0;
		addAttack = 160;
		priceBuy = 1500;
		priceSell = 600;
		break;
	}

	case 4: {
		goodsId = id;
		name = "�׼�";
		desc = "��ͨ�׾ߣ���������";
		type = 1;

		addArmor = 40;
		priceBuy = 200;
		priceSell = 100;
		break;
	}
	case 5: {
		goodsId = id;
		name = "����";
		desc = "��������ԼΪ�����׼�";
		type = 1;
		addArmor = 80;
		priceBuy = 300;
		priceSell = 150;
		break;
	}
	case 6: {
		goodsId = id;
		name = "�ϼ�";
		desc = "�ĸ��׼ף��Լ۱ȳ���";
		type = 1;
		addArmor = 160;
		priceBuy = 500;
		priceSell = 250;
		break;
	}
	case 7: {
		goodsId = id;
		name = "���";
		desc = "�������ߣ����ļ��£�������";
		type = 1;
		addArmor = 200;
		priceBuy = 800;
		priceSell = 500;
		break;
	}
	case 8: {
		goodsId = id;
		name = "���";
		desc = "���صı���׾ߣ��ഫ����ǿ�Ķ�";
		type = 1;
		addArmor = 300;
		priceBuy = 1500;
		priceSell = 600;
		break;
	}

	case 9: {
		goodsId = id;
		name = "�ν�ʽ";
		desc = "��������";
		type = 2;
		addAttack = 10;
		addMP = -5;
		priceBuy = 200;
		priceSell = 80;
		break;

	}
	case 10: {
		goodsId = id;
		name = "��ɽ��ţ";
		desc = "����ֱ�ӹ�����������";
		type = 2;
		addAttack = 20;
		addMP = -10;
		priceBuy = 200;
		priceSell = 80;
		break;

	}
	case 11: {
		goodsId = id;
		name = "��������";
		desc = "�����˹��������Թ�";
		type = 2;
		addAttack = 15;
		addMP = -10;
		priceBuy = 100;
		priceSell = 0;
		break;

	}
	case 12:{
	    goodsId = id;
	    name = "����������";
		desc = "������ɿ��Զ�����������";
		type = 2;
		addAttack = 40;
		addMP = -40;
		priceBuy = 1000;
		priceSell = 600;
		break;

		   }
	case 13: {
		goodsId = id;
		name = "�����";
		desc = "ʦ�л���а�񣬴����һ�����ָ���";
		type = 2;
		addAttack = 70;
		priceBuy = 2000;
		priceSell = 1000;
		addMP = -60;
		break;

	}
	case 14: {
		goodsId = id;
		name = "���¾Ž�";
		desc = "��������ǿ��ʽ���ഫ�Ž�һ��������һ��";
		type = 2;
		addAttack = 100;
		addMP = -90;
		priceBuy = 2000;
		priceSell = 1000;
		break;

	}
	case 15: {
		goodsId = id;
		name = "��������";
		desc = "�����������������ʽ����������";
		type = 2;
		addAttack = 300;
		priceBuy = 5000;
		priceSell = 2000;
		addMP = -100;
		break;

	}

	case 16: {
		goodsId = id;
		name = "��ҩ";
		desc = "����������ҩ,����������Ѫ";
		type = 3;
		addHP = 30;
		priceBuy = 100;
		priceSell = 10;
		break;
	}
	case 17: {
		goodsId = id;
		name = "С����";
		desc = "ɢ������������ɫҩ��,���������Ѫ";
		type = 3;
		addHP = 60;
		priceBuy = 180;
		priceSell = 20;
		break;
	}
	case 18: {
		goodsId = id;
		name = "�ͼ��׷�";
		desc = "����ҩ�ﾫ�����ɵķ�ĩ,�޲���������";
		type = 3;
		addArmor = 20;
		priceBuy = 80;
		priceSell = 20;
		break;
	}
	case 19: {
		goodsId = id;
		name = "�߼��׷�";
		desc = "����ҩ�ﾫ�����ɵķ�ĩ,�޲���������";
		type = 3;
		addArmor = 40;
		priceBuy = 140;
		priceSell = 30;
		break;
	}
	case 20: {
		goodsId = id;
		name = "������";
		desc = "����ҩ�ﾫ�����ɵĵ�ҩ,��������";
		type = 3;
		addMP = 40;
		priceBuy = 200;
		priceSell = 20;
		break;
	}

	default:
		break;
	}
}

goods::~goods()
{
}



string goods::getName() {
	return string(name);
}

int goods::getGoodsId()
{
	return goodsId;
}

string goods::getDesc()
{
	return string(desc);
}



int goods::getType()
{
	return type;
}

int goods::getAddAttack()
{
	return addAttack;
}


int goods::getAddHP()
{
	return addHP;
}


int goods::getAddMP()
{
	return addMP;
}
int goods::getAddArmor() {
	return addArmor;
}

int goods::getPriceSell()
{
	return priceSell;
}

int goods::getPriceBuy()
{
	return priceBuy;
}

void goods::showGoods()
{
	cout << name << endl;
	cout << desc << endl;
	if (type == 0) //����
	{
		cout << "������:" << addAttack << endl;
	}
	if (type == 1) //����
	{
		cout << "����" << addArmor << endl;
	
	}
	if (type == 2)//�ؼ�
	{
		cout << "������" << addAttack << "�������ģ�" << -1*addMP << endl;
	}
	if (type == 3) //ҩƷ
	{
		cout << "�ظ���Ѫ:" << addHP << endl;
		cout << "�ظ�����:" << addMP << endl;
	}
}
