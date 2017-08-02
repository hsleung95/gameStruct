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

mainChar::mainChar(){
    exp = 0;
    expCap = setExpCap(1);
	
}

mainChar::mainChar(string name, float hpVal,float mpVal,float att,float def,float intl) : gameChar(name,hpVal,mpVal,att,def, intl){
    exp = 0;
    expCap = setExpCap(lv);		// expCap = (x^2)/2 + 125x
	for(int i=0;i<wearingNum;i++){
		enum equipment::eqType eqtype = static_cast<enum equipment::eqType>(i);
		enum equipment::attribute attr = static_cast<enum equipment::attribute>(rand()%5);
		equipment* temp = new equipment(equipment::eqTypeStr[i],*this, "First equipments of player",lv,5,eqtype,attr);
		changeEquipment(*temp);
	}
	for(int i=0;i<ownedNum;i++){
		owned[i] = equipment();
	}
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
    maxHP += 100;
    maxMP += 50;
    attack += 10;
    defense += 10;
	intelligence += 10;
    expCap += setExpCap(lv);
	return true;
}

float mainChar::setExpCap(int lv){
	return (lv * lv)/2 + (125 * lv);
}

void mainChar::printStat(){
	cout << "Your character value: "<< endl;
    gameChar::printStat();
	std::cout << " LV: " << lv << " Current EXP: " << exp << "/" << expCap << std::endl << endl;
}

string mainChar::getType(){ return "mainChar";}

bool mainChar::changeEquipment(equipment eq){
	if(lv < eq.getLvCap()){		//check if character has the lv to equip item
		cout << "Not enough lv." << endl;
		return false;
	}
	for(int i=0;i<wearingNum;i++){
		if(wearing[i].isNull() || eq.getEqType() == wearing[i].getEqType()){
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

bool mainChar::addEquipment(equipment eq){
	for(int i=0;i<ownedNum;i++){
		if(owned[i].isNull()){
			owned[i] = eq;
			return true;
		}
	}
	cout << "No empty space for new equipment." << endl;
	return false;
}

bool mainChar::dropEquipment(equipment eq){
	for(int i=0; i<wearingNum;i++){
		if(wearing[i] == eq){
			wearing[i] = equipment();
			return true;
		}
	}
	for(int i=0;i<ownedNum;i++){
		if(owned[i] == eq){
			owned[i] = equipment();
			return true;
		}
	}
	cout << "cannot find equipment." << endl;
	return false;
}

equipment* mainChar::getWearingArr(){return wearing;}
equipment* mainChar::getOwnedArr(){return owned;}
