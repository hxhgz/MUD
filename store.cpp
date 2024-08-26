#include <iostream>
#include <string>
#include <vector>
#include<iomanip>
#include "store.h"
using namespace std;
Store::Store() {
	int i = 0;
	while (i <= 20) {
		stores.insert(pair<int, int>(i, 999));
		i++;
	}
}
Store::~Store() {

};
void Store::showStore() {
	cout <<left<< "��ƷID" << setw(20) << "��Ʒ����" << setw(70) << "�۸�" << setw(15) << endl;
	map<int, int>:: iterator iter;
	int i = 0;
	for (iter = stores.begin(); iter != stores.end(); iter++)
	{
		cout << left << setw(2) << i << setw(10) << goods[iter->first].getName() << "   "
			<< setw(50) << goods[iter->first].getDesc() << "   "
			<< goods[iter->first].getPriceBuy() << endl;

		i++;//��Ʒ���
	}

}
Role Store:: Buywares(Role player) {
	int goodsId, goodsNum;
	bool ifcontinue = false;
	while (!ifcontinue) {
		cout << "������Ҫ�������ƷID�ţ�����21�˳���" << endl;
		cin >> goodsId;

		if (goodsId == 21) {
			return player;
		}
		else if (goodsId >= 0 && goodsId < 21) {
			ifcontinue = true; // ID��Ч���˳�ѭ��  
		}
		else {
			cout << "��Ч����ƷID������������" <<endl;
		}
	}	cout << "������Ҫ���������(����0�˳�)" << endl;
	cin >> goodsNum;
	if (goodsNum == 0) return player;
	int Price = int( goods[goodsId].getPriceBuy()) * int(goodsNum);
	if (player.getMoney() >= Price)
	{
		player.addGoodsToBag(goodsId, goodsNum);
		player.setMoney(player.getMoney() - Price);
		cout << "����ɹ�" << endl;
		cout << "��� " << goods[goodsId].getName() << goodsNum<<"��";
	}
	else
	{
		cout << "��û���㹻��Ǯ���Ų�����" << endl;
	}
	return player;
}

Role Store::Sellwares(Role player){
	int goodsId, goodsNum;
	bool ifcontinue = false;
	while(!ifcontinue){
	cout << "������Ҫ��������ƷID(����21�˳�)" << endl;
	cin >> goodsId;
	if (goodsId == 21) { return player; }else
		if (goodsId >= 0 && goodsId < 21) {
			ifcontinue = true; // ID��Ч���˳�ѭ��  
		}
		else {
			cout << "��Ч����ƷID������������" << endl;
		}
	cout << "������Ҫ����������(����0�˳�)" << endl;
	cin >> goodsNum;
	if (goodsNum == 0) return player;
	if (player.subGoodsToBag(goodsId, goodsNum)) {
		int Price = int(goods[goodsId].getPriceSell()) * int(goodsNum);

		player.setMoney(player.getMoney() + Price);
		cout << "���۳ɹ�" << endl;
		cout << "��ý�Ǯ:" << Price << endl;
	}
	else {
		cout << "����ʧ�ܣ�" << endl;
	}
	return player;
}