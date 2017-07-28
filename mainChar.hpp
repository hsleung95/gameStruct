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
#include "equipment.hpp"

class mainChar: public gameChar{
	const static int wearingNum = 8;
	const static int ownedNum = 20;
    float exp;
    float expCap;
	equipment wearing[wearingNum];
	equipment owned[ownedNum];
	
    
public:
    mainChar();
    mainChar(string name, float hpVal,float mpVal,float att,float def,float intl);
    
    bool addExp(float expAmount);
    void lvUp();
	float setExpCap(int lv);

	virtual string getType();
    virtual void printStat();
	
	void changeEquipment(equipment eq);
};
#endif /* mainChar_hpp */
