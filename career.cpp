//
//  career.cpp
//  gameStruct
//
//  Created by Wilson Leung on 9/8/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//

#include "career.hpp"
/* ------   career function -------- */
career::career(){}
career::career(string name, float hpVal,float mpVal,float att,float def,float intl) : mainChar(name,hpVal,mpVal,att,def,intl){
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
}

string adventurer::getCareer(){return "adventurer";}
bool adventurer::lvUp(){
	lv += 1;
	expCap += setExpCap(lv);
	maxHP += 10;
	maxMP +=5;
	attack += 3;
	defense += 3;
	intelligence += 1;
	expCap -= 50*lv*lv;
	if(expCap < exp){
		expCap= exp + 100;
	}
	return true;
}
void adventurer::generateEq(){
	srand((int)time(NULL));		//set random seed as time
	for(int i=0;i<wearingNum;i++){		//for each wearing places in character
		enum equipment::eqType eqtype = static_cast<enum equipment::eqType>(i);		//get type of the place
		enum equipment::attribute attr = static_cast<enum equipment::attribute>(rand()%attrNum);	//random attribute(hp/mp/att/def/intl)
		equipment temp = equipment(("adventurer " + equipment::eqTypeStr[i]),*this, "First equipments of player",lv,5,eqtype,attr);		//create new equipment
		changeEquipment(temp);		//equip the new equipment to character
	}
	
	for(int i=0;i<ownedNum;i++){	//set owned equipment as empty equipment
		owned[i] = equipment();
	}
}

/* ----------------   magician function ------------------ */

magician::magician(string name, float hpVal,float mpVal,float att,float def,float intl) : career(name,hpVal,mpVal,att,def,intl){
	generateEq();
	skill* ma = new skill("magic attack",10,-2,'m',"Damage enemy for based on intelligence");
	skillList.push_back(ma);
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
	maxMP +=10;
	attack += 2;
	defense += 2;
	intelligence += 5;
	return true;
}

void magician::generateEq(){
	srand((int)time(NULL));		//set random seed as time
	for(int i=0;i<wearingNum;i++){		//for each wearing places in character
		int randAttrNum = rand()%attrNum;
		randAttrNum = (randAttrNum < 2 ? 1 : 4);
		enum equipment::eqType eqtype = static_cast<enum equipment::eqType>(i);		//get type of the place
		enum equipment::attribute attr = static_cast<enum equipment::attribute>(randAttrNum);	//random attribute(hp/mp/att/def/intl)
		equipment temp = equipment(("adventurer " + equipment::eqTypeStr[i]),*this, "First equipments of player",lv,5,eqtype,attr);		//create new equipment
		changeEquipment(temp);		//equip the new equipment to character
	}
	
	for(int i=0;i<ownedNum;i++){	//set owned equipment as empty equipment
		owned[i] = equipment();
	}
}
/* ----------------   fighter function ------------------ */

fighter::fighter(string name, float hpVal,float mpVal,float att,float def,float intl) : career(name,hpVal,mpVal,att,def,intl){
	generateEq();
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
	maxMP +=5;
	attack += 5;
	defense += 5;
	intelligence += 1;
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
		equipment temp = equipment(("adventurer " + equipment::eqTypeStr[i]),*this, "First equipments of player",lv,5,eqtype,attr);		//create new equipment
		changeEquipment(temp);		//equip the new equipment to character
	}
	
	for(int i=0;i<ownedNum;i++){	//set owned equipment as empty equipment
		owned[i] = equipment();
	}
}
