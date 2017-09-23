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
#include <iostream>
#include <utility>
using namespace std;

class equipment{
public:
	enum eqType {head=0, shoulders=1, arms=2, body=3, legs=4, boots=5, leftHand=6, rightHand=7};	//8 types of eq
	enum attribute {attack=0, hp=1, mp=2, defense=3, intelligence=4};	//5 atrributes
	static string eqTypeStr[8];
	
protected:
	eqType eqType;
	string eqName;
	gameChar owner;
	string description;
	pair<attribute, float> attributePair[4];
	int lv;
	int rank;
	
public:
	equipment();
	equipment(enum eqType equipType);
	equipment(string name, gameChar ownedBy, string description, int lvCap, enum eqType equipType, int rank, pair<attribute, float> attrPair[4]);
	
	void setEquipment(string name, gameChar ownedBy, string description, int lvCap, enum eqType equipType, int eqRank, pair<attribute, float> attrPair[4]);
	
	void randomEquipment(int lv, gameChar owner);
	
	enum eqType getEqType();
	string getEqName();
	gameChar getOwner();
	string getDescription();
	enum attribute getAttribute(int index);
	float getEqVal(int index);
	int getLvCap();
	int getRank();
	
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


#endif /* equipment_hpp */

