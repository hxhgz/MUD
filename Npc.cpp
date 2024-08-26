
#include"Npc.h"
#include<iostream>
using namespace std;


/*
string Npc::getName(int whichNpc) {
	return name[whichNpc];
}
*/

Npc::Npc(int num) {
	type = num;
	switch (num)
	{
	case 0: {
		name = "�˶���";
		goodId = 0;
		goodNum = 1;
		money = 100;
		break;
	}

	case 1: {
		name = "����";
		goodId = 9;
		goodNum = 1;
		money = 20;
		break;
	}
	case 2: {
		name = "���";
		goodId = 10;
		goodNum = 1;
		money = 50;
		break;
	}
	case 3: {
		name = "������";
		goodId = 11;
		goodNum = 1;
		money = 100;
		break;
	}
	case 4: {
		name = "����";
		goodId = -1;
		goodNum = 0;
		money = 0;
		break;
	}
	case 9: {
		name = "�޸�˹";
		goodId = 8;
		goodNum = 1;
		money = 2000;
		break;
	}
	


	default:
		break;
	}
}

Npc::~Npc() {}

string Npc::getName() {
	return name;
}

Role Npc::chat(Role player) {
	switch (type)
	{
	case 0: {
		if (player.getStory() == 0) {
			cout << "�˶���: ���డ����˵���Ǽ��п�ȸ����һ�������������Խ��������ʹʹ�" << endl;
			system("pause");
			cout << "��: ��ô��, ��ʲô�����ˣ�" << endl;
			system("pause");
			cout << "�˶��������֪��������ɣ�����������ڳﻮ����Ҫһͳ�������Ϸ��ھ��Ѿ����ݣ��������Ǳ����ھ�Ҳ����ѽ��" << endl;
			system("pause");
			cout << "�㣺�벻����������ô���񰡣����ǵ����壬��ȸ��̫Σ���ˣ�Ҫ������ȥ����ˮ��" << endl;
			system("pause");
			cout << "�˶�����డ����ɲ����������أ�Ҫ���㻹�ǽ�����������ðɣ����ģ��һ�ע��ġ�" << endl;
			system("pause");
			cout << "�㣺��ѽ�������壬���ֲ���С�����ˣ�������ȥ�����£��ѵ��㻹�������ҵ�ʵ���" << endl;
			system("pause");
			cout << "�˶���Ǻðɣ�������һ�㣬ע�ⰲȫ������Ҳûʲô�����������������Щ�̲��������°ɡ�" << endl;
			system("pause");
			cout << "�㣺�ǾͶ�л�������ˣ������ˣ��ݰ�..." << endl;
			system("pause");
			player.setStory(player.getStory() + 1);
			player.addGoodsToBag(getGoodsId(), getGoodsNum());
			cout << endl << "�����Ʒ:" << goods[getGoodsId()].getName() << " * " << getGoodsNum() << endl << endl;

		}
		else cout << "�Ѿ���̸���ˡ�" << endl << endl;
		break;
	}
	case 1: {//�������飬���ܵ�����ƷӦ��Enemy����д
		if (player.getStory() == 1) {
			cout << "����������˭�������³Ǹ����֪������������ĵط���" << endl;
			system("pause");
			cout << "��: �Ҿ��ǻ�ڷ��Եģ�����С������ˣ��书ƽƽ���䡣" << endl;
			system("pause");
			cout << "����: �ٸ������컬�࣬��˵��������" << endl;
			system("pause");
			cout << "��: ��������Ҿ��������㽵����ġ�" << endl;
			system("pause");
			cout << "�������ϻ���˵�����Ҿͺúÿ�������ô���ҽ���" << endl;
			system("pause");
			

		}
		else cout << "��Ҫ��֮ǰ���ｻ̸�������Ѿ���̸���ˡ�" << endl << endl;
		break;
	}
	case 2: {
		if (player.getStory() == 2) {
			
			cout << "��棺������Ǹ����ܸ�����С�ӣ�" << endl;
			system("pause");
			cout << "��: �治��ò���ҿ��������ֵģ�����С��ÿ���" << endl;
			system("pause");
			cout << "��棺�ҹ���С��С���ģ���ֻ֪������첻������뿪�����ˣ�" << endl;
			system("pause");
			cout << "��: �ǿ�˵����Ŷ��" << endl;
			system("pause");
			cout << "��棺�ϻ���˵����������" << endl;
			system("pause");

			
		}
		else cout << "��Ҫ��֮ǰ���ｻ̸�������Ѿ���̸���ˡ�" << endl << endl;
		break;
	}
	case 3: {
		if (player.getStory() == 3) {
			cout << "  " << endl;
			system("pause");
			cout << "������С�ֵܣ�����С�����ˣ���Ȼ���ҵ������󽫶������ˡ�" << endl;
			system("pause");
			cout << "�㣺�ٺ٣����Ұ��ˡ�" << endl;
			system("pause");
			cout << "�����񣺲�������������ԩ�޳�������Ϊ�Σ�" << endl;
			system("pause");
			cout << "��: ��ԩ�޳𣿺Ǻǣ�����������ɱ��Щ���޴�����ƽ����յ�ʱ����ôû���������������ԩ�޳��أ�" << endl;
			system("pause");
			cout << "�����񣺹�������С�ֵܣ��������Ĭ����������Ҳ��ˣ��Ұ��������ȥͶ̥����ô�ܽ���ɱ�أ�" << endl;
			system("pause");
			cout << "��: ���ǲ�������������������ûʲô��˵�ģ�������!" << endl;
			system("pause");
			


		}
		else cout << "��Ҫ��֮ǰ���ｻ̸�������Ѿ���̸���ˡ�" << endl << endl;
		break;
	}

	case 4: {
		if (player.getStory() == 4) {
			cout << "����е��Ʋʱ�Ϧ��Ⱦ���˺�ɫ��������һƬ���ţ�Ψ��ż��������������˻��������������������������һ��Ũ�ص�Ѫ��ζ�����˲�������η��" << endl;
			system("pause");
			cout << "��:������ǿɶ��������" << endl;
			system("pause");
			cout << "����������������ȸɽׯ����ׯ��˵�����ǲ�һ����" << endl;
			system("pause");
			
			cout << "��: ʲô�����Ѿ�֪�����ҵ���ݣ�ʲôʱ��" << endl;
			system("pause");
			cout << "��������ׯ�������Ʋ����ˣ����������㱾�¶�û�еĻ�������ôһͳ�����أ�" << endl;
			system("pause");
			cout << "��: �Ǻǣ�������С�����ˣ���ΪʲôҪ��������" << endl;
			system("pause");
			cout << "������ �����������Թ�������δ��ֹϢ�����ģ����ӣ����������Ʈҡ������ͳһ���Խ������޾��Ķ�����" << endl;
			system("pause");
			cout << "�㣺�ߣ�˵�ı����ĺ���������ô������Щ����ɱ�������أ�" << endl;
			system("pause");
			cout << "������Ŷ���ѵ���ׯ����֪���ɴ����߲���С������������Щ�����������ˡ�" << endl;
			system("pause");
			cout << "�㣺�Ǻǣ����컬�ࡣ" << endl;
			system("pause");
			cout << "�������ҿ���ׯ��Ҳ�Ǹ������ˣ�����������ҵĿ�ȸ�ᣬ�������ܿ����������ҵ����¡���ô������ׯ����" << endl;
			system("pause");
			cout << "�㣺������λ�������ȥ������·�Ϻú����ɣ����У�" << endl;
			system("pause");
			cout << "������������ׯ�����治ʶȤ��" << endl;
			system("pause");
	


		}
		else cout << "��Ҫ��֮ǰ���ｻ̸�������Ѿ���̸���ˡ�" << endl << endl;
		break;
	}
	case 9: {
		if (player.getStory() == 5) {
			cout << "�޸�˹��ʲô�ˣ������ô������ȣ�" << endl;
			system("pause");
			cout << "��: �ٺ٣���˵��ֻ�Ǹ����͵������" << endl;
			system("pause");
			cout << "�޸�˹���Ǻǣ������û�н�������ֻ�б�صĲк�" << endl;
			system("pause");
			cout << "��: ��к��ҿɲ�Ҫ�����������ı������׽�����£�" << endl;
			system("pause");
			cout << "�޸�˹����Ŀ����������Ϳ�����û���������ˣ�" << endl;
			system("pause");
			
		}
		else cout << "��Ҫ��֮ǰ���ｻ̸�������Ѿ���̸���ˡ�" << endl << endl;
		break;
	}
	default:cout << "û��������" << endl << endl; break;
	}
	return player;
}

int Npc::getGoodsNum()
{
	return goodNum;
}

int Npc::getGoodsId() {
	return goodId;
}

int Npc::getMoney() {
	return money;
}
//��������δ�ں����ļ��￴�����ò���
bool Npc::isChatted(int whichNpc) {
	if (whichNpc == 1)
		return true;
	if (whichNpc == 2)
		return true;
	if (whichNpc == 3)
		return true;
	if (whichNpc == 4)
		return true;
	if (whichNpc == 5)
		return true;
	if (whichNpc == 6)
		return true;
	if (whichNpc == 7)
		return false;
}
