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
}

gameChar::gameChar(string name, float hpVal,float mpVal,float att,float def){
    hp = hpVal;
    mp = mpVal;
    attack=att;
    defense=def;
    charName = name;
}


float gameChar::getHP(){return hp;}
float gameChar::getMP(){return mp;}
float gameChar::getAttack(){return attack;}
float gameChar::getDefense(){return defense;}
string gameChar::getName(){return charName;}
    
void gameChar::setHP(float val){this->hp = val;}
void gameChar::setMP(float val){mp = val;}
void gameChar::setAttack(float val){attack=val;}
void gameChar::setDefense(float val){defense=val;}
void gameChar::setName(string name){charName=name;}
void gameChar::setChar(string name, float charHP, float charMP, float charAtt,float charDef){
    charName = name;
    hp=charHP;
    mp=charMP;
    attack = charAtt;
    defense = charDef;
}

void gameChar::randChar(int lv){
    if(lv <= 0) lv = 1;
    srand(time(NULL));
    hp=rand() % (lv * 100);
    mp=rand() % (lv * 50);
    attack=rand() % (lv * 10);
    defense = rand() % (lv * 10);
}

float gameChar::attackChar(gameChar &target){
    float ownAttack = getAttack();
    float targetDefense = target.getDefense();
    float damage = ownAttack * 1.25 - targetDefense ;
    if(damage<=0) damage = 1;
    float hpVal = target.getHP() - damage;
    target.setHP(hpVal);
    return damage;
}
