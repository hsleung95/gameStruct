//
//  mainChar.cpp
//  gameStruct
//
//  Created by Wilson Leung on 25/7/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//

#include "mainChar.hpp"
#include <iostream>

mainChar::mainChar(){
    exp = 0;
    expCap = setExpCap(1);
}

mainChar::mainChar(string name, float hpVal,float mpVal,float att,float def,float intl) : gameChar(name,hpVal,mpVal,att,def, intl){
    exp = 0;
    expCap = setExpCap(lv);		// expCap = (x^2)/2 + 125x
	for(int i=0;i<wearingNum;i++){
		wearing[i] = equipment();
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
	if(lv < eq.getLvCap()){
		cout << "Not enough lv." << endl;
		return false;
	}
	
	for(int i=0;i<ownedNum;i++){
		if(owned[i]==eq){	//check equipment is in players owning
			for(int j=0;j<wearingNum;j++){
				if(eq.getEqType() == wearing[j].getEqType()){
					equipment temp = wearing[j];	//swap between the equiped one and the one in bag
					wearing[j].unEquipChar(*this);
					owned[i].equipChar(*this);
					wearing[j] = owned[i];
					owned[i] = temp;
					return true;
				}
			}
		}
	}
	cout << "Equipment not exist in bag." << endl;
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
	for(int i=0;i<ownedNum;i++){
		if(owned[i] == eq){
			owned[i] = equipment();
			return true;
		}
	}
	cout << "cannot find equipment." << endl;
	return false;
}
