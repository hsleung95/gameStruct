//
//  enemyChar.cpp
//  gameStruct
//
//  Created by Wilson Leung on 25/7/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//

#include "enemyChar.hpp"
#include <string>
#include <iostream>

enemyChar::enemyChar(){
	srand((int)time(NULL));		//set random seed as time
	enum equipment::eqType eqtype = static_cast<enum equipment::eqType>(rand()%wearingNum);
	enum equipment::attribute attr = static_cast<enum equipment::attribute>(rand()%attrNum);
	expContain = maxHP * 0.5 + maxMP * 0.1 + attack * 4 + defense * 4;
	eq = equipment("random "+equipment::eqTypeStr[eqtype], *this, "random equipment", lv, rand()%(5*lv), eqtype, attr);
}

float enemyChar::getExpContain(){ return expContain; }
void enemyChar::setExpContain(){ expContain = maxHP * 0.5 + maxMP * 0.1 + attack * 4 + defense * 4; }

void enemyChar::printStat(){
	std::cout << "Enemy character value: " << endl;
    gameChar::printStat();
    std::cout << " exp: " << expContain << endl;
	cout << endl;
}

void enemyChar::printEq(){
	eq.printEq();
}

string enemyChar::getType(){ return "enemyChar";}

equipment enemyChar::getEquipment(){return eq;}

void enemyChar::randChar(string enemyName,int lv){
	gameChar::randChar(lv);
	enum equipment::eqType eqtype = static_cast<enum equipment::eqType>(rand()%wearingNum);
	enum equipment::attribute attr = static_cast<enum equipment::attribute>(rand()%5);
	expContain = maxHP * 0.5 + maxMP * 0.1 + attack * 4 + defense * 4;
	eq = equipment("random "+equipment::eqTypeStr[eqtype], *this, "random equipment", lv, lv + rand()%(5*lv), eqtype, attr);
	setName(enemyName);
	setExpContain();
}
