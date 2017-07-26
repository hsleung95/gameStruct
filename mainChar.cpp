//
//  mainChar.cpp
//  gameStruct
//
//  Created by Wilson Leung on 25/7/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//

#include "mainChar.hpp"

mainChar::mainChar(){
    exp = 0;
    expCap = lv * lv * 125;
}

mainChar::mainChar(string name, float hpVal,float mpVal,float att,float def) : gameChar(name,hpVal,mpVal,att,def){
    exp = 0;
    expCap = lv * lv * 125;
}

bool mainChar::addExp(float expAmount){
    exp += expAmount;
    if(exp >= expCap){
        lvUp();
        return true;
    }
    return false;
}

void mainChar::lvUp(){
    maxHP += 100;
    maxMP += 50;
    attack += 10;
    defense += 10;
    expCap += lv * lv * 125;
}
