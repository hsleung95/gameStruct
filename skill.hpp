//
//  skill.hpp
//  gameStruct
//
//  Created by Wilson Leung on 4/8/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//

#ifndef skill_hpp
#define skill_hpp
#pragma once

#include <stdio.h>
#include <math.h>
#include <string>
#include "gameChar.hpp"
#include "equipment.hpp"
#include <iostream>

class skill{
protected:
	int skillLv;
	string skillName;
	float cost;
	float effectVal;
	char key;
	string description;
	
public:
	skill();
	skill(string name, float skillCost, float skillVal, char skillKey, string skillDes);
	char getKey();
	string getSkillName();
	string getDescription();
	float getCost();
	int getSKillLv();
	float cast(gameChar &source, gameChar &target);
	float castSkill(gameChar &source, gameChar &target, float val);
};

class skillNode{
protected:
	int unlockLv;
	skill root;
	skill left;
	skill right;
	
public:
	skillNode();
	void learnSkill(int charLv);
};
#endif /* skill_hpp */
