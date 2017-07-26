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

class enemyChar: public gameChar{
protected:
    float expContain;
    
public:
    enemyChar();
    float getExpContain();
    void setExpContain();
};
#endif /* enemyChar_hpp */
