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
public:
	const static int skillTypeNum = 3;
	const static string skillTypeArr[skillTypeNum];

protected:
	string skillName;
	float cost;
	float effectVal;
	char key;
	string description;
	int skillType;
	int skillField;
	
public:
	skill();
	skill(string name, float skillCost, float skillVal, char skillKey, string skillDes, int skillType, int skillField);
	char getKey();
	string getSkillName();
	string getDescription();
	float getCost();
	int getSKillLv();
	float cast(gameChar &source, gameChar &target);
};

class skillNode{
protected:
	int unlockLv;
	skill containSkill;
	skillNode* next;
	skillNode* root;
	
public:
	skillNode();
	skillNode(int lv, skill s, skillNode* nextSkill, skillNode* rootSkill);
	~skillNode();
	int getUnlockLv();
	skill getContainSkill();
	skillNode* getNext();
	void destroySkillNode(skillNode* nextSkill);
	void insertSkill(int lv,skill in);
	skill searchSkill(int lv);
};
#endif /* skill_hpp */
