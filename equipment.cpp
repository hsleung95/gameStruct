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
string equipment::attrStr[5] = {"hp","mp","attack","defense","intelligence"};

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
	cout << "+" << effectingVal  << " " << equipment::attrStr[(int)attribute] << endl;
	cout << "can be equiped after lv" << lv << endl;
}

bool equipment::equipChar(gameChar &equiped){
	switch (this->attribute) {
  case hp:{
	float maxHP = equiped.getMaxHP();
	float currentHP = equiped.getCurrentHP();
	equiped.setMaxHP(maxHP+effectingVal);
	equiped.setCurrentHP(currentHP+effectingVal);
	break;
  }
  case mp:{
	float maxMP = equiped.getMaxMP();
	float currentMP = equiped.getCurrentMP();
	equiped.setMaxHP(maxMP+effectingVal);
	equiped.setCurrentHP(currentMP+effectingVal);
	break;
  }
  case attack:{
	float attack = equiped.getAttack();
	equiped.setAttack(attack+effectingVal);
	break;
  }
  case defense:{
	  float defense = equiped.getDefense();
	  equiped.setDefense(defense+effectingVal);
  }
  case intelligence:{
	  float intelligence = equiped.getIntelligence();
	  equiped.setIntelligence(intelligence+effectingVal);
  }
			
  default:
			break;
	}
	return true;
}

bool equipment::unEquipChar(gameChar &equiped){
	cout << "attribute: " << this->attribute << endl;
	switch (this->attribute) {
  case hp:{
	  cout << "before setting, max/current hp = " << equiped.getMaxHP() << "/" << equiped.getCurrentHP() << endl;
	  equiped.setMaxHP(equiped.getMaxHP() - effectingVal);
	  equiped.setCurrentHP(equiped.getCurrentHP() - effectingVal);
	  cout << "after setting, max/current hp = " << equiped.getMaxHP() << "/" << equiped.getCurrentHP() << endl;
	  return true;
	  break;
  }
  case mp:{
	  cout << "before setting, max/current mp = " << equiped.getMaxMP() << "/" << equiped.getCurrentMP() << endl;
	  equiped.setMaxHP(equiped.getMaxMP() - effectingVal);
	  equiped.setCurrentHP(equiped.getCurrentMP() - effectingVal);
	  cout << "after setting, max/current mp = " << equiped.getMaxMP() << "/" << equiped.getCurrentMP() << endl;
	  return true;
	  break;
  }
  case attack:{
	  cout << "before setting, attack = " << equiped.getAttack() << endl;
	  equiped.setAttack(equiped.getAttack() - effectingVal);
	  cout << "after setting, attack = " << equiped.getAttack() << endl;
	  return true;
	  break;
  }
  case defense:{
	  cout << "before setting, defense = " << equiped.getDefense() << endl;
	  equiped.setDefense(equiped.getDefense() - effectingVal);
	  cout << "after setting, defense = " << equiped.getDefense() << endl;
	  return true;
	  break;
  }
  case intelligence:{
	  equiped.setIntelligence(equiped.getIntelligence() - effectingVal);
	  cout << "decreased " << effectingVal << endl;
	  return true;
	  break;
  }
			
  default:
			return false;
			break;
	}
	return false;
}

bool equipment::isNull(){
	if(eqName=="" && description == "" && effectingVal == 0 && lv == 1) return true;
	return false;
}

bool equipment::operator==(equipment &eq){
	/*
	if(this->getEqType()==eq.getEqType() &&
	   this->getEqName().compare(eq.getEqName())==0 &&
	   this->getEqVal() == eq.getEqVal() &&
	   this->getDescription().compare(eq.getDescription())==0 &&
	   this->getLvCap() == eq.getLvCap()
	   )
	 */
	return (this == &eq ? true : false);
}
