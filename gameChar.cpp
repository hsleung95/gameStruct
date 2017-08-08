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
    currentHP=maxHP=currentMP=maxMP=attack=defense=intelligence=0;
    lv = 1;
}

gameChar::gameChar(string name, float hpVal,float mpVal,float att,float def, float inti){
    maxHP = hpVal;
    maxMP = mpVal;
    attack=att;
    defense=def;
	intelligence=inti;
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
void gameChar::setName(string name){charName=name;}
void gameChar::setChar(string name, float charHP, float charMP, float charAtt,float charDef,float charInt, int charLv){
    charName = name;
    maxHP=charHP;
    maxMP=charMP;
    attack = charAtt;
    defense = charDef;
	intelligence = charInt;
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
    defense =randValWithLV(5, 10, lv);
	intelligence = randValWithLV(5, 10, lv);
    currentHP = maxHP;
    currentMP = maxMP;
}

float gameChar::attackChar(gameChar target){
    float ownAttack = getAttack();
    float targetDefense = target.getDefense();
    float damage = (ownAttack  - targetDefense) * 1.5 ;
    if(damage<=0) damage = 1;
    return damage;
}
