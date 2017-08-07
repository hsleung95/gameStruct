//
//  equipment.cpp
//  gameStruct
//
//  Created by Wilson Leung on 27/7/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//

#include "equipment.hpp"
#include <iostream>
#include <string>
string equipment::eqTypeStr[8] = {"head","shoulders","arms","body","legs","boots","leftHand","rightHand"};

equipment::equipment(){
	eqName = "";
	description = "";
	effectingVal = 0;
	lv = 1;
}

equipment::equipment(string name, gameChar ownedBy, string eqDescription, int lvCap, float effectVal, enum eqType equipType, enum attribute attr){
	eqType = equipType;
	attribute = attr;
	eqName = name;
	owner = ownedBy;
	description = eqDescription;
	effectingVal = effectVal;
	lv = lvCap;
}

enum equipment::eqType equipment::getEqType(){ return eqType;}
enum equipment::attribute equipment::getAttribute(){ return attribute;}
string equipment::getEqName(){return eqName;}
gameChar equipment::getOwner(){return owner;}
string equipment::getDescription(){return description;}
float equipment::getEqVal(){return effectingVal;}
int equipment::getLvCap(){return lv;}

bool equipment::setOwner(gameChar ch){
	owner = ch;
	return true;
}

void equipment::printEq(){
	cout << "Equipment Type: " << equipment::eqTypeStr[eqType] << endl;
	cout << "Name: " << eqName << endl;
	cout << "Description: " << description << endl;
	cout << "+" << effectingVal  << " " << gameChar::attrStr[(int)attribute] << endl;
	cout << "can be equiped after lv" << lv << endl;
}

bool equipment::equipChar(gameChar &equiped){
  switch (this->attribute) {
	case 0:{
		equiped.setMaxHP(equiped.getMaxHP()+effectingVal);
		equiped.setCurrentHP(equiped.getCurrentHP()+effectingVal);
		return true;
		break;
	}
	case 1:{
		equiped.setMaxMP(equiped.getMaxMP()+effectingVal);
		equiped.setCurrentMP(equiped.getCurrentMP()+effectingVal);
		return true;
		break;
	}
	case 2:{
		equiped.setAttack(equiped.getAttack()+effectingVal);
		return true;
		break;
	}
	case 3:{
		equiped.setDefense(equiped.getDefense()+effectingVal);
		return true;
		break;
	}
	case 4:{
		equiped.setIntelligence(equiped.getIntelligence()+effectingVal);
		return true;
		break;
	}
			
	default:{
		return false;
		break;
	}
  }
  return false;
}

bool equipment::unEquipChar(gameChar &equiped){
	switch (this->attribute) {
		case 0:{
			equiped.setMaxHP(equiped.getMaxHP() - effectingVal);
			equiped.setCurrentHP(equiped.getCurrentHP() - effectingVal);
			return true;
			break;
		}
		case 1:{
			equiped.setMaxMP(equiped.getMaxMP() - effectingVal);
			equiped.setCurrentMP(equiped.getCurrentMP() - effectingVal);
			return true;
			break;
		}
		case 2:{
			equiped.setAttack(equiped.getAttack() - effectingVal);
			return true;
			break;
		}
		case 3:{
			equiped.setDefense(equiped.getDefense() - effectingVal);
			return true;
			break;
		}
		case 4:{
			equiped.setIntelligence(equiped.getIntelligence() - effectingVal);
			return true;
			break;
		}
			
		default:{
			return false;
			break;
		}
	}
	return false;
}

bool equipment::isNull(){
	if(eqName=="" && description == "" && effectingVal == 0 && lv == 1) return true;
	return false;
}

bool equipment::operator==(equipment &eq){
	return (this == &eq ? true : false);
}
