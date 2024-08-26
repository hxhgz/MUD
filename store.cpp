#include <iostream>
#include <string>
#include <vector>
#include<iomanip>
#include "store.h"
using namespace std;
Store::Store() {
	int i = 0;
	while (i <= 26) {
		stores.insert(pair<int, int>(i, 999));
		i++;
	}
}
Store::~Store() {

};
void Store::showStore() {
	cout <<left<< "物品ID" << setw(20) << "物品描述" << setw(70) << "价格" << setw(15) << endl;
	map<int, int>:: iterator iter;
	int i = 0;
	for (iter = stores.begin(); iter != stores.end(); iter++)
	{
		if (iter->first <= 21) {
			cout << left << setw(2) << i << setw(10) << goods[iter->first].getName() << "   "
				<< setw(50) << goods[iter->first].getDesc() << "   "
				<< goods[iter->first].getPriceBuy() << endl;

			i++;//物品序号
		}
	}

}
Role Store:: Buywares(Role player) {
	int goodsId, goodsNum;
	bool ifcontinue = false;
	while (!ifcontinue) {
		cout << "请输入要购买的物品ID号（输入21退出）" << endl;
		cin >> goodsId;

		if (goodsId == 21) {
			return player;
		}
		else if (goodsId >= 0 && goodsId < 21) {
			ifcontinue = true; // ID有效，退出循环  
		}
		else {
			cout << "无效的物品ID，请重新输入" <<endl;
		}
	}	cout << "请输入要购买的数量(输入0退出)" << endl;
	cin >> goodsNum;
	if (goodsNum == 0) return player;
	int Price = int( goods[goodsId].getPriceBuy()) * int(goodsNum);
	if (player.getMoney() >= Price)
	{
		player.addGoodsToBag(goodsId, goodsNum);
		player.setMoney(player.getMoney() - Price);
		cout << "购买成功" << endl;
		cout << "获得 " << goods[goodsId].getName() << goodsNum<<"件";
	}
	else
	{
		cout << "你没有足够的钱，概不赊账" << endl;
		return player;
	}
	return player;
}

Role Store::Sellwares(Role player){
	int goodsId, goodsNum;
	bool ifcontinue = false;
	while(!ifcontinue){
	cout << "请输入要卖出的物品ID(输入27退出)" << endl;
	cin >> goodsId;
	if (goodsId == 27) { return player; }else
		if (goodsId >= 0 && goodsId < 27) {
			ifcontinue = true; // ID有效，退出循环  
		}
		else {
			cout << "无效的物品ID，请重新输入" << endl;
		}
	cout << "请输入要卖出的数量(输入0退出)" << endl;
	cin >> goodsNum;
	if (goodsNum == 0) return player;
	if (player.subGoodsToBag(goodsId, goodsNum)) {
		int Price = int(goods[goodsId].getPriceSell()) * int(goodsNum);

		player.setMoney(player.getMoney() + Price);
		cout << "出售成功" << endl;
		cout << "获得金钱:" << Price << endl;
	}
	else {
		cout << "出售失败！" << endl;
		return player;
	}
	return player;
}
