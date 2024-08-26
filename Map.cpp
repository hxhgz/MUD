#include <iostream>
#include"Map.h"

using namespace std;

Map::Map() :npc(0) {
	position = 0;
	dx = 5;
	dy = 2;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 10; j++) {
			pos[i][j] = ' ';
		}
	}
	pos[dx][dy]='*';
}

Map::Map(int p):npc(p) {
	position = p;
	if (p == 0) {
		dx = 4;
		dy = 0;
	}
	if (p == 1) {
		dx = 3;
		dy = 0;
	}
	if (p == 2) {
		dx = 2;
		dy = 0;
	}
	if (p == 3) {
		dx = 1;
		dy = 0;
	}
	if (p == 4) {
		dx = 0;
		dy = 0;
	}
	if (p == 5) {
		dx = 3;
		dy = 1;
	}
	if (p == 6) {
		dx = 2;
		dy = 1;
	}
	if (p == 7) {
		dx = 1;
		dy = 1;
	}
	if (p == 8) {
		dx = 0;
		dy = 1;
	}
	if (p == 9) {
		dx = 2;
		dy = 2;
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			pos[i][j] = ' ';
		}
	}
	pos[dx][dy] = '*';
}

Map::~Map()
{
}

void Map::Store()
{
}


void Map::showMap()
{
	system("cls");
	cout << "�����ͼ:" << endl;
	cout << " _____________________" << endl;
	cout << "|          |          |" << endl;
	cout << "|  ����ԭ  |  ����ɽ  |" << endl;
	cout << "|    " << pos[0][0] << "     |    " << pos[0][1] << "     |" << endl;
	cout << "|__________|__________|" << endl;
	cout << "|          |          |" << endl;
	cout << "|  ���ǵ�  |  ���Ʒ�  |" << endl;
	cout << "|    " << pos[1][0] << "     |    " << pos[1][1] << "     |" << endl;
	cout << "|__________|__________|__________" << endl;
	cout << "|          |          |          |" << endl;
	cout << "|  ���½�  |   �̵�   |  ������  |" << endl;
	cout << "|    " << pos[2][0] << "     |    " << pos[2][1] << "     |    " << pos[2][2] << "     |" << endl;
	cout << "|__________|__________|__________|" << endl;
	cout << "|          |          |" << endl;
	cout << "|  ���³�  |  ������  |" << endl;
	cout << "|    " << pos[3][0] << "     |    " << pos[3][1] << "     |" << endl;
	cout << "|__________|__________|" << endl;
	cout << "|          |" << endl;
	cout << "| ��ȸɽׯ |" << endl;
	cout << "|    " << pos[4][0] << "     |" << endl;
	cout << "|__________|" << endl;
	cout << "�����ڵ�λ��Ϊ" << mapName[position] << endl;
}


void Map::showRoom() {
	if (isThereChat())
		cout << "�����У�" << '\t' << npc.getName() << '\t';
}

void Map::Move(char order)
{
	pos[dx][dy] = ' ';
	switch (order)
	{
	case 'w': {
		if (position == 0 || position == 1 || position == 2 || position == 3 || position == 6 || position == 7 || position == 5) {
			dx--;
			position++;
		}
		else
		{
			cout << "�ƶ�ʧ��" << endl;
		}
		break;
	}
	case 'a': {
		if (position == 5 || position == 6 || position == 7 || position == 8) {
			dy--;
			position-=4;
		}
		else if (position == 9)
		{
			dy--;
			position = 6;
		}
		else
		{
			cout << "�ƶ�ʧ��" << endl;
		}
		break;
	}
	case 's': {
		if (position == 1 || position == 2 || position == 3 || position == 4 || position == 8 || position == 6 || position == 7) {
			dx++;
			position--;
		}
		else
		{
			cout << "�ƶ�ʧ��" << endl;
		}
		break;
	}
	case 'd': {
		if (position == 4 || position == 1 || position == 2 || position == 3) {
			dy++;
			position--;
		}
		else if (position == 6)
		{
			dy++;
			position = 9;
		}
		else
		{
			cout << "�ƶ�ʧ��" << endl;
		}
		break;
	}
	default:
		break;
	}
	pos[dx][dy] = '*';
	npc = Npc(position);		//����npc
	showRoom();
}

bool Map::isThereChat()
{
	if (position == 0 || position == 2 || position == 4 || position == 3 || position == 1 || position == 9)
		return true;
	else return false;
}

bool Map::isThereFight()
{
	if (position == 1 || position == 3 || position == 4 || position == 5 || position == 2 || position == 7 || position == 8 || position == 9)
		return true;
	else return false;
}

int Map::getPosition()
{
	return position;
}

string Map::getNpcName() {
	return npc.getName();
}

void Map::setNpc(Npc newNpc) {
	npc = newNpc;
}

Role Map::chatToNpc(Role player) {
	return npc.chat(player);
}

int Map::getNpcGoodsId() {
	return npc.getGoodsId();
}

int Map::getNpcGoodsNum() {
	return npc.getGoodsNum();
}

string Map::getName()
{
	return mapName[position];
}
