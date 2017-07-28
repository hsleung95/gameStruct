//
//  equipment.cpp
//  gameStruct
//
//  Created by Wilson Leung on 27/7/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//

#include "equipment.hpp"

equipment::equipment(){
	eqName = "";
	description = "";
	effectingVal = 0;
	lv = 1;
}

equipment::equipment(string name, gameChar ownedBy, string eqDescription, int lvCap, float effectVal, enum eqType equipType){
	eqType = equipType;
	eqName = name;
	owner = ownedBy;
	description = eqDescription;
	effectingVal = effectVal;
	lv = lvCap;
}

enum equipment::eqType equipment::getEqType(){ return eqType;}
string equipment::getEqName(){return eqName;}
gameChar equipment::getOwner(){return owner;}
string equipment::getDescription(){return description;}
float equipment::getEqVal(){return effectingVal;}
int equipment::getLvCap(){return lv;}

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
