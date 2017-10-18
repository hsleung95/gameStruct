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
protected:
	list<skillNode> skillTree;
public:
	career();
	career(string name, float hpVal,float mpVal,float att,float def,float intl);
	bool learnSkill();
	virtual string getCareer();
	virtual bool addExp(float expAmount);
	virtual bool lvUp();
	virtual void generateEq();
};

class adventurer : public career{
public:
	adventurer(string name, float hpVal,float mpVal,float att,float def,float intl);
	string getCareer() override;
	bool addExp(float expAmount) override;
	bool lvUp() override;
	//bool lvUp(int lv) override;
	void generateEq() override;
};

class magician : public career{
public:
	magician(string name, float hpVal,float mpVal,float att,float def,float intl);
	string getCareer() override;
	bool addExp(float expAmount) override;
	bool lvUp() override;
	//bool lvUp(int lv) override;
	void generateEq() override;
};

class fighter : public career{
public:
	fighter(string name, float hpVal,float mpVal,float att,float def,float intl);
	string getCareer() override;
	bool addExp(float expAmount)override;
	bool lvUp() override;
	//bool lvUp(int lv) override;
	void generateEq() override;
	//void learnSkill() override;
};
#endif /* career_hpp */
