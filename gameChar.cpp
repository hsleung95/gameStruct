//
//  gameChar.cpp
//  gameStruct
//
//  Created by Wilson Leung on 20/7/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//

#include "gameChar.hpp"
#include <iostream>
#include <stdlib.h>
string gameChar::attrStr[5] = {"hp","mp","attack","defense","intelligence"};

gameChar::gameChar(){
    currentHP=maxHP=currentMP=maxMP=attack=attVal=defense=defVal=intelligence=intVal=attMod=defMod=intMod=0;
    lv = 1;
	decreasedAttRound=decreasedDefRound=decreasedIntRound=defenseRound = -1;
	decreasedAtt=decreasedDef=decreasedInt=false;
}

gameChar::gameChar(string name, float hpVal,float mpVal,float att,float def, float inti){
	defenseRound = -1;
    maxHP = currentHP = hpVal;
    maxMP = currentMP = mpVal;
    attack=attVal=att;
    defense=defVal=def;
	intelligence=intVal=inti;
    charName = name;
	lv = 1;
	attMod=defMod=intMod=0;
}

float gameChar::getMaxHP(){return maxHP;}
float gameChar::getMaxMP(){return maxMP;}
float gameChar::getCurrentHP(){return currentHP;}
float gameChar::getCurrentMP(){return currentMP;}
float gameChar::getAttack(){return attack;}
float gameChar::getDefense(){return defense;}
float gameChar::getIntelligence(){return intelligence;}
float gameChar::getAttVal(){return attVal;}
float gameChar::getDefVal(){return defVal;}
float gameChar::getIntVal(){return intVal;}
float gameChar::getAttMod(){return attMod;}
float gameChar::getDefMod(){return defMod;}
float gameChar::getIntMod(){return intMod;}
string gameChar::getName(){return charName;}
string gameChar::getType(){return "gameChar";}
int gameChar::getLV(){ return lv; }

int gameChar::getRandCount(){		//counter for monster generated
    static int randCount;
    return (randCount++);
}
void gameChar::setMaxHP(float val){maxHP = val;}
void gameChar::setCurrentHP(float val){currentHP = val;}
void gameChar::setMaxMP(float val){maxMP = val;}
void gameChar::setCurrentMP(float val){currentMP = val;}
void gameChar::setAttack(float val){
	attack=val;
	attVal = attack;
}
void gameChar::setDefense(float val){
	defense=val;
	defVal = defense;
}
void gameChar::setIntelligence(float val){
	intelligence=val;
	intVal = intelligence;
}
void gameChar::setAttVal(float val){attVal=val;}
void gameChar::setDefVal(float val){defVal=val;}
void gameChar::setIntVal(float val){intVal=val;}
void gameChar::setAttMod(float val){attMod=val;}
void gameChar::setDefMod(float val){defMod=val;}
void gameChar::setIntMod(float val){intMod=val;}
void gameChar::setName(string name){charName=name;}
void gameChar::setChar(string name, float charHP, float charMP, float charAtt,float charDef,float charInt, int charLv){
    charName = name;
    maxHP=charHP;
    maxMP=charMP;
    attack = charAtt;
	attVal = charAtt;
    defense = charDef;
	defVal = charDef;
	intelligence = charInt;
	intVal = charInt;
    currentHP = maxHP;
    currentMP = maxMP;
    lv = charLv;
	attMod = defMod = intMod = 0;
}

 void gameChar::printStat(){
     cout << "name: " << charName;
	 cout << " lv: " << lv;
	 cout << " HP: " << (currentHP <= 0? 0 : currentHP) << "/" << maxHP;
	 cout << " MP: " << (currentMP <= 0? 0 : currentMP) << "/" << maxMP;
     cout << " Attack: " << attVal + attMod;
     cout << " Defense: " << defVal + defMod;
	 cout << " Intelligence: " << intVal + intMod;
}

float randValWithLV(int min, int max,int lv){	//function to rand stat
    srand((int)time(NULL) * (int)time(NULL));
	for(int i=0;i<10;i++) rand();
    return (min * lv) + rand() %  (max * lv);
}

void gameChar::randChar(int charLv){	//set char stat with random value
    if(charLv <= 0) charLv = 1;
	lv = charLv;
    maxHP= randValWithLV(10, 20, lv);   //val = min + rand  % max
    maxMP= randValWithLV(5, 50, lv);
    attack=randValWithLV(5, 10, lv);
	attVal = attack;
	attMod = 0;
    defense =randValWithLV(5, 10, lv);
	defVal = defense;
	defMod = 0;
	intelligence = randValWithLV(5, 10, lv);
	intVal = intelligence;
	intMod = 0;
    currentHP = maxHP;
    currentMP = maxMP;
}

float gameChar::attackChar(gameChar target){	//attack function
    float ownAttack = getAttVal() + attMod;
    float targetDefense = target.getDefVal() + target.getDefMod();
    float damage = (ownAttack  - targetDefense) * 1.5 ;
    if(damage<=0) damage = 1;
    return damage;
}

bool gameChar::defenseAction(int currentRound){
	defenseRound = currentRound;
	defVal = getDefense() * 2;
	defensed = true;
	return true;
}

bool gameChar::stopDefense(){
	defVal = getDefense();
	defensed = false;
	return true;
}

//function that set char's modifier, used by other char
void gameChar::decreaseAttr(int attribute, float effectVal, int currentRound){
switch (attribute) {
	case 2:{
		attMod = effectVal;
		decreasedAttRound = currentRound;
		decreasedAtt = true;
		break;
	}
	case 3:{
		defMod = effectVal;
		decreasedDefRound = currentRound;
		decreasedDef = true;
		break;
	}
	case 4:{
		intMod = effectVal;
		decreasedIntRound = currentRound;
		decreasedInt = true;
		break;
	}
	default:
		break;
	}
}

void gameChar::checkRoundStat(int currentRound){	//reset all modifier after 7 moves(including enemy and myself)
	if(decreasedAtt){
		if(decreasedAttRound + 7 == currentRound){
			attMod = 0;
			decreasedAtt = false;
		}
	}
	if(decreasedDef){
		if(decreasedDefRound + 7 == currentRound){
			defMod = 0;
			decreasedDef = false;
		}
	}
	if(decreasedInt){
		if(decreasedIntRound + 7 == currentRound){
			intMod = 0;
			decreasedInt = false;
		}
	}
}
