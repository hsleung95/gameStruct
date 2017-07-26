//
//  enemyChar.cpp
//  gameStruct
//
//  Created by Wilson Leung on 25/7/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//

#include "enemyChar.hpp"
#include <iostream>

enemyChar::enemyChar(){
    expContain = maxHP * 0.5 + maxMP * 0.1 + attack * 4 + defense * 4;
}

float enemyChar::getExpContain(){ return expContain; }
void enemyChar::setExpContain(){ expContain = maxHP * 0.5 + maxMP * 0.1 + attack * 4 + defense * 4; }

void enemyChar::printStat(){
	std::cout << "Enemy character value: " << endl;
    gameChar::printStat();
    std::cout << " exp: " << expContain << endl << endl;
}
