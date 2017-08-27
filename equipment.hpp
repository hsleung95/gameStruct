//
//  equipment.hpp
//  gameStruct
//
//  Created by Wilson Leung on 27/7/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//


#ifndef equipment_hpp
#define equipment_hpp
#pragma once

#include <stdio.h>
#include "gameChar.hpp"
#include <string>

#endif /* equipment_hpp */

class equipment{
public:
	enum eqType {head=0, shoulders=1, arms=2, body=3, legs=4, boots=5, leftHand=6, rightHand=7};	//8 types of eq
	enum attribute {attack=0, hp=1, mp=2, defense=3, intelligence=4};	//5 atrributes
	static string eqTypeStr[8];
	
protected:
	eqType eqType;
	attribute attribute;
	string eqName;
	gameChar owner;
	string description;
	float effectingVal;
	int lv;
	
public:
	equipment();
	equipment(enum eqType equipType);
	equipment(string name, gameChar ownedBy, string description, int lvCap, float effectVal, enum eqType equipType, enum attribute attribute);
	
	void setEquipment(string name, gameChar ownedBy, string description, int lvCap, float effectVal, enum eqType equipType, enum attribute attribute);
	
	enum eqType getEqType();
	enum attribute getAttribute();
	string getEqName();
	gameChar getOwner();
	string getDescription();
	float getEqVal();
	int getLvCap();
	
	bool setOwner(gameChar ch);
	
	void printEq();
	bool equipChar(gameChar &equiped);
	bool unEquipChar(gameChar &equiped);
	
	bool isNull();
	bool operator==(equipment &eq);
};

// 7 type of equipments

/*
class head : public equipment{};
class shoulders : public equipment{};
class arms : public equipment{};
class body : public equipment{};
class legs : public equipment{};
class boots : public equipment{};
class hand : public equipment{};
*/
