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
#include <iostream>

class skill{
public:
	const static int skillTypeNum = 3;
	const static string skillTypeArr[skillTypeNum];

protected:
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
	void setTargetParam(gameChar &target, int field, int effectVal);
	virtual string getSkillClass();
	virtual float cast(gameChar &source, gameChar &target, int currentRound);
	virtual void printEffect(gameChar &source, gameChar &target, float value);
};

// magic class: use mana to cast magic damage based on intelligence
class magic : public skill{
public:
	magic();
	magic(string name, float skillCost, float skillVal, char skillKey, string skillDes);
	string getSkillClass() override;
	float cast(gameChar &source, gameChar &target, int currentRound) override;
	void printEffect(gameChar &source, gameChar &target, float value) override;
};

// physical skill class: cost 0, but may miss on target
class physical_skill : public skill{
public:
	physical_skill();
	physical_skill(string name, float skillCost, float skillVal, char skillKey, string skillDes);
	string getSkillClass() override;
	float cast(gameChar &source, gameChar &target, int currentRound) override;
	void printEffect(gameChar &source, gameChar &target, float value) override;
};

class restore_health : public skill{
public:
	restore_health();
	restore_health(string name, float skillCost, float skillVal, char skillKey, string skillDes);
	string getSkillClass() override;
	float cast(gameChar &source, gameChar &target, int currentRound) override;
	void printEffect(gameChar &source, gameChar &target, float value) override;
};

class attribute_modifier : public skill{
	int field;
public:
	attribute_modifier();
	attribute_modifier(string name, float skillCost, float skillVal, char skillKey, string skillDes, int skillField);
	string getSkillClass() override;
	float cast(gameChar &source, gameChar &target, int currentRound) override;
	void printEffect(gameChar &source, gameChar &target, float value) override;
};
/************************ code for skillNode(skill tree node) *****************/

class skillNode{
	skill* containSkill;		// use pointer for derived skill classes
	int unlockLv;
	
public:
	skillNode();
	skillNode(int lv, skill* in);
	
	int getUnlockLv();
	skill* getSkill();
};
#endif /* skill_hpp */
