//
//  enemyChar.cpp
//  gameStruct
//
//  Created by Wilson Leung on 25/7/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//

#include "enemyChar.hpp"

enemyChar::enemyChar(){
	expContain = maxHP * 0.5 + maxMP * 0.1 + attack * 4 + defense * 4;
	eq = equipment();
	eq.randomEquipment(1, *this);
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
	expContain = maxHP * 0.5 + maxMP * 0.1 + attack * 4 + defense * 4;
	eq.randomEquipment(lv, *this);
	setName(enemyName);
	setExpContain();
}
