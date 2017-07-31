//
//  equipment.cpp
//  gameStruct
//
//  Created by Wilson Leung on 27/7/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//

#include "equipment.hpp"
#include <iostream>

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

void equipment::printEq(){
	cout << "Equipment detail:" << endl;
	cout << "Equip at: " << eqType << endl;
	cout << "Name: " << eqName << endl;
	cout << "Description" << description << endl;
	cout << "+" << effectingVal << attribute << endl;
	cout << "can be equiped after lv" << lv << endl;
}

void equipment::equipChar(gameChar &equiped){
	switch (attribute) {
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
}

void equipment::unEquipChar(gameChar &equiped){
	switch (attribute) {
  case hp:{
	  float maxHP = equiped.getMaxHP();
	  float currentHP = equiped.getCurrentHP();
	  equiped.setMaxHP(maxHP - effectingVal);
	  equiped.setCurrentHP(currentHP - effectingVal);
	  break;
  }
  case mp:{
	  float maxMP = equiped.getMaxMP();
	  float currentMP = equiped.getCurrentMP();
	  equiped.setMaxHP(maxMP - effectingVal);
	  equiped.setCurrentHP(currentMP - effectingVal);
	  break;
  }
  case attack:{
	  float attack = equiped.getAttack();
	  equiped.setAttack(attack - effectingVal);
	  break;
  }
  case defense:{
	  float defense = equiped.getDefense();
	  equiped.setDefense(defense - effectingVal);
  }
  case intelligence:{
	  float intelligence = equiped.getIntelligence();
	  equiped.setIntelligence(intelligence - effectingVal);
  }
			
  default:
			break;
	}
}

bool equipment::isNull(){
	if(eqName=="" && description == "" && effectingVal == 0 && lv ==1) return true;
	
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
