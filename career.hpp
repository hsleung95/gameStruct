//
//  career.hpp
//  gameStruct
//
//  Created by Wilson Leung on 9/8/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//

#ifndef career_hpp
#define career_hpp

#include <stdio.h>
#include <iostream>
#include "mainChar.hpp"

class career : public mainChar{
public:
	career();
	career(string name, float hpVal,float mpVal,float att,float def,float intl);
	virtual bool addExp(float expAmount);
	virtual bool lvUp();
	virtual string getCareer();
};

class adventurer : public career{
public:
	adventurer(string name, float hpVal,float mpVal,float att,float def,float intl);
	virtual bool addExp(float expAmount);
	virtual bool lvUp();
	virtual string getCareer();
};

class magician : public career{
public:
	magician(string name, float hpVal,float mpVal,float att,float def,float intl);
	virtual bool addExp(float expAmount);
	virtual bool lvUp();
	virtual string getCareer();
};

class fighter : public career{
public:
	fighter(string name, float hpVal,float mpVal,float att,float def,float intl);
	virtual bool addExp(float expAmount);
	virtual bool lvUp();
	virtual string getCareer();
};
#endif /* career_hpp */
