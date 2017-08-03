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
public:
	const static int wearingNum = 8;
	const static int ownedNum = 10;
	
protected:
    float exp;
    float expCap;
	equipment wearing[wearingNum];
	equipment owned[ownedNum];
	
    
public:
    mainChar();
    mainChar(string name, float hpVal,float mpVal,float att,float def,float intl);
    
    bool addExp(float expAmount);
    bool lvUp();
	float setExpCap(int lv);

	virtual string getType();
    virtual void printStat();
	
	bool changeEquipment(equipment eq);
	bool addEquipment(equipment eq);
	bool dropEquipment(equipment eq);
	
	equipment* getWearingArr();
	equipment* getOwnedArr();
};
#endif /* mainChar_hpp */
