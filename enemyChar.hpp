//
//  enemyChar.hpp
//  gameStruct
//
//  Created by Wilson Leung on 25/7/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//

#ifndef enemyChar_hpp
#define enemyChar_hpp
#pragma once

#include <stdio.h>
#include "gameChar.hpp"
#include "equipment.hpp"
#include "skill.hpp"

class enemyChar: public gameChar{
protected:
    float expContain;
	equipment eq;
	skill skillArr[4];
    
public:
    enemyChar();
    float getExpContain();
    void setExpContain();
	equipment getEquipment();
	void printEq();
	virtual string getType();
	void randChar(string enemyName, int lv);
    
    virtual void printStat();
};
#endif /* enemyChar_hpp */
