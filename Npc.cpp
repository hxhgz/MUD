
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
		name = "邓定侯";
		goodId = 0;
		goodNum = 1;
		money = 100;
		break;
	}

	case 1: {
		name = "高立";
		goodId = 9;
		goodNum = 1;
		money = 20;
		break;
	}
	case 2: {
		name = "麻锋";
		goodId = 10;
		goodNum = 1;
		money = 50;
		break;
	}
	case 3: {
		name = "西门玉";
		goodId = 11;
		goodNum = 1;
		money = 100;
		break;
	}
	case 4: {
		name = "青龙";
		goodId = -1;
		goodNum = 0;
		money = 0;
		break;
	}
	case 9: {
		name = "修格斯";
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
			cout << "邓定侯: 凤梧啊，听说你们家有孔雀翎这一绝世武器，可以借你邓叔叔使使嘛？" << endl;
			system("pause");
			cout << "你: 怎么了, 出什么事情了？" << endl;
			system("pause");
			cout << "邓定侯：唉，你知道青龙会吧，最近他们正在筹划着想要一统江湖，南方镖局已经沦陷，我想我们北方镖局也快了呀！" << endl;
			system("pause");
			cout << "你：想不到青龙会这么猖狂啊，可是邓叔叔，孔雀翎太危险了，要不我先去试试水？" << endl;
			system("pause");
			cout << "邓定侯：凤梧啊，这可不是闹着玩呢，要不你还是借你邓叔叔用用吧，放心，我会注意的。" << endl;
			system("pause");
			cout << "你：哎呀，邓叔叔，我又不是小孩子了，就让我去试试呗，难道你还不相信我的实力嘛？" << endl;
			system("pause");
			cout << "邓定侯：那好吧，多留心一点，注意安全啊，我也没什么东西，这把武器和这些盘缠就请收下吧。" << endl;
			system("pause");
			cout << "你：那就多谢邓叔叔了，我走了，拜拜..." << endl;
			system("pause");
			player.setStory(player.getStory() + 1);
			player.addGoodsToBag(getGoodsId(), getGoodsNum());
			cout << endl << "获得物品:" << goods[getGoodsId()].getName() << " * " << getGoodsNum() << endl << endl;

		}
		else cout << "已经交谈过了。" << endl << endl;
		break;
	}
	case 1: {//触发剧情，击败掉落物品应是Enemy里面写
		if (player.getStory() == 1) {
			cout << "高立：你是谁，来萧月城干嘛，不知道这是青龙会的地方吗？" << endl;
			system("pause");
			cout << "你: 我就是混口饭吃的，叫我小武就是了，武功平平的武。" << endl;
			system("pause");
			cout << "高立: 少给我油嘴滑舌，快说你来这干嘛！" << endl;
			system("pause");
			cout << "你: 火气真大，我就是来给你降降火的。" << endl;
			system("pause");
			cout << "高立：废话少说，那我就好好看看你怎么给我降火。" << endl;
			system("pause");
			

		}
		else cout << "需要与之前人物交谈。或者已经交谈过了。" << endl << endl;
		break;
	}
	case 2: {
		if (player.getStory() == 2) {
			
			cout << "麻锋：你就是那个击败高立的小子？" << endl;
			system("pause");
			cout << "你: 真不礼貌，我可是有名字的，叫我小武好咯。" << endl;
			system("pause");
			cout << "麻锋：我管你小五小六的，我只知道你今天不会活着离开这里了！" << endl;
			system("pause");
			cout << "你: 那可说不定哦。" << endl;
			system("pause");
			cout << "麻锋：废话少说，拿命来！" << endl;
			system("pause");

			
		}
		else cout << "需要与之前人物交谈。或者已经交谈过了。" << endl << endl;
		break;
	}
	case 3: {
		if (player.getStory() == 3) {
			cout << "  " << endl;
			system("pause");
			cout << "西门玉：小兄弟，我真小看你了，居然把我的两名大将都击败了。" << endl;
			system("pause");
			cout << "你：嘿嘿，侥幸罢了。" << endl;
			system("pause");
			cout << "西门玉：不过我们与你无冤无仇，你这是为何？" << endl;
			system("pause");
			cout << "你: 无冤无仇？呵呵，你们肆意掠杀那些手无寸铁的平民百姓的时候怎么没有想过他们与你无冤无仇呢！" << endl;
			system("pause");
			cout << "西门玉：哈哈哈，小兄弟，你可真幽默，反正他们也活够了，我帮他们早点去投胎，怎么能叫掠杀呢？" << endl;
			system("pause");
			cout << "你: 真是不可理喻，跟你这种人没什么好说的，受死吧!" << endl;
			system("pause");
			


		}
		else cout << "需要与之前人物交谈。或者已经交谈过了。" << endl << endl;
		break;
	}

	case 4: {
		if (player.getStory() == 4) {
			cout << "天空中的云彩被夕阳染成了红色，四周是一片死寂，唯有偶尔传来的青龙的嘶吼声响破云霄，空气中弥漫着一股浓重的血腥味，让人不禁心生畏惧" << endl;
			system("pause");
			cout << "你:你就是那可恶的青龙？" << endl;
			system("pause");
			cout << "青龙：哈哈哈，孔雀山庄的少庄主说话就是不一样。" << endl;
			system("pause");
			
			cout << "你: 什么，你已经知道了我的身份，什么时候？" << endl;
			system("pause");
			cout << "青龙：少庄主可真瞧不起人，我如果连这点本事都没有的话，还怎么一统江湖呢？" << endl;
			system("pause");
			cout << "你: 呵呵，看来我小瞧你了，你为什么要这样做？" << endl;
			system("pause");
			cout << "青龙： 江湖纷争，自古以来，未有止息，我心，久矣，欲将这风雨飘摇的武林统一，以结束这无尽的斗争。" << endl;
			system("pause");
			cout << "你：哼，说的比做的好听，你怎么解释那些被你杀掉的人呢！" << endl;
			system("pause");
			cout << "青龙：哦？难道少庄主不知道成大事者不拘小节嘛，做大事嘛，有些牺牲很正常了。" << endl;
			system("pause");
			cout << "你：呵呵，油嘴滑舌。" << endl;
			system("pause");
			cout << "青龙：我看少庄主也是个明白人，不如献上你家的孔雀翎，我兴许能考虑让你做我的手下。怎么样，少庄主？" << endl;
			system("pause");
			cout << "你：你的美梦还是留在去地狱的路上好好做吧，看招！" << endl;
			system("pause");
			cout << "青龙：唉，少庄主可真不识趣。" << endl;
			system("pause");
	


		}
		else cout << "需要与之前人物交谈。或者已经交谈过了。" << endl << endl;
		break;
	}
	case 9: {
		if (player.getStory() == 5) {
			cout << "修格斯：什么人，竟敢擅闯升龙谷！" << endl;
			system("pause");
			cout << "你: 嘿嘿，我说我只是个打酱油的你信嘛？" << endl;
			system("pause");
			cout << "修格斯：呵呵，我这可没有酱油卖。只有遍地的残骸" << endl;
			system("pause");
			cout << "你: 这残骸我可不要，不如你把你的宝贝护甲借给我呗？" << endl;
			system("pause");
			cout << "修格斯：想的可真美啊，就看你有没有命来拿了！" << endl;
			system("pause");
			
		}
		else cout << "需要与之前人物交谈。或者已经交谈过了。" << endl << endl;
		break;
	}
	default:cout << "没有这个人物。" << endl << endl; break;
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
//待定，暂未在后续文件里看到引用部分
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
