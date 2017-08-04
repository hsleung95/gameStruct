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
#include <string>
#include "gameChar.hpp"
#include "equipment.hpp"

class skill{
protected:
	float cost;
	float effectVal;
	
public:
	skill();
	virtual string skillName();
	virtual float cast(gameChar &source, gameChar &target);
	float castSkill(gameChar &source, gameChar &target, float val);
};

class restore_health : public skill{
public:
	restore_health();
	string skillName();
	float cast(gameChar &source, gameChar &target);

};

class magic_attack : public skill{
public:
	magic_attack();
	string skillName();
	float cast(gameChar &source, gameChar & target);
};

#endif /* skill_hpp */
