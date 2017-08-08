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
	float cost;
	float effectVal;
	char key;
	string description;
	
public:
	skill();
	virtual char getKey();
	virtual string skillName();
	virtual string getDescription();
	virtual float cast(gameChar &source, gameChar &target);
	float getCost();
	float castSkill(gameChar &source, gameChar &target, float val);
};

class restore_health : public skill{
public:
	restore_health();
	char getKey();
	string skillName();
	string getDescription();
	//float getCost();
	float cast(gameChar &source, gameChar &target);

};

class magic_attack : public skill{
public:
	magic_attack();
	char getKey();
	string skillName();
	string getDescription();
	//float getCost();
	float cast(gameChar &source, gameChar & target);
};

#endif /* skill_hpp */
