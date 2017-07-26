//
//  gameChar.hpp
//  gameStruct
//
//  Created by Wilson Leung on 20/7/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//

#ifndef gameChar_hpp
#define gameChar_hpp
#pragma once

#include <stdio.h>
#include <string>
using namespace std;

#endif /* gameChar_hpp */
class gameChar{
protected:
    int lv;
    float maxHP, currentHP, maxMP, currentMP, attack, defense;
    string charName;
    
public:
    gameChar();
    gameChar(string name, float hpVal,float mpVal,float att,float def);
    
    float getCurrentHP();
    float getMaxHP();
    float getCurrentMP();
    float getMaxMP();
    float getAttack();
    float getDefense();
    int   getLV();
    string getName();
    static int getRandCount();
    
    void setCurrentHP(float val);
    void setMaxHP(float val);
    void setCurrentMP(float val);
    void setMaxMP(float val);
    void setAttack(float val);
    void setDefense(float val);
    void setName(string name);
    
    virtual void printStat();
    
    void setChar(string name, float charHP, float charMP, float charAtt, float charDef, int lv);
    void randChar(int lv);
    
    float attackChar(gameChar &target);
};
