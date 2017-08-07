//
//  mainChar.cpp
//  gameStruct
//
//  Created by Wilson Leung on 25/7/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//

#include "mainChar.hpp"
#include "equipment.hpp"
#include <string>
#include <iostream>

float mainChar::setExpCap(int lv){
	return (lv * lv)/2 + (125 * lv);
}

mainChar::mainChar(){
    exp = 0;
    expCap = setExpCap(1);
	
}

bool mainChar::changeEquipment(equipment eq){
	if(lv < eq.getLvCap()){		//check if character has the lv to equip item
		return false;
	}
	for(int i=0;i<wearingNum;i++){
		if(wearing[i].isNull() || eq.getEqType() == wearing[i].getEqType()){	//check if the slot is empty or same type in the slot
			equipment temp = wearing[i];
			wearing[i].unEquipChar(*this);
			eq.equipChar(*this);
			this->wearing[i] = eq;
			addEquipment(temp);
			return true;
		}
	}
	return false;
}

mainChar::mainChar(string name, float hpVal,float mpVal,float att,float def,float intl) : gameChar(name,hpVal,mpVal,att,def, intl){
    exp = 0;
    expCap = setExpCap(lv);		// expCap = (x^2)/2 + 125x
	
	srand((int)time(NULL));		//set random seed as time
	for(int i=0;i<wearingNum;i++){		//for each wearing places in character
		enum equipment::eqType eqtype = static_cast<enum equipment::eqType>(i);		//get type of the place
		enum equipment::attribute attr = static_cast<enum equipment::attribute>(rand()%attrNum);	//random attribute(hp/mp/att/def/intl)
		equipment* temp = new equipment(("Adventurer " + equipment::eqTypeStr[i]),*this, "First equipments of player",lv,5,eqtype,attr);		//create new equipment
		changeEquipment(*temp);		//equip the new equipment to character
	}
	
	for(int i=0;i<ownedNum;i++){	//set owned equipment as empty equipment
		owned[i] = equipment();
	}
	
	skillList.push_back(new restore_health());	//push the two default skill to skill list
	skillList.push_back(new magic_attack());
}

bool mainChar::addExp(float expAmount){
    exp += expAmount;
    if(exp >= expCap){
        lvUp();
        return true;
    }
    return false;
}

bool mainChar::lvUp(){
	lv += 1;
    maxHP += 10;
    maxMP += 5;
    attack += 5;
    defense += 5;
	intelligence += 5;
    expCap += setExpCap(lv);
	return true;
}

void mainChar::printStat(){
	cout << "Your character value: "<< endl;
    gameChar::printStat();
	std::cout << " LV: " << lv << " Current EXP: " << exp << "/" << expCap << std::endl << endl;
}

string mainChar::getType(){ return "mainChar";}

bool mainChar::addEquipment(equipment eq){
	for(int i=0;i<ownedNum;i++){	//loop through owned equipment array, put the equipment into empty slot or cannot add
		if(owned[i].isNull()){
			owned[i] = eq;
			return true;
		}
	}
	return false;
}

bool mainChar::dropEquipment(equipment eq){
	for(int i=0; i<wearingNum;i++){		//check if the equipment is worn
		if(wearing[i] == eq){
			wearing[i] = equipment();
			return true;
		}
	}
	for(int i=0;i<ownedNum;i++){		//check if the equipment is owned
		if(owned[i] == eq){
			owned[i] = equipment();
			return true;
		}
	}
	return false;						//not exist in character, return false
}

equipment* mainChar::getWearingArr(){return wearing;}
equipment* mainChar::getOwnedArr(){return owned;}
list<skill*> mainChar::getSkillList(){return skillList;}

void mainChar::printSkill(){
	for(list<skill*>::iterator it=skillList.begin();it!=skillList.end();it++){
		cout << "skill key: " << (*it)->getKey();
		cout << ", skill name: " << (*it)->skillName();
		cout << ", skill cost: " << (*it)->getCost();
		cout << " , description: " << (*it)->getDescription();
		cout << endl;
	}
}

bool mainChar::checkMagicKey(char userInput){
	for(list<skill*>::iterator it=skillList.begin();it!=skillList.end();it++){
		if(userInput == (*it)->getKey()) return true;		//check if userInput match any skill key in user skill list
	}
	return false;
}

