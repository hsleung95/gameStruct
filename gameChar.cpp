//
//  gameChar.cpp
//  gameStruct
//
//  Created by Wilson Leung on 20/7/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//

#include "gameChar.hpp"
#include <stdlib.h>
gameChar::gameChar(){
    hp=mp=attack=defense=0;
    lv = 1;
}

gameChar::gameChar(string name, float hpVal,float mpVal,float att,float def){
    hp = hpVal;
    mp = mpVal;
    attack=att;
    defense=def;
    charName = name;
    lv = 1;
}


float gameChar::getHP(){return hp;}
float gameChar::getMP(){return mp;}
float gameChar::getAttack(){return attack;}
float gameChar::getDefense(){return defense;}
string gameChar::getName(){return charName;}

int gameChar::getRandCount(){
    static int randCount;
    return randCount++;
}
void gameChar::setHP(float val){hp = val;}
void gameChar::setMP(float val){mp = val;}
void gameChar::setAttack(float val){attack=val;}
void gameChar::setDefense(float val){defense=val;}
void gameChar::setName(string name){charName=name;}
void gameChar::setChar(string name, float charHP, float charMP, float charAtt,float charDef, int charLv){
    charName = name;
    hp=charHP;
    mp=charMP;
    attack = charAtt;
    defense = charDef;
    lv = charLv;
}

void gameChar::randChar(int lv){
    if(lv <= 0) lv = 1;
    srand((int)time(NULL));
    hp=rand() % (lv * 100);
    mp=rand() % (lv * 50);
    attack=rand() % (lv * 20);
    defense = rand() % (lv * 20);
}

float gameChar::attackChar(gameChar &target){
    float ownAttack = this->getAttack();
    float targetDefense = target.getDefense();
    float damage = (ownAttack  - targetDefense) * 1.25 ;
    if(damage<=0) damage = 1;
    float hpVal = target.getHP() - damage;
    target.setHP(hpVal);
    return damage;
}
