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

float enemyChar::attackChar(gameChar &target){
    float result = gameChar::attackChar(target);
    return result;
}
