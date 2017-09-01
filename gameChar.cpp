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
    currentHP=maxHP=currentMP=maxMP=attack=attVal=defense=defVal=intelligence=intVal=0;
    lv = 1;
	defenseRound = -1;
}

gameChar::gameChar(string name, float hpVal,float mpVal,float att,float def, float inti){
	defenseRound = -1;
    maxHP = hpVal;
    maxMP = mpVal;
    attack=att;
	attVal=att;
    defense=def;
	defVal=def;
	intelligence=inti;
	intVal=inti;
    charName = name;
    lv = 1;
    currentMP = mpVal;
    currentHP = hpVal;
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
string gameChar::getName(){return charName;}
string gameChar::getType(){return "gameChar";}
int gameChar::getLV(){ return lv; }

int gameChar::getRandCount(){
    static int randCount;
    return (randCount++);
}
void gameChar::setMaxHP(float val){maxHP = val;}
void gameChar::setCurrentHP(float val){currentHP = val;}
void gameChar::setMaxMP(float val){maxMP = val;}
void gameChar::setCurrentMP(float val){currentMP = val;}
void gameChar::setAttack(float val){attack=val;}
void gameChar::setDefense(float val){defense=val;}
void gameChar::setIntelligence(float val){intelligence=val;}
void gameChar::setAttVal(float val){attVal=val;}
void gameChar::setDefVal(float val){defVal=val;}
void gameChar::setIntVal(float val){intVal=val;}
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
}

 void gameChar::printStat(){
     cout << "name: " << charName;
	 cout << " lv: " << lv;
	 cout << " HP: " << (currentHP <= 0? 0 : currentHP) << "/" << maxHP;
	 cout << " MP: " << (currentMP <= 0? 0 : currentMP) << "/" << maxMP;
     cout << " Attack: " << attack;
     cout << " Defense: " << defense;
	 cout << " Intelligence: " << intelligence;
}

float randValWithLV(int min, int max,int lv){
    srand((int)time(NULL) * (int)time(NULL));
	for(int i=0;i<10;i++) rand();
    return (min * lv) + rand() %  (max * lv);
}

void gameChar::randChar(int charLv){
    if(charLv <= 0) charLv = 1;
	lv = charLv;
    maxHP= randValWithLV(10, 20, lv);   //val = min + rand  % max
    maxMP= randValWithLV(5, 50, lv);
    attack=randValWithLV(5, 10, lv);
	attVal = attack;
    defense =randValWithLV(5, 10, lv);
	defVal = defense;
	intelligence = randValWithLV(5, 10, lv);
	intVal = intelligence;
    currentHP = maxHP;
    currentMP = maxMP;
}

float gameChar::attackChar(gameChar target){
    float ownAttack = getAttVal();
    float targetDefense = target.getDefVal();
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
