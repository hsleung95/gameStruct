//
//  mainChar.hpp
//  gameStruct
//
//  Created by Wilson Leung on 25/7/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//

#ifndef mainChar_hpp
#define mainChar_hpp
#pragma once

#include <stdio.h>
#include "gameChar.hpp"

class mainChar: public gameChar{
    float exp;
    float expCap;
    
public:
    mainChar();
    mainChar(string name, float hpVal,float mpVal,float att,float def);
    
    void addExp(float expAmount);
    void lvUp();
    float attackChar(gameChar &target);
};
#endif /* mainChar_hpp */
