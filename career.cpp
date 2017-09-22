//
//  career.cpp
//  gameStruct
//
//  Created by Wilson Leung on 9/8/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//

#include "career.hpp"

/*-- skill list for all classes--*/
//skill(string name, float skillCost, float skillVal, char skillKey, string skillDes)
//attribute_modifier(string name, float skillCost, float skillVal, char skillKey, string skillDes, int skillField)
//skill fields are 2:attMod, 3:defMod, 4:intMod

skill* restoration = new restore_health("restore health",6,2,'r',"Restore health based on intelligence");	//root skill of all class

skill* doubleAttack = new physical_skill("double attack", 5, 2, 'd', "attack dealing double damage");
skill* trippleAttack = new physical_skill("tripple attack", 10, 3, 't', "attack dealing tripple damage");

skill* piercing_ball = new magic("piercing ball",10,2,'m',"Damaging enemy using magic");

skill* heavyAttack = new physical_skill("heavy attack", 5, 4, 'h', "heavy attack dealing a lot of damage");

skill* decreaseDef = new attribute_modifier("decrease defense", 10, -10,'d', "decrease enemy defense",3);
/* ------   career function -------- */

career::career(){}
career::career(string name, float hpVal,float mpVal,float att,float def,float intl) : mainChar(name,hpVal,mpVal,att,def,intl){
	skillNode first = skillNode(1, restoration);
	skillTree.push_back(first);
}

bool career::learnSkill(){
	if(!skillTree.empty()){
		skillNode first = *skillTree.begin();
		if(lv >= first.getUnlockLv()){
			skill* learning = first.getSkill();
			skillList.push_back(learning);
			skillTree.pop_front();
			learnSkill();
			return true;
		}
	}
	return false;
}

string career::getCareer(){return "career";}

bool career::addExp(float expAmount){
	if(mainChar::addExp(expAmount)){
		lvUp();
		return true;
	}
	return false;
}

bool career::lvUp(){
	return true;
}

bool adventurer::addExp(float expAmount){
	if(career::addExp(expAmount)){
		return true;
	}
	return false;
}

void career::generateEq(){}

/* ----------------   adventurer function ------------------ */

adventurer::adventurer(string name, float hpVal,float mpVal,float att,float def,float intl) : career(name,hpVal,mpVal,att,def,intl){
	generateEq();
	skillTree.push_back(skillNode(1, doubleAttack));
	skillTree.push_back(skillNode(1, trippleAttack));
	skillTree.push_back(skillNode(1, piercing_ball));
	cout << learnSkill();
}

string adventurer::getCareer(){return "adventurer";}
bool adventurer::lvUp(){
	lv += 1;
	expCap += setExpCap(lv);
	maxHP += 10;
	currentHP += 10;
	maxMP +=5;
	currentMP += 5;
	attack += 3;
	defense += 3;
	intelligence += 3;
	expCap -= 50*lv*lv;
	if(expCap < exp){
		expCap= exp + 100;
	}
	learnSkill();
	return true;
}
void adventurer::generateEq(){
	srand((int)time(NULL));		//set random seed as time
	for(int i=0;i<wearingNum;i++){		//for each wearing places in character
		enum equipment::eqType eqtype = static_cast<enum equipment::eqType>(i);		//get type of the place
		enum equipment::attribute attr = static_cast<enum equipment::attribute>(rand()%attrNum);	//random attribute(hp/mp/att/def/intl)
		pair<equipment::attribute, float> attrPair[1];
		attrPair[0] = pair<equipment::attribute, float>(attr,5);
		equipment temp = equipment(("adventurer " + equipment::eqTypeStr[i]),*this, "First equipments of player",lv,eqtype,1,attrPair);		//create new equipment
		changeEquipment(temp);		//equip the new equipment to character
	}
	
	for(int i=0;i<ownedNum;i++){	//set owned equipment as empty equipment
		owned[i] = equipment();
	}
}

/* ----------------   magician function ------------------ */

magician::magician(string name, float hpVal,float mpVal,float att,float def,float intl) : career(name,hpVal,mpVal,att,def,intl){
	generateEq();
	skillTree.push_back(skillNode(1, piercing_ball));
	skillTree.push_back(skillNode(1, decreaseDef));
	learnSkill();
}

string magician::getCareer(){return "magician";}

bool magician::addExp(float expAmount){
	if(career::addExp(expAmount)){
		return true;
	}
	return false;
}
bool magician::lvUp(){
	lv += 1;
	expCap += setExpCap(lv);
	maxHP += 5;
	currentHP += 5;
	maxMP +=10;
	maxMP += 10;
	attack += 2;
	defense += 2;
	intelligence += 5;
	learnSkill();
	return true;
}

void magician::generateEq(){
	srand((int)time(NULL));		//set random seed as time
	for(int i=0;i<wearingNum;i++){		//for each wearing places in character
		int randAttrNum = rand()%attrNum;
		randAttrNum = (randAttrNum < 2 ? 1 : 4);
		enum equipment::eqType eqtype = static_cast<enum equipment::eqType>(i);		//get type of the place
		enum equipment::attribute attr = static_cast<enum equipment::attribute>(randAttrNum);	//random attribute(hp/mp/att/def/intl)
		pair<equipment::attribute, float> attrPair[1];
		attrPair[0] = pair<equipment::attribute, float>(attr,5);
		equipment temp = equipment(("magician " + equipment::eqTypeStr[i]),*this, "First equipments of player",lv,eqtype,1,attrPair);		//create new equipment

		changeEquipment(temp);		//equip the new equipment to character
	}
	
	for(int i=0;i<ownedNum;i++){	//set owned equipment as empty equipment
		owned[i] = equipment();
	}
}
/* ----------------   fighter function ------------------ */

fighter::fighter(string name, float hpVal,float mpVal,float att,float def,float intl) : career(name,hpVal,mpVal,att,def,intl){
	generateEq();
	skillTree.push_back(skillNode(1, heavyAttack));
	learnSkill();
}

bool fighter::addExp(float expAmount){
	if(career::addExp(expAmount)){
		return true;
	}
	return false;
}
string fighter::getCareer(){return "fighter";}
bool fighter::lvUp(){
	lv += 1;
	expCap += setExpCap(lv);
	maxHP += 15;
	currentHP += 15;
	maxMP +=5 ;
	currentMP += 5;
	attack += 5;
	defense += 5;
	intelligence += 1;
	learnSkill();
	return true;
}

void fighter::generateEq(){
	srand((int)time(NULL));		//set random seed as time
	for(int i=0;i<wearingNum;i++){		//for each wearing places in character
		int randAttrNum = rand()%attrNum;
		if(randAttrNum == 1){randAttrNum = 0;}
		else if(randAttrNum == 4){randAttrNum = 2;}
		enum equipment::eqType eqtype = static_cast<enum equipment::eqType>(i);		//get type of the place
		enum equipment::attribute attr = static_cast<enum equipment::attribute>(randAttrNum);	//random attribute(hp/mp/att/def/intl)
		pair<equipment::attribute, float> attrPair[1];
		attrPair[0] = pair<equipment::attribute, float>(attr,5);
		equipment temp = equipment(("fighter " + equipment::eqTypeStr[i]),*this, "First equipments of player",lv,eqtype,1,attrPair);		//create new equipment
		changeEquipment(temp);		//equip the new equipment to character
	}
	
	for(int i=0;i<ownedNum;i++){	//set owned equipment as empty equipment
		owned[i] = equipment();
	}
}
