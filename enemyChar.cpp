//
//  enemyChar.cpp
//  gameStruct
//
//  Created by Wilson Leung on 25/7/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//

#include "enemyChar.hpp"

enemyChar::enemyChar(){
    expContain = maxHP + maxMP + attack + defense;
}

float enemyChar::getExpContain(){ return expContain; }
void enemyChar::setExpContain(){ expContain = maxHP + maxMP + attack + defense; }
