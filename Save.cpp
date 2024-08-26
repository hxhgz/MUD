#ifndef SAVE_CPP
#define SAVE_CPP

#include "Save.h"
#include<fstream>
#include<iostream>

using namespace std;

void Save::setToFile(Role player) {
	ofstream fileRole("SaveRole.dat", ios_base::binary);
	ofstream fileBag("SaveBag.dat", ios_base::binary);
	ofstream fileSkill("SaveSkill.dat", ios_base::binary);
	if (!fileRole || !fileBag || !fileSkill) {
		cout<<"无法打开保存文件"<<endl;
		cout << "保存失败请检查文件是否存在" << endl;
	}
	else {
		fileRole << player.getName() << ' '
			<< player.getType() << ' '
			<< player.getHealth_max() << ' '
			<< player.getHealth() << ' '
			<< player.getMp() << ' '
			<< player.getAttack() << ' '
			<< player.getDefend() << ' '
			<< player.getMoney() << ' '
			<< player.getMapId() << ' '
			<< player.getStory() << ' ';

		
		fileSkill.write(reinterpret_cast<char*>(&player.getSkill()), sizeof(Skill));
		for (const auto& i : player.getBag().getMapBags()) {
			fileBag << i.first << ' ' << i.second << ' ';
		}
		cout << "保存成功" << endl;
		fileRole.close();
		fileBag.close();
		fileSkill.close();

	}
}
#endif